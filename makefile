CC=g++
OBJS=main.o P1.o
DEBUG=-g
CFLAGS=-Wall -I. -c $(DEBUG) -std=c++11
LFLAGS=-Wall -I. $(DEBUG)
all: exec1
exec1: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o pa1
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
P1.o: P1.cpp P1.h
	$(CC) $(CFLAGS) P1.cpp
clean:
	rm -f $(OBJS) *~ pa1
