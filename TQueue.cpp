#include "TQueue.h"

TQueue::TQueue() : first(nullptr), last(nullptr), size(0) {};

TQueue::TQueue(const TQueue& original) {
    first = original.first;
    last = original.last;
    size = original.size;
}

void TQueue::Push(std::shared_ptr<IFigure> figure) {
    std::shared_ptr<TQueueItem> item(new TQueueItem(figure));
    if(last != nullptr) {
        last->SetNext(item);
        last = item;
    }
    else {
        first = item;
        last = item;
    }
    size++;
}

bool TQueue::Empty() {
    return size == 0;
}

void TQueue::Pop() {
    if(first != nullptr) {
        std::shared_ptr<TQueueItem> oldFirst = first;
        first = first->GetNext();
        oldFirst->SetNext(nullptr);
        size--;
        if(size == 0) {
            last = nullptr;
        }
    }
}

TQueue::~TQueue() {
}

std::ostream &operator<<(std::ostream &os, TQueue &queue) {
    if(queue.Empty()) {
        os << "Empty";
        return os;
    }
    std::shared_ptr<TQueueItem> item = queue.first;

    while(item != nullptr) {
        os << *item;
        item = item->GetNext();
    }

    return os;
}

std::shared_ptr<IFigure> TQueue::Front() {
    std::shared_ptr<IFigure> result;
    if (first != nullptr) {
        result = first->GetFigure();
    } else {
        result = nullptr;
    }
    return result;
}