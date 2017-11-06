#ifndef TQUEUE_H
#define TQUEUE_H

#include "IFigure.h"
#include "TRectangle.h"
#include "TRhombus.h"
#include "TTrapezoid.h"
#include "TQueueItem.h"
#include "TIterator.h"
#include <memory>

template <class T> class TQueue {
public:
    TQueue();
    virtual ~TQueue();

    template <class A> friend std::ostream& operator<<(std::ostream& os, TQueue<A>& queue);

    void Push(std::shared_ptr<T> figure);
    bool Empty();
    void Pop();
    std::shared_ptr<T> Front();

    TIterator < TQueueItem<T>, T > begin();
    TIterator < TQueueItem<T>, T > end();

private:
    std::shared_ptr < TQueueItem <T> > first;
    std::shared_ptr < TQueueItem <T> > last;
    size_t size;
};

#endif //TQUEUE_H
