#ifndef TQUEUE_H
#define TQUEUE_H

#include "IFigure.h"
#include "TRectangle.h"
#include "TRhombus.h"
#include "TTrapezoid.h"
#include "TQueueItem.h"
#include "TIterator.h"
#include <memory>
#include <future>
#include <mutex>

template <class T> class TQueue {
public:
    TQueue();
    virtual ~TQueue();

    template <class A> friend std::ostream& operator<<(std::ostream& os, TQueue<A>& queue);

    size_t Size();

    void Push(std::shared_ptr<T> figure);
    bool Empty();
    void Pop();
    std::shared_ptr<T> Front();

    std::shared_ptr<T> operator[](size_t i);
    void Sort();
    void SortParallel();

    TIterator < TQueueItem<T>, T > begin();
    TIterator < TQueueItem<T>, T > end();

private:
    std::shared_ptr < TQueueItem <T> > first;
    std::shared_ptr < TQueueItem <T> > last;
    size_t size;
    std::future<void> SortInBackground();
};

#endif //TQUEUE_H
