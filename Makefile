CC=g++
CFLAGS=-std=c++11 -c
LD=g++
RM=rm -rf
OUT=main.out

all:build

build: rhombus.o trapezoid.o rectangle.o queueitem.o queue.o main.o allocationblock.o
	$(LD) -o $(OUT) main.o TRectangle.o TRhombus.o TTrapezoid.o TQueueItem.o TQueue.o TAllocationBlock.o

main.o: main.cpp TRectangle.h TTrapezoid.h TRhombus.h TQueueItem.h TQueue.h
	$(CC) $(CFLAGS) main.cpp

rectangle.o: TRectangle.cpp TRectangle.h IFigure.h
	$(CC) $(CFLAGS) TRectangle.cpp

trapezoid.o: TTrapezoid.cpp TTrapezoid.h IFigure.h
	$(CC) $(CFLAGS) TTrapezoid.cpp

rhombus.o: TRhombus.cpp TRhombus.h IFigure.h
	$(CC) $(CFLAGS) TRhombus.cpp

allocationblock.o: TAllocationBlock.cpp TAllocationBlock.h
	$(CC) $(CFLAGS) TAllocationBlock.cpp

queueitem.o: TQueueItem.cpp TQueueItem.h TRectangle.h TRhombus.h TTrapezoid.h TAllocationBlock.h
	$(CC) $(CFLAGS) TQueueItem.cpp

queue.o: TQueue.cpp TQueue.h TQueueItem.h TRectangle.h TRhombus.h TTrapezoid.h TIterator.h
	$(CC) $(CFLAGS) TQueue.cpp

clean:
	$(RM) *.o $(OUT)
