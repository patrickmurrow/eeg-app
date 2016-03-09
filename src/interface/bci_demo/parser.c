#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "eeg.h"


#define BaseX 640
#define BaseValue 0

enum parserstate pstate;

static unsigned short rdata, tdata;
static int eegindex, even;
static unsigned int plen, rlen;
static int xpos, yposX;
static int count;

extern void draw_line(int, int, int, int, int);

void draw_sample(short data)
{

draw_line(xpos, BaseX-yposX, xpos+1, BaseX-data, 1);
//printf("y1: %d y2: %d fdata: %d ", yposX-BaseValue+BaseX, data-BaseValue+BaseX, data);
xpos += 1;
count ++;
if(count == SAMPLE_RATE) {
    draw_line(xpos, 540, xpos, 800, 1);
    count = 0;
}
if(xpos > 1034) xpos = 11;
draw_line(xpos+1, 540, xpos+1, 800, 0);
yposX = data;

}


void *packet_process(void *arg)
{
    unsigned char buf[256];
    int res, fd, i;

    
    fd = *((int *) arg);

    while (1) {
        res = read(fd,buf,255);
//        for(i=0;i<res;i++) printf("%x ", buf[i]);
        if(res > 0) parser(buf, res);
    }


}

void parser_init()
{
    eegindex = 0; plen = 0; rlen = 0; even = 0;
    xpos = 10; count = 0; pstate = SEEK;
}

void parser(unsigned char *buf, int len)
{
    unsigned int i, j;
    short *p;
    float fdata;

    i = 0;

    while (i < len) {
	switch (pstate){
	case SEEK:
		if (buf[i++] == 0xAA) pstate = SYNC;
		break;
	case SYNC:
		if (buf[i++] == 0xAA) pstate = PSTART;
		else pstate = SEEK;
		break;
	case PSTART:
		if(buf[i] == 0xAA) {i++;}
		else {plen = buf[i++]; pstate = PCODE;}
		break;
	case PCODE:
		if (buf[i++] == 0x80) pstate = RAWLEN;
		else pstate = NOTEEG;
		break;
	case RAWLEN:
		rlen = buf[i++]; pstate = RAWEEG;
		even = 0;
		break;
	case RAWEEG:
		if(rlen > 2) {pstate = SEEK; i++; break;}
		if(rlen != 0) {
			if(even == 0) {
			    rdata = (unsigned short)buf[i++];
			    even = 0xff;
			}
			else {
			    rdata = (rdata << 8) | buf[i]; 
			    i++;
			    eegdata[sample_count%(SAMPLE_RATE*SAM_LEN)] = (double)((short)rdata);
			    fwrite(&rdata, sizeof(short), 1, dfp);
			    sample_count ++;
			    even = 0;
			    if(gui_on){
				fdata = (short)rdata;
				fdata = (fdata * (1.8/4096))*200;
				draw_sample((short)fdata);
			    }
			}
			if(sample_count >= SAMPLE_RATE*1000000) {
			/*	p = eegdata;
				for (j=0; j< SAMPLE_RATE; j++) {
					fdata = *p++;*/
				/** to convert the values on the Raw EEG channel to voltages: 
				**  (rawValue * (1.8/4096)) / 2000. This is due to a 2000x gain, 
				**  4096 value range, and 1.8V input voltage. **/

/*					fdata = (fdata * (1.8/4096))/2000;
					fprintf(dfp, "%f ", fdata);
				}*/
				psycho_start = 0;
			}
			rlen --;
		} else pstate = CHKSUM;
		break;
	case CHKSUM:
		pstate = SEEK; i++;
		break;
	case NOTEEG:
		pstate = SEEK;
		/*if(plen != 0) {plen --; i++;}
		else pstate = SEEK;*/
		break;
	}

    }
}

