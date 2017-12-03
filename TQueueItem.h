#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H

#include "IFigure.h"
#include "TAllocationBlock.h"
#include <iostream>
#include <memory>
#include "TBinTree.h"
#include "TNode.h"

template <class T> class TQueueItem {
public:
    TQueueItem(const std::shared_ptr<T>& figure);
    virtual ~TQueueItem();
    
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);

    std::shared_ptr< TQueueItem<T> > SetNext(std::shared_ptr< TQueueItem<T> > next);
    std::shared_ptr< TQueueItem<T> > GetNext();
    std::shared_ptr<T> GetFigure() const;

    void* operator new(size_t size);
    void operator delete(void* ptr);
    
private:
    std::shared_ptr<T> figure;
    std::shared_ptr< TQueueItem<T> > next;

    static TAllocationBlock queueitem_allocator;    
};

#endif //TQUEUEITEM_H
