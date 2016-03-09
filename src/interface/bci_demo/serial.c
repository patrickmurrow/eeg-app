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
#include "eeg.h"

/* baudrate settings are defined in <asm/termbits.h>, which is
included by <termios.h> */
#define BAUDRATE B115200            
/* change this definition for the correct port */
#define MODEMDEVICE "/dev/rfcomm0"
#define _POSIX_SOURCE 1 /* POSIX compliant source */


static int fd;
static struct termios oldtio,newtio;

int sp_init(char *device)
{
    int res;

    fd = open(device, O_RDWR | O_NOCTTY | O_NONBLOCK );
    if (fd <0) {perror(device); exit(-1); }

    res = tcgetattr(fd,&oldtio);  // save current serial port settings
    if (res <0) {perror("Failed to get attr"); exit(-1); }

    bcopy(&oldtio, &newtio, sizeof(newtio));
        
    cfsetospeed(&newtio, (speed_t)BAUDRATE);
    cfsetispeed(&newtio, (speed_t)BAUDRATE);
    cfmakeraw(&newtio);

    newtio.c_cc[VMIN] = 1;
    newtio.c_cc[VTIME] = 10;

    newtio.c_cflag &= ~CSTOPB;
    newtio.c_cflag &= ~CRTSCTS;    // no HW flow control
    newtio.c_cflag |= CLOCAL | CREAD;
    res = tcsetattr(fd, TCSANOW, &newtio);
    if (res <0) {perror("Failed to set attr"); exit(-1); }

    return fd;

}

void sp_exit()
{
    /* restore the old port settings */
    tcsetattr(fd, TCSANOW, &oldtio);
}

