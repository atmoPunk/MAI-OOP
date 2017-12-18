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

typedef std::function <void (void)> Command;

void TestQueue() {
    std::cout << std::endl << "Queue Demonstration" << std::endl;

    TQueue <IFigure> queue;
    TBinTree <std::shared_ptr<Command> > tree_cmd;

    Command cmd_insert = [&]() {
        std::cout << "Command: create figures" << std::endl;
        std::default_random_engine generator;
        std::uniform_real_distribution<float> distr(1.0, 10.0);
        std::uniform_real_distribution<float> distrAngle(0.0, PI/2);
        std::uniform_int_distribution<int> distrInt(0, 10);
        for(int i = 0; i < 5; ++i) {
            int fig = distrInt(generator);
            if(fig < 4) { // Rectangle
                float side1 = distr(generator);
                float side2 = distr(generator);
                std::shared_ptr <IFigure> ptr = std::make_shared <TRectangle>(side1, side2);
                queue.Push(ptr);
            }
            else if(fig < 7) { // Rhombus
                float side =  distr(generator);
                float angle = distrAngle(generator);
                std::shared_ptr <IFigure> ptr = std::make_shared <TRhombus>(side, angle);
                queue.Push(ptr);
            } else {
                float side1 = distr(generator);
                float side2 = distr(generator);
                float height = distr(generator);
                std::shared_ptr <IFigure> ptr = std::make_shared <TTrapezoid>(side1, side2, height);
                queue.Push(ptr);
            }
            
        }

    };

    Command cmd_print = [&]() {
        std::cout << "================================================================" << std::endl;
        std::cout << "Print" << std::endl;
        std::cout << queue;
    };

    std::function <void(float)> cmd_delete_num = [&](float minSqr) {
        std::cout << "Delete" << std::endl;
        TQueue <IFigure> tmp;
        while(!queue.Empty()) {
            std::shared_ptr <IFigure> fig = queue.Front();
            queue.Pop();
            if(fig->Square() >= minSqr) {
                tmp.Push(fig);
            }
        }
        while(!tmp.Empty()) {
            std::shared_ptr <IFigure> fig = tmp.Front();
            tmp.Pop();
            queue.Push(fig);
        }
    };  

    float minSqr = 25.0;

    Command cmd_delete = [&]() { cmd_delete_num(minSqr); };

    tree_cmd.insert(std::shared_ptr <Command> (&cmd_print, [](Command*) {} ), &tree_cmd.root, nullptr);
    tree_cmd.insert(std::shared_ptr <Command> (&cmd_delete, [](Command*) {} ), &tree_cmd.root, nullptr);
    tree_cmd.insert(std::shared_ptr <Command> (&cmd_print, [](Command*) {} ), &tree_cmd.root, nullptr);
    tree_cmd.insert(std::shared_ptr <Command> (&cmd_insert, [](Command*) {} ), &tree_cmd.root, nullptr);

    while(!tree_cmd.empty()) {
        TNode<std::shared_ptr<Command> >* resNode = tree_cmd.findLeaf(tree_cmd.root);
        tree_cmd.delLeaf();
        std::future <void> ft = std::async(*(resNode->block));
        ft.get();
    }



    // std::shared_ptr<IFigure> ptr1 = std::make_shared<TRectangle>(1.0, 2.0);
    // std::shared_ptr<IFigure> ptr2 = std::make_shared<TRhombus>(1, 1.57);
    // std::shared_ptr<IFigure> ptr3 = std::make_shared<TTrapezoid>(1, 2, 1);
    
    // queue.Push(ptr1);
    // queue.Push(ptr2);
    // queue.Push(ptr3);
    
    // for(TIterator<TQueueItem <IFigure> , IFigure> i = queue.begin(); i != queue.end(); ++i) {
    //     (*i)->Print();
    // }
}

int main() {
    //TestAllocationBlock();
    TestQueue();   
	return 0;
}
