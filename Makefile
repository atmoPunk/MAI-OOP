CC=g++
CFLAGS=-std=c++11
RM=rm -rf
OUT=main.out

all: build

build:
	$(CC) $(CFLAGS) -o $(OUT) main.cpp
	$(RM) *.o
	
debug: CFLAGS+=-g
debug: build

clean:
	$(RM) *.o $(OUT)