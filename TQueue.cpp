#include "TQueue.h"

template <class T> TQueue<T>::TQueue() : first(nullptr), last(nullptr), size(0) {};

// TQueue::TQueue(const TQueue& original) {
//     first = original.first;
//     last = original.last;
//     size = original.size;
// }

template <class T> void TQueue<T>::Push(std::shared_ptr<T> figure) {
    std::shared_ptr < TQueueItem <T> > item(new TQueueItem<T>(figure));
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

template <class T> bool TQueue<T>::Empty() {
    return size == 0;
}

template <class T> void TQueue<T>::Pop() {
    if(first != nullptr) {
        std::shared_ptr < TQueueItem <T> > oldFirst = first;
        first = first->GetNext();
        oldFirst->SetNext(nullptr);
        size--;
        if(size == 0) {
            last = nullptr;
        }
    }
}

template <class T> TQueue<T>::~TQueue() {
}

template <class T> std::ostream &operator<<(std::ostream &os, TQueue<T> &queue) {
    if(queue.Empty()) {
        os << "Empty";
        return os;
    }
    std::shared_ptr< TQueueItem<T> > item = queue.first;

    while(item != nullptr) {
        os << *item;
        item = item->GetNext();
    }

    return os;
}

template <class T> std::shared_ptr<T> TQueue<T>::Front() {
    std::shared_ptr<T> result;
    if (first != nullptr) {
        result = first->GetFigure();
    } else {
        result = nullptr;
    }
    return result;
}