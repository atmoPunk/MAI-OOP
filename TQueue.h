#ifndef TQUEUE_H
#define TQUEUE_H

#include "IFigure.h"
#include "TRectangle.h"
#include "TRhombus.h"
#include "TTrapezoid.h"
#include "TQueueItem.h"
#include <memory>

class TQueue {
public:
    TQueue();
    TQueue(const TQueue& original);
    virtual ~TQueue();

    friend std::ostream& operator<<(std::ostream& os, TQueue& queue);

    void Push(std::shared_ptr<IFigure> figure);
    bool Empty();
    void Pop();
    std::shared_ptr<IFigure> Front();

private:
    std::shared_ptr<TQueueItem> first;
    std::shared_ptr<TQueueItem> last;
    size_t size;
};


#endif //TQUEUE_H