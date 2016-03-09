#include <sys/types.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <unistd.h>

#include "eeg.h"

/* our real numbers */
typedef double REAL;

/* Complex numbers and operations */
typedef struct {
     REAL re, im;
} COMPLEX;

#define c_re(c)  ((c).re)
#define c_im(c)  ((c).im)

double frequency = 5.0;


static COMPLEX *in1, *in2, *out1, *out2;
static double *power1, *power2;

extern void draw_sampleF(short data);

void test_fft_elem(int n, int j, COMPLEX * in, COMPLEX * out)
{
     int i;
     COMPLEX sum;
     COMPLEX w;
     c_re(sum) = c_im(sum) = 0.0;
     for (i = 0; i < n; ++i) {
          c_re(w) = cos((2.0 * H_PI * (i * j % n)) / n);
          c_im(w) = -sin((2.0 * H_PI * (i * j % n)) / n);
          c_re(sum) += c_re(in[i]) * c_re(w) - c_im(in[i]) * c_im(w);
          c_im(sum) += c_im(in[i]) * c_re(w) + c_re(in[i]) * c_im(w);
     }
     out[j] = sum;
     return;
}

void test_fft(int n, COMPLEX * in, COMPLEX * out)
{
     int j;

     for (j = 0; j < n; ++j)
          test_fft_elem(n, j, in, out);

     return;
}


void fft_init()
{
    in1 = malloc(NUM_SAMPLES * sizeof(COMPLEX));
    out1 = malloc(NUM_SAMPLES * sizeof(COMPLEX));
    in2 = malloc(NUM_SAMPLES * sizeof(COMPLEX));
    out2 = malloc(NUM_SAMPLES * sizeof(COMPLEX));

    power1 = malloc(NUM_SAMPLES * sizeof(double));
    power2 = malloc(NUM_SAMPLES * sizeof(double));

    if(in1 == NULL | out1 == NULL | in2 == NULL | out2 == NULL | power1 == NULL | power2 == NULL) {
        fprintf(stderr, "No enough memory\n");
        exit(0);
    }

}

double *test_stft_correctness(double *samples)
{
    double a, d, error;
    int i, count=0;

    for (i = 0; i < NUM_SAMPLES; i++) {
	c_re(in1[i]) = samples[i];
	c_im(in1[i]) = 0.0;

    }

    stft(NUM_SAMPLES, in1, out1);

          /* compute the relative error */
/*          error = 0.0;
          for (i = 0; i < NUM_SAMPLES; ++i) {
               a = sqrt((c_re(out1[i]) - c_re(out2[i])) *
                        (c_re(out1[i]) - c_re(out2[i])) +
                        (c_im(out1[i]) - c_im(out2[i])) *
                        (c_im(out1[i]) - c_im(out2[i])));
               d =  sqrt(c_re(out2[i]) * c_re(out2[i]) +
                         c_im(out2[i]) * c_im(out2[i]));
               if (d < -1.0e-10 || d > 1.0e-10)
                    a /= d;
               if (a > error)
                    error = a;
          }
          if (error > 1e-3) {
               printf("error=%e\n", error);
          }
*/
    for (i=0; i<NUM_SAMPLES; i++){
        power1[i] = sqrt(c_re(out1[i]) * c_re(out1[i]) + c_im(out1[i]) * c_im(out1[i]));
    }

return power1;

}

/*
int main(int argc, char *argv[])
{   
    unsigned cbBuffer=sizeof(samples);
    int count=0, i;
    COMPLEX *in1, *out1;

    if (argc >= 2){
        frequency = atof(argv[1]);
    }

        for (i = 0; i < NUM_SAMPLES; i++){
            samples[i] = sin(frequency * 2 * H_PI * (double)count /(double)(SAMPLE_RATE));
	    count++;
	    if(count==SAMPLE_RATE) count = 0;
	    printf("%f ", samples[i]);
        }
    printf("\n");

    test_correctness();

    return 0;
}
*/
