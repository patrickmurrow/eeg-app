#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <X11/Xlib.h>
#include <signal.h>
#include <fcntl.h>

#include "eeg.h"
#include "drone.h"

#define WHITE 0
#define BLACK 1

#define LANDED 0
#define TAKEOFF 1


#define MODEMDEVICE "/dev/rfcomm0"

extern double *test_stft_correctness(double *);
extern void *packet_process(void *);
void draw_line(int, int, int, int, int);

static Window win;
static Display *dsp;
static GC gc;
unsigned long white;
unsigned long black;
static int on, mark_index;
static long mark[1000];
static double *fftraw, *fft_power;
static FILE *bfp;
static double baseline_eeg[BASELINE_LEN*SAMPLE_RATE];
static double eeg_segment[ARTIFACT_LEN*SAMPLE_RATE];
static int baseline_ready;
static double alpha_baseline[NUM_SAM_BASELINE];
static double beta_baseline[NUM_SAM_BASELINE];
static double theta_baseline[NUM_SAM_BASELINE];
static double power_baseline[NUM_SAM_BASELINE];
static double mean_metric_baseline;
static double vari_metric_baseline;
static double alpha_trial[NUM_SAM_TRIAL];
static double beta_trial[NUM_SAM_TRIAL];
static double theta_trial[NUM_SAM_TRIAL];
static double power_trial[NUM_SAM_TRIAL];
static double mean_metric_trial;
static double vari_metric_trial;
static double metric_trial[NUM_SAM_TRIAL], raw_metric_trial[NUM_SAM_TRIAL];
static double metric_baseline[NUM_SAM_BASELINE];
static int trial_index, art_count;

static int sec_count, cross_ypos;

static int three_times, drone_state;

static double baseline_avg, baseline_stddev;

static int cross_x, cross_y, direction_state;
static int leftarrow_x, leftarrow_y, rightarrow_x, rightarrow_y;
static int uparrow_x, uparrow_y, downarrow_x, downarrow_y;
static int move_speed;

void *DroneControl()
{
   ar_drone("192.168.2.1");      //Sets up ARDrone at provided IP address (Default is 192.168.1.1)
   control();                    //Starts Control Thread
   return NULL;
}


static void sig_char()
{
char buf[100];
int m;

while((m=read(0, buf, 100))>=0){printf("%d chars read\n", m);};
printf("%d chars read\n", m);
return;
}


draw_rect(int x, int y, int height, int width, int color)
{
int i;
    for (i=0; i<height; i++)
	draw_line(x, y+i, x+width, y+i, color); 
}

draw_cross(int x, int y)
{
    draw_rect(x-40, y-4, 8, 80, 0);
    draw_rect(x-4, y-40, 80, 8, 0);
}

clear_cross(int x, int y)
{
    draw_rect(x-40, y-4, 8, 80, 1);
    draw_rect(x-4, y-40, 80, 8, 1);
}


draw_leftarrow(int x, int y)
{int i, z;
float c;
    draw_rect(x, y, 10, 20, 0);

}

clear_leftarrow(int x, int y)
{int i, z;
float c;
    draw_rect(x, y, 10, 20, 1);

}

draw_rightarrow(int x, int y)
{int i, z;
float c;
    draw_rect(x, y, 10, 20, 0);

}

clear_rightarrow(int x, int y)
{int i, z;
float c;
    draw_rect(x, y, 10, 20, 1);
}

draw_uparrow(int x, int y)
{int i, z;
float c;
    draw_rect(x, y, 20, 10, 0);
}

clear_uparrow(int x, int y)
{int i, z;
float c;
    draw_rect(x, y, 20, 10, 0);
}


draw_downarrow(int x, int y)
{int i, z;
float c;
    draw_rect(x, y, 20, 10, 0);
}

clear_downarrow(int x, int y)
{
int i, z;
float c;
    draw_rect(x, y, 20, 10, 0);
}


