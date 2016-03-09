#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <termios.h>
#include <strings.h>

/* baudrate settings are defined in <asm/termbits.h>, which is
included by <termios.h> */
#define BAUDRATE B115200            
/* change this definition for the correct port */
#define MODEMDEVICE "/dev/rfcomm0"
#define _POSIX_SOURCE 1 /* POSIX compliant source */

#define FALSE 0
#define TRUE 1

volatile int STOP=FALSE; 

main()
{
          int fd, c, res, i;
          struct termios oldtio,newtio;
          unsigned char buf[256];
        /* 
          Open modem device for reading and writing and not as controlling tty
          because we don't want to get killed if linenoise sends CTRL-C.
        */
         fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY | O_NONBLOCK ); 
         if (fd <0) {perror(MODEMDEVICE); exit(-1); }

         res = tcgetattr(fd,&oldtio); /* save current serial port settings */
	 if (res <0) {perror("Failed to get attr"); exit(-1); }

         //bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */
	 bcopy(&oldtio, &newtio, sizeof(newtio));
        
        /* 
          BAUDRATE: Set bps rate. You could also use cfsetispeed and cfsetospeed.
          CRTSCTS : output hardware flow control (only used if the cable has
                    all necessary lines. See sect. 7 of Serial-HOWTO)
          CS8     : 8n1 (8bit,no parity,1 stopbit)
          CLOCAL  : local connection, no modem contol
          CREAD   : enable receiving characters
        */

	cfsetospeed(&newtio, (speed_t)BAUDRATE);
	cfsetispeed(&newtio, (speed_t)BAUDRATE);
	cfmakeraw(&newtio);

    newtio.c_cc[VMIN] = 1;
    newtio.c_cc[VTIME] = 10;

    newtio.c_cflag &= ~CSTOPB;
    newtio.c_cflag &= ~CRTSCTS;    /* no HW flow control? */
    newtio.c_cflag |= CLOCAL | CREAD;
    res = tcsetattr(fd, TCSANOW, &newtio);
    if (res <0) {perror("Failed to set attr"); exit(-1); }
        /*
          terminal settings done, now handle input
          In this example, inputting a 'z' at the beginning of a line will 
          exit the program.
        */

         while (STOP==FALSE) {     /* loop until we have a terminating condition */
         /* read blocks program execution until a line terminating character is 
            input, even if more than 255 chars are input. If the number
            of characters read is smaller than the number of chars available,
            subsequent reads will return the remaining chars. res will be set
            to the actual number of characters actually read */
            res = read(fd,buf,255); 
	    if(res > 0) {
		if(*buf == '\r') STOP=TRUE;
		printf("res is %d\n", res);
	        for(i=0; i<res; i++) printf("%x ", buf[i]);
	   }
         }
         /* restore the old port settings */
         tcsetattr(fd,TCSANOW,&oldtio);
}

