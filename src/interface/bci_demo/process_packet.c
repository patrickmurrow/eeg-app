#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "sfsource.h"
#include "read_packet.h"

#define BaseX 0
#define BaseY 120
#define BaseFX 250
#define BaseFY 300
#define BaseValue 2650
#define SmoothFactor 0.1
#define TI	0.02
#define G1	9.80665
#define VGRate	0.066 //0.057

extern void draw_line(int, int, int, int, int);


void *process_packet(void *arg)
{
  int fd, j, k=0, len;
  serial_header_t header;
  oscilloscope_t data;
  double Ax[5], Ay[5], avgAx=0.0, avgAy=0.0, speedX=0.0, speedY=0.0, distanceX=0.0, distanceY=0.0, accAx=0.0, accAy=0.0, pref_yposX, pref_yposY, f_yposX, f_yposY, tX=0.0, tY=0.0;
  unsigned long prevX=0, prevY=0, avgX=0, avgY=0, xpos=10, yposX, yposY;

  fd = *((int *) arg);
  for (;;)
//  for(j=0; j<10000; j++)
    {
      int len, i;
      const unsigned char *packet = read_sf_packet(fd, &len);

      if (!packet)
	exit(0);
      header.dest = ntohs(*(unsigned short *)(packet + 1));
      header.src = ntohs(*(unsigned short *)(packet + 3));
      header.length = *(unsigned char *)(packet + 5);
      header.group = *(unsigned char *)(packet + 6);
      header.type = *(unsigned char *)(packet + 7);
      data.version = ntohs(*(uint16_t *)(packet + 8));
      data.interval = ntohs(*(uint16_t *)(packet + 10));
      data.id = ntohs(*(uint16_t *)(packet + 12));
      data.count = ntohs(*(uint16_t *)(packet + 14));
      len = (header.length-8)/2;
      for(i=0;i<len;i++)
          data.readings[i] = ntohs(*(uint16_t *)(packet + 16 + i*2));

      printf("DEST SRC  LEN  GRP  TYPE VER  INT  ID   CNT  D1   D2   ...\n");
      printf("%04x ", header.dest);
      printf("%04x ", header.src);
      printf("%04x ", header.length);
      printf("%04x ", header.group);
      printf("%04x ", header.type);
      printf("%04x ", data.version);
      printf("%04x ", data.interval);
      printf("%04x ", data.id);
      printf("%04x ", data.count);
      for(i=0;i<len;i++) printf("%04d ", data.readings[i]);
      putchar('\n');
      if(k<100) {
	for(i=0;i<len/2;i++){
	    prevX += data.readings[2*i];
	    prevY += data.readings[2*i+1];
	    if(i==0 && k==0){
		pref_yposX = (double)data.readings[2*i];
		pref_yposY = (double)data.readings[2*i+1];
		tX += pref_yposX;
		tY += pref_yposY;
	    } else {
		f_yposX = pref_yposX + SmoothFactor*((double)data.readings[2*i]-(double)pref_yposX);
		f_yposY = pref_yposY + SmoothFactor*((double)data.readings[2*i+1]-(double)pref_yposY);
		pref_yposX = f_yposX;
		pref_yposY = f_yposY;
		tX += pref_yposX;
		tY += pref_yposY;
	    }
	}
	k++;
	if(k==100) {
	    prevX = prevX*2/(len*k);
            prevY = prevY*2/(len*k);
            pref_yposX = tX*2.0/(len*k);
	    yposX = prevX;
            pref_yposY = tY*2.0/(len*k);
	    yposY = prevY;
	}
	continue;
      }
/*
      for(i=0; i<(header.length-8)/4; i++) {
      	Ax[i] = ((((double)data.readings[2*i]-(double)prevX)/4096.0)*2.5)/0.057;
      	Ay[i] = ((((double)data.readings[2*i+1]-(double)prevY)/4096.0)*2.5)/0.057;
        prevX = data.readings[2*i];
        prevY = data.readings[2*i+1];
        distanceX = distanceX + speedX*0.02 + 0.5*Ax[i]*9.80665*0.02*0.02;
        distanceY = distanceY + speedY*0.02 + 0.5*Ay[i]*9.80665*0.02*0.02;
        speedX = speedX + Ax[i]*0.02*9.80665;
        speedY = speedY + Ay[i]*0.02*9.80665;
	printf("Ax Ay Vx Vy Dx Dy: %f %f %f %f %f %f\n", Ax[i], Ay[i], speedX, speedY, distanceX, distanceY);
      }
*/
      for(i=0;i<len/2;i++) {
	avgX += data.readings[2*i];
	avgY += data.readings[2*i+1];
	f_yposX = pref_yposX + SmoothFactor*((double)data.readings[2*i]-(double)pref_yposX);
	f_yposY = pref_yposY + SmoothFactor*((double)data.readings[2*i+1]-(double)pref_yposY);
	draw_line(xpos, yposX-BaseValue+BaseX, xpos+2, data.readings[2*i]-BaseValue+BaseX, 1);
	draw_line(xpos, yposY-BaseValue+BaseY, xpos+2, data.readings[2*i+1]-BaseValue+BaseY, 1);
	draw_line(xpos, (int)pref_yposX-BaseValue+BaseFX, xpos+2, (int)f_yposX-BaseValue+BaseFX, 1);
	draw_line(xpos, (int)pref_yposY-BaseValue+BaseFY, xpos+2, (int)f_yposY-BaseValue+BaseFY, 1);
	xpos += 2; 
	if(xpos > 990) xpos = 11;
	draw_line(xpos+1, 10, xpos+1, 489, 0);
	draw_line(xpos+2, 10, xpos+2, 489, 0);

	accAx += (((f_yposX-pref_yposX)/4096.0)*2.5)/VGRate;
	accAy += (((f_yposY-pref_yposY)/4096.0)*2.5)/VGRate;
	distanceX = distanceX + speedX*TI + 0.5*accAx*G1*TI*TI;
	distanceY = distanceY + speedY*TI + 0.5*accAy*G1*TI*TI;
	speedX = speedX + accAx*TI*G1;
	speedY = speedY + accAy*TI*G1;
	printf("Ax Ay Vx Vy Dx Dy: %f %f %f %f %f %f\n", accAx, accAy, speedX, speedY, distanceX, distanceY);

	yposX = data.readings[2*i];
	yposY = data.readings[2*i+1];
	pref_yposX = f_yposX;
	pref_yposY = f_yposY;
      }
/*
      avgX = avgX*2/len;
      avgY = avgY*2/len;
      avgAx = ((((double)avgX-(double)prevX)/4096.0)*2.5)/0.057;
      avgAy = ((((double)avgY-(double)prevY)/4096.0)*2.5)/0.057;
      accAx += avgAx;
      accAy += avgAy;
      accAx = ((int)(accAx*100))/100.0;
      accAy = ((int)(accAy*100))/100.0;
      prevX = avgX; avgX = 0;
      prevY = avgY; avgY = 0;
      distanceX = distanceX + speedX*0.1 + 0.5*accAx*9.80665*0.1*0.1;
      distanceY = distanceY + speedY*0.1 + 0.5*accAy*9.80665*0.1*0.1;
      speedX = speedX + accAx*0.1*9.80665;
      speedY = speedY + accAy*0.1*9.80665;
      printf("Ax Ay Vx Vy Dx Dy: %f %f %f %f %f %f\n", accAx, accAy, speedX, speedY, distanceX, distanceY);
*/
      putchar('\n');
      fflush(stdout);
      free((void *)packet);
    }
//printf("avg X Y: %ld %ld\n", totalX/5000, totalY/5000);
}
