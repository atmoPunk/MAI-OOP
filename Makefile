CC=g++
CFLAGS=-std=c++11 -c -g
LD=g++ -g
RM=rm -rf
OUT=main.out

main.o: main.cpp TRectangle.h TTrapezoid.h TRhombus.h TQueueItem.h TQueue.h TBinTree.h TNode.h
	$(CC) $(CFLAGS) main.cpp

rectangle.o: TRectangle.cpp TRectangle.h IFigure.h
	$(CC) $(CFLAGS) TRectangle.cpp

trapezoid.o: TTrapezoid.cpp TTrapezoid.h IFigure.h
	$(CC) $(CFLAGS) TTrapezoid.cpp

rhombus.o: TRhombus.cpp TRhombus.h IFigure.h
	$(CC) $(CFLAGS) TRhombus.cpp

allocationblock.o: TAllocationBlock.cpp TAllocationBlock.h
	$(CC) $(CFLAGS) TAllocationBlock.cpp

queueitem.o: TQueueItem.cpp TQueueItem.h TRectangle.h TRhombus.h TTrapezoid.h TAllocationBlock.h TBinTree.h TNode.h
	$(CC) $(CFLAGS) TQueueItem.cpp

queue.o: TQueue.cpp TQueue.h TQueueItem.h TRectangle.h TRhombus.h TTrapezoid.h TIterator.h TBinTree.h TNode.h
	$(CC) $(CFLAGS) TQueue.cpp

clean:
	$(RM) *.o $(OUT)

build: rhombus.o trapezoid.o rectangle.o queueitem.o queue.o allocationblock.o main.o
	$(LD) -o $(OUT) main.o TRectangle.o TRhombus.o TTrapezoid.o TQueueItem.o TQueue.o TAllocationBlock.o