void draw_direction()
{
    if(direction_state==0) {
	clear_uparrow(uparrow_x, uparrow_y);
	clear_downarrow(downarrow_x, downarrow_y);
	draw_leftarrow(leftarrow_x, leftarrow_y);
	draw_rightarrow(rightarrow_x, rightarrow_y);
    } else {
        clear_leftarrow(leftarrow_x, leftarrow_y);
        clear_rightarrow(rightarrow_x, rightarrow_y);
        draw_uparrow(uparrow_x, uparrow_y);
        draw_downarrow(downarrow_x, downarrow_y);
    }
}

int detect_noise(int count)
{
double sum, avg, delta, stddev;
int i;

    for(i=0; i<ARTIFACT_LEN*SAMPLE_RATE; i++){
	eeg_segment[i] = eegdata[(count+i-(ARTIFACT_LEN*SAMPLE_RATE))%(SAMPLE_RATE*SAM_LEN)];
    }
    sum = 0.0;
    for(i=0; i< ARTIFACT_LEN*SAMPLE_RATE; i++){
	sum += eeg_segment[i];
    }
    avg = sum / (ARTIFACT_LEN*SAMPLE_RATE);
    sum = 0.0;
    for(i=0; i< ARTIFACT_LEN*SAMPLE_RATE; i++){
	delta = eeg_segment[i] - avg;
	sum += delta * delta;
    }
    stddev = sum / (ARTIFACT_LEN*SAMPLE_RATE - 1);

    if(stddev > baseline_stddev){
	if(stddev/baseline_stddev > FISHER_THRESHOLD) {
//		printf("high noise detected %f\n", stddev/baseline_stddev);
		direction_state = (direction_state + 1) % 2;
		draw_direction();
		return 1;
	}
	else return 0;
    } else {
	if(baseline_stddev/stddev > FISHER_THRESHOLD) {
		printf("low noise detected %f\n", baseline_stddev/stddev);
		return 0;
	}
	else return 0;
    }
}

void trial_fft(int count, int index)
{
int i, j;
double a,b,t,p;

    for(j=0; j<NUM_SAMPLES; j++){
        fftraw[j] = (eegdata[(count+j-NUM_SAMPLES)%(SAMPLE_RATE*SAM_LEN)] * ((double)1.8/40.96))/2;
        /* apply Hamming window to the data */
        fftraw[j] = fftraw[j] * (ALPHA - BETA * cos(2*H_PI*(double)j/(NUM_SAMPLES-1)));
    }
    fft_power = test_stft_correctness(fftraw);

    p = 0.0;
    for (i=1; i<49; i++) p += log10(fft_power[i]);
    a = 0.0;
    for (i=8; i<13; i++) a += log10(fft_power[i]);
    b = 0.0;
    for (i=16; i<27; i++) b += log10(fft_power[i]);
    t = 0.0;
    for (i=4; i<9; i++) t += log10(fft_power[i]);

    alpha_trial[index] = a;
    beta_trial[index] = b;
    theta_trial[index] = t;
    power_trial[index] = p;

if(psycho_start) printf("alpha:%f   beta:%f    theta:%f\n", a/p, b/p, t/p);

    if(t/p > 0.12) {
        clear_cross(cross_x, cross_y);
        if(direction_state==0) cross_x = cross_x + move_speed;
        else cross_y = cross_y + move_speed;
        draw_cross(cross_x, cross_y);
    } else
    if(a/p < 0.11) {
	clear_cross(cross_x, cross_y);
	if(direction_state==0) cross_x = cross_x - move_speed;
	else cross_y = cross_y - move_speed;
	draw_cross(cross_x, cross_y);
    }

} 

static double median(double a, double b, double c)
{
    if(a > b) {
	if(b > c) return b; 
	else {
		if(a > c) return c;
		else return a;
	}
    } else {
	if(a > c) return a;
	else {
		if(b > c) return c;
		else return b;
	}
    }
}

