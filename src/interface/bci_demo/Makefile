all: window

window.o: window.c eeg.h
	gcc -I /usr/include/X11 -c window.c -O2
drone.o: drone.c drone.h
	gcc -c drone.c -O2
serial.o: serial.c eeg.h
	gcc -c serial.c -O2
parser.o: parser.c eeg.h
	gcc -c parser.c -O2
dft.o: dft.c eeg.h
	gcc -c dft.c -O2
fft.o: fft.c
	gcc -c fft.c -O2

window: window.o drone.o parser.o serial.o dft.o fft.o
	gcc -L /usr/lib/X11 -o window window.o drone.o parser.o serial.o dft.o fft.o -lX11 -lpthread -lm

clean:
	rm -rf *.o window
