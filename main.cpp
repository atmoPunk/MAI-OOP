#include <iostream>
#include <cstdlib>
#include <memory>

#include "TQueue.h"
#include "TQueueItem.h"
#include "TRectangle.h"
#include "TTrapezoid.h"
#include "TRhombus.h"
#include "IFigure.h"

//#include "TQueue.cpp"
//#include "TQueueItem.cpp"
//#include "TRectangle.cpp"
//#include "TTrapezoid.cpp"
//#include "TRhombus.cpp"

int main() {
    
    TQueue<IFigure> queue;

    std::shared_ptr<IFigure> ptr1 = std::make_shared<TRectangle>(1.0, 2.0);
    std::shared_ptr<IFigure> ptr2 = std::make_shared<TRhombus>(1, 1.57);
    std::shared_ptr<IFigure> ptr3 = std::make_shared<TTrapezoid>(1, 2, 1);
    
    queue.Push(ptr1);
    queue.Push(ptr2);
    queue.Push(ptr3);
    
    std::cout << std::endl << "QUEUE:" << std::endl;
    std::cout << queue;
    
    std::shared_ptr<IFigure> ptr = queue.Front();
    std::cout << std::endl << "Figure 1:" <<std::endl;
    ptr->Print();
    queue.Pop();
    
    ptr = queue.Front();
    std::cout << std::endl << "Figure 2:" <<std::endl;
    ptr->Print();
    queue.Pop();
    
    return 0;
}