void detect_fatigue(int index)
{
int i, count;
double ttest, tvari, delta;

    mean_metric_trial = vari_metric_trial = 0.0;

    for(i=0; i<NUM_SAM_TRIAL; i++){
	count = (index+i)%NUM_SAM_TRIAL;
        raw_metric_trial[i] = (alpha_trial[count])/beta_trial[count];
    }
    /* median filter */
    metric_trial[0] = raw_metric_trial[0];
    for(i=1; i< NUM_SAM_TRIAL-1; i++){
	metric_trial[i] = median(raw_metric_trial[i-1], raw_metric_trial[i], raw_metric_trial[i+1]);
    }
    metric_trial[NUM_SAM_TRIAL-1] = raw_metric_trial[NUM_SAM_TRIAL-1];

    for(i=0; i< NUM_SAM_TRIAL; i++){
	mean_metric_trial += metric_trial[i];
    }
    mean_metric_trial /= NUM_SAM_TRIAL;

    for(i=0; i<NUM_SAM_TRIAL; i++){
	delta = metric_trial[i] - mean_metric_trial;
	vari_metric_trial += delta*delta;
    }
    vari_metric_trial /= NUM_SAM_TRIAL-1;

    ttest = mean_metric_trial - mean_metric_baseline;

//    tvari = sqrt(vari_metric_trial/NUM_SAM_BASELINE + vari_metric_baseline/NUM_SAM_TRIAL);
    tvari = sqrt(vari_metric_trial/NUM_SAM_TRIAL + vari_metric_baseline/NUM_SAM_BASELINE);
    ttest = ttest/tvari;
    if(ttest > T_DISTRIBUTION) {
//	printf("High alpha detected: t-test %f\n", ttest);

/*        clear_cross(cross_x, cross_y);
        if(direction_state==0) cross_x = cross_x + move_speed;
        else cross_y = cross_y + move_speed;
        draw_cross(cross_x, cross_y);*/

	if(!state_switch) three_times ++;
    }
    else {
	three_times = 0;
//	printf("Alpha degree: %f\%\n", (ttest<0?0:ttest*100/T_DISTRIBUTION));
    }

    if(three_times >= 3 && !state_switch){
	three_times = 0;

	if(drone_state == LANDED){ 
//	    takeOff();
//printf("take off!!!!!!!!!!!!!!!!\n");
	    drone_state = TAKEOFF;
	    state_switch = 1;
	} else { 
//	    land();
//printf("landed!!!!!!!!!!!!!!!!!\n");
	    drone_state = LANDED;
	    state_switch = 1;
	}

    }
}

void *start_test(void *arg)
{
int n, tmp, i, j, tick;
double result;

while(1){

    while(!psycho_start && baseline_ready);
    sec_count = 0;
    trial_index = 0;
    art_count = 0;
    tick = 0;
    tmp = sample_count;
    while (tmp <= SAMPLE_RATE) {tmp++; while(tmp > sample_count);}
    while(1){
	if(!psycho_start) {sample_count = 0; break;}
	if((tmp%(SAMPLE_RATE/2))==0){
	    trial_fft(tmp, (trial_index + sec_count)%NUM_SAM_TRIAL);
	    sec_count ++;
	    art_count ++;
	    if(state_switch) {
		tick++;
		if(tick > 2*5) {
		    state_switch = 0;
		    tick = 0;
		}
	    }
	    if(art_count == ARTIFACT_LEN*2){
		art_count = 0;
		if(detect_noise(tmp-(SAMPLE_RATE/2))) {
		    sec_count -= ARTIFACT_LEN*2;
		}
	    }
	    if(sec_count == NUM_SAM_TRIAL) {
		/* test trial for fatigue detection */
		detect_fatigue(trial_index);
		sec_count -= 2;
		trial_index = (trial_index + 2) % NUM_SAM_TRIAL;

	    }
	}
	tmp ++;
	while(tmp > sample_count);
    }

}

}

void baseline_fft(int count, int index)
{
int i, j;
double a,b,t,p;

    for(j=0; j<NUM_SAMPLES; j++){
        fftraw[j] = (baseline_eeg[count+j-NUM_SAMPLES] * ((double)1.8/40.96))/2;
        /* apply Hamming window to the data */
        fftraw[j] = fftraw[j] * (ALPHA - BETA * cos(2*H_PI*(double)j/(NUM_SAMPLES-1)));
    }
    fft_power = test_stft_correctness(fftraw);

    p = 0.0;
    for (i=1; i<49; i++) p += log10(fft_power[i]);
    a = 0.0;
    for (i=8; i<13; i++) a += log10(fft_power[i]);
    b = 0.0;
    for (i=16; i<27; i++) b += log10(fft_power[i]);
    t = 0.0;
    for (i=4; i<9; i++) t += log10(fft_power[i]);

    alpha_baseline[index] = a;
    beta_baseline[index] = b;
    theta_baseline[index] = t;
    power_baseline[index] = p;

}


