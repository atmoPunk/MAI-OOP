#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H

#include "IFigure.h"
#include <iostream>
#include <memory>

class TQueueItem {
public:
    TQueueItem(const std::shared_ptr<IFigure>& figure);
    TQueueItem(const TQueueItem& item);
    virtual ~TQueueItem();
    
    friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

    std::shared_ptr<TQueueItem> SetNext(std::shared_ptr<TQueueItem> next);
    std::shared_ptr<TQueueItem> GetNext();
    std::shared_ptr<IFigure> GetFigure() const;
    
private:
    std::shared_ptr<IFigure> figure;
    std::shared_ptr<TQueueItem> next;    
};

#endif //TQUEUEITEM_H