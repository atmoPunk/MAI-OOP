#include <iostream>
#include <cstdlib>
#include <memory>

#include "TQueue.h"
#include "TQueueItem.h"
#include "TRectangle.h"
#include "TTrapezoid.h"
#include "TRhombus.h"
#include "IFigure.h"

int main() {
    
    TQueue<IFigure> queue;

    std::shared_ptr<IFigure> ptr1 = std::make_shared<TRectangle>(1.0, 2.0);
    std::shared_ptr<IFigure> ptr2 = std::make_shared<TRhombus>(1, 1.57);
    std::shared_ptr<IFigure> ptr3 = std::make_shared<TTrapezoid>(1, 2, 1);
    
    queue.Push(ptr1);
    queue.Push(ptr2);
    queue.Push(ptr3);
    
    for(auto i : queue) {
        (*i).Print();
    }
    
    return 0;
}