void process_baseline()
{
double sum, avg, delta;
int i, j;

    sum = 0.0;
    for(i=0; i< SAMPLE_RATE*BASELINE_LEN; i++){
	sum += baseline_eeg[i];
    }
    baseline_avg = avg = sum / (SAMPLE_RATE*BASELINE_LEN);
    sum = 0.0;
    for(i=0; i< SAMPLE_RATE*BASELINE_LEN; i++){
	delta = baseline_eeg[i] - avg;
	sum += delta * delta;
    }
    baseline_stddev = sum / (SAMPLE_RATE*BASELINE_LEN - 1);
    printf("Baseline Average: %f  Baseline Stddev: %f\n", baseline_avg, baseline_stddev);
    j = 0;
    for(i=NUM_SAMPLES; i<= SAMPLE_RATE*BASELINE_LEN; i+=SAMPLE_RATE/2){
	baseline_fft(i, j);
	j++;
    }
    mean_metric_baseline = 0.0;
    vari_metric_baseline = 0.0;
    for(i=0; i<NUM_SAM_BASELINE; i++){
	metric_baseline[i] = (alpha_baseline[i])/beta_baseline[i];
	mean_metric_baseline += metric_baseline[i];
    } 
    mean_metric_baseline /= NUM_SAM_BASELINE;
    for(i=0; i<NUM_SAM_BASELINE; i++){
	delta = metric_baseline[i] - mean_metric_baseline;
	vari_metric_baseline += delta*delta;
    }
    vari_metric_baseline /= NUM_SAM_BASELINE-1;


for(i=0; i<NUM_SAM_BASELINE; i++){
printf("p:%f a:%f b:%f t:%f\n", power_baseline[i], alpha_baseline[i], beta_baseline[i], theta_baseline[i]);

}
printf("means:%f variance:%f\n", mean_metric_baseline, vari_metric_baseline);

    baseline_ready = 1;
}

void acquire_baseline()
{
long tmp;
int i;

    gui_on = 1;
    tmp = sample_count;

    while(sample_count < tmp+SAMPLE_RATE*2);
    tmp = sample_count;
    while(sample_count < tmp+SAMPLE_RATE*BASELINE_LEN);
    gui_on = 0;
    for(i=0; i<SAMPLE_RATE*BASELINE_LEN; i++){
	baseline_eeg[i] = eegdata[(i+tmp)%(SAMPLE_RATE*SAM_LEN)];
    }
    fwrite(baseline_eeg, sizeof(double), SAMPLE_RATE*BASELINE_LEN, bfp);
}

