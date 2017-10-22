CC=g++
CFLAGS=-std=c++11
RM=rm -rf
OUT=main.out

all: build

build:  rhombus.o trapezoid.o rectangle.o queueItem.o queue.o main.o
	$(CC) $(CFLAGS) -o $(OUT) main.cpp TQueueItem.cpp TQueue.cpp TRhombus.cpp TTrapezoid.cpp TRectangle.cpp
	$(RM) *.o
	
debug: CFLAGS+=-g
debug: build

rectangle.o: TRectangle.cpp TRectangle.h IFigure.h
	$(CC) $(CFLAGS) -c TRectangle.cpp

rhombus.o: TRhombus.cpp TRhombus.h IFigure.h
	$(CC) $(CFLAGS) -c TRhombus.cpp

trapezoid.o: TTrapezoid.cpp TTrapezoid.h IFigure.h
	$(CC) $(CFLAGS) -c TTrapezoid.cpp		
	
queueItem.o: TQueueItem.cpp TQueueItem.h IFigure.h
	$(CC) $(CFLAGS) -c TQueueItem.cpp

queue.o: TQueue.cpp TQueue.h queueItem.o IFigure.h
	$(CC) $(CFLAGS) -c TQueue.cpp

main.o: main.cpp queue.o
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) *.o $(OUT)