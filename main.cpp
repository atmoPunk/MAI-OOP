#include <iostream>
#include <cstdlib>
#include <memory>
#include <ratio>
#include <chrono>
#include <vector>
#include <functional>
#include <thread>
#include <future>
#include <random>


#include "TQueue.h"
#include "TQueueItem.h"
#include "TRectangle.h"
#include "TTrapezoid.h"
#include "TRhombus.h"
#include "IFigure.h"

typedef std::function<void (void)> Command;

void TestQueue() {
    std::cout << std::endl << "Queue Demonstration" << std::endl;

    TQueue<IFigure> queue;
    TQueue<Command> queue_cmd;

    Command cmd_insert = [&]() {
        std::cout << "Command: create figures" << std::endl;
        std::default_random_engine generator;
        std::uniform_real_distribution<float> distr(1.0, 100.0);
        for(int i = 0; i < 10; ++i) {
            float side1 = distr(generator);
            float side2 = distr(generator);
            std::shared_ptr<IFigure> ptr = std::make_shared<TRectangle>(side1, side2);
            queue.Push(ptr);
        }

    };

    Command cmd_print = [&]() {
        std::cout << "Print" << std::endl;
        std::cout << queue;
    };



    std::shared_ptr<IFigure> ptr1 = std::make_shared<TRectangle>(1.0, 2.0);
    std::shared_ptr<IFigure> ptr2 = std::make_shared<TRhombus>(1, 1.57);
    std::shared_ptr<IFigure> ptr3 = std::make_shared<TTrapezoid>(1, 2, 1);
    
    queue.Push(ptr1);
    queue.Push(ptr2);
    queue.Push(ptr3);
    
    for(TIterator<TQueueItem <IFigure> , IFigure> i = queue.begin(); i != queue.end(); ++i) {
        (*i)->Print();
    }
}

void TestAllocationBlock() {
    std::cout << "Allocation Block Demonstration" << std::endl;
    
    TAllocationBlock allocator(sizeof(int), 10);
    int* a1 = nullptr;
    int* a2 = nullptr;
    int* a3 = nullptr;
    int* a4 = nullptr;
    int* a5 = nullptr;

    a1 = (int*) allocator.allocate();
    *a1 = 1;
    std::cout << "a1 pointer value: " << *a1 << std::endl;
    a2 = (int*) allocator.allocate();
    *a2 = 2;
    std::cout << "a2 pointer value: " << *a2 << std::endl;
    a3 = (int*) allocator.allocate();
    *a3 = 3;
    std::cout << "a3 pointer value: " << *a3 << std::endl;

    allocator.deallocate(a1);
    allocator.deallocate(a3);

    a4 = (int*) allocator.allocate();
    *a4 = 4;
    std::cout << "a4 pointer value: " << *a4 << std::endl;
    a5 = (int*) allocator.allocate();
    *a5 = 5;
    std::cout << "a5 pointer value: " << *a5 << std::endl;

    std::cout << "a1 pointer value: " << *a1 << std::endl;
    std::cout << "a2 pointer value: " << *a2 << std::endl;
    std::cout << "a3 pointer value: " << *a3 << std::endl;

    allocator.deallocate(a2);
    allocator.deallocate(a4);
    allocator.deallocate(a5);
}

void BenchmarAllcators() {
	std::cout << std::endl << "Benchmark" << std::endl;
	using namespace std::chrono;
	int** arr = (int**) malloc(sizeof(int*) * 1000);
	high_resolution_clock::time_point ownAllocBegin = high_resolution_clock::now();
	TAllocationBlock allocator(sizeof(int), 10000);
	for(int i = 0; i < 1000; i++) {
		arr[i] = (int*) allocator.allocate();
	}
	for(int i = 0; i < 1000; i++) {
		allocator.deallocate(arr[i]);
	}
	high_resolution_clock::time_point ownAllocEnd = high_resolution_clock::now();
	std::cout << duration_cast<microseconds>(ownAllocEnd - ownAllocBegin).count() << std::endl;
	high_resolution_clock::time_point AllocBegin = high_resolution_clock::now();
	std::vector <int*> vect(1000);
	for(int i = 0; i < 1000; i++) {
		vect[i] = (int*) malloc(sizeof(int));
	}
	for(int i = 0; i < 1000; i++) {
		free(vect[i]);
	}
	high_resolution_clock::time_point AllocEnd = high_resolution_clock::now();
	std::cout << duration_cast<microseconds>(AllocEnd - AllocBegin).count() << std::endl;
}

int main() {
    TestAllocationBlock();
    TestQueue();   
	return 0;
}