int main(int argc, char **argv){
    char device[256];
    int fd, ch, i;
    struct stat sb;
    pthread_t ControlThread;

    if(argc > 1) strcpy(device, argv[1]);
    else strcpy(device, MODEMDEVICE);

//    if(pthread_create(&ControlThread, NULL, DroneControl, NULL)) {
//      fprintf(stderr, "Error creating thread\n");
//      return 1;
//    }

    three_times = 0;
    drone_state = LANDED;
    state_switch = 0;


    fd = sp_init(device);
    parser_init();
    fft_init();
    sample_count = 0;
    sec_count = 0;
    cross_ypos = 0;
    gui_on = 0;
    psycho_start = 0;
    eegdata = malloc(SAMPLE_RATE*SAM_LEN*sizeof(double));
    fftraw = malloc(NUM_SAMPLES*sizeof(double));
    if(eegdata == NULL || fftraw == NULL) {
        fprintf(stderr, "No enough memory\n");
        exit(0);
    }

printf("median %f %f %f\n", median(2,2,3), median(3,4,4), median (2,3,4));
    dfp = fopen("raweeg","w+");
    if (dfp == NULL) {perror("raweeg"); exit(-1); }

    baseline_ready = 0;
    if (stat("baseline", &sb) != -1) {
	bfp = fopen("baseline", "r");
	if(bfp == NULL) {
	    perror("baseline");
	    goto next;
	}
	i = fread(baseline_eeg, sizeof(double), SAMPLE_RATE*BASELINE_LEN, bfp);
	if(i == (SAMPLE_RATE*BASELINE_LEN)) process_baseline();
	fclose(bfp);
    }

next:
    bfp = fopen("baseline","w+");
    if (bfp == NULL) {perror("baseline"); exit(-1); }


    dsp = XOpenDisplay( NULL );
    if( !dsp ){ return 1; }


    int screenNumber = DefaultScreen(dsp);
    pthread_t tid1, tid2;

    white = WhitePixel(dsp,screenNumber);
    black = BlackPixel(dsp,screenNumber);

    win = XCreateSimpleWindow(dsp,
                               DefaultRootWindow(dsp),
                               50, 50,   // origin
                               1200, 800, // size
                               0, black, // border
                               black );  // backgd

    XMapWindow( dsp, win );


    long eventMask = StructureNotifyMask;
    XSelectInput( dsp, win, eventMask );

    XEvent evt;
    do{
      XNextEvent( dsp, &evt );   // calls XFlush
    }while( evt.type != MapNotify );


    gc = XCreateGC( dsp, win,
                     0,        // mask of values
                     NULL );   // array of values
    XSetForeground( dsp, gc, black );


//packet_process(&fd);
    pthread_create(&tid1, NULL, &packet_process, (void *)&fd);
    pthread_create(&tid2, NULL, &start_test, NULL);

    eventMask = ButtonPressMask|ButtonReleaseMask;
    XSelectInput(dsp,win,eventMask); // override prev

    cross_x = 300; cross_y = 300;
    draw_cross(cross_x, cross_y);
    draw_rect(700, 50, 40, 40, 0);
    direction_state = 0;
    leftarrow_x = 20; leftarrow_y = 20; 
    rightarrow_x = 20; rightarrow_y = 40;
    uparrow_x = 20; uparrow_y = 20;
    downarrow_x = 40; downarrow_y = 20;
    draw_direction();
    move_speed = 10;

printf("space bar: start, g: EEG wave, b: acquire baseline, q: quit\n");

while(1){

    ch = getchar();
    //printf("ch is %d\n", ch);
    if(ch == 32) {
        if(drone_state == TAKEOFF) {
            while(state_switch);
            //land();
            drone_state = LANDED;
        }

	psycho_start = (psycho_start + 1)%2;
	if(psycho_start)printf("space bar: pause, g: EEG wave, q: quit\n");
	else printf("space bar: start, g: EEG wave, b: acquire baseline, q: quit\n");
    }
    else if(ch == 103 && psycho_start == 0) gui_on = (gui_on + 1)%2;
    else if(ch == 98 && psycho_start == 0) {
	acquire_baseline();
	process_baseline();
	printf("space bar: start, g: EEG wave, b: acquire baseline, q: quit\n");
    }
    else if(ch == 113) {

//        terminateThread();   //Terminate Control Thread (should be called ONLY
                        //after landing for the last time)

        // Stops Program terminating early by waiting for control thread
        // to terminate properly.
//        pthread_join(ControlThread, NULL);


        fwrite(baseline_eeg, sizeof(double), SAMPLE_RATE*BASELINE_LEN, bfp);
        fclose(dfp);
        fclose(bfp);

	exit(0);
    }
}
 
    do{
      XNextEvent( dsp, &evt );   // calls XFlush()
    }while( evt.type != ButtonRelease );


    XDestroyWindow( dsp, win );
    XCloseDisplay( dsp );

    return 0;
}

void draw_line(int x1, int y1, int x2, int y2, int color)
{
    switch(color) {
	case WHITE:
		XSetForeground( dsp, gc, white );
		break;
	case BLACK:
		XSetForeground( dsp, gc, black );
		break;
	default: break;
    }
    XDrawLine(dsp, win, gc, x1, y1, x2, y2); //from-to
    XSync(dsp, False);
}
