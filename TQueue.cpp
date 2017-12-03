#include "TQueue.h"

template <class T, class TT> TQueue<T, TT>::TQueue() : first(nullptr), last(nullptr), size(0) {};

template <class T, class TT> void TQueue<T, TT>::Push(std::shared_ptr<T> container) {
    std::shared_ptr < TQueueItem <T> > item(new TQueueItem<T>(container));
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

template <class T, class TT> void TQueue<T, TT>::Insert(std::shared_ptr<TT> obj) {
    bool inserted = false;
    if(first != nullptr) {
        for(auto i : *this) {
            if(i->size < 5) {
                i->Push(obj);
                inserted = true;
                break;
            }
        }
    }

    if(!inserted) {
        std::shared_ptr<T> cont = std::make_shared<T>();
        cont->Push(obj);
        Push(cont);
    }
}

template <class T, class TT> bool TQueue<T, TT>::Empty() {
    return size == 0;
}

template <class T, class TT> void TQueue<T, TT>::Pop() {
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

template <class T, class TT> TQueue<T, TT>::~TQueue() {
}

template <class T, class TT> std::ostream &operator<<(std::ostream &os, TQueue<T, TT> &queue) {
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

template <class T, class TT> std::shared_ptr<T> TQueue<T, TT>::Front() {
    std::shared_ptr<T> result;
    if (first != nullptr) {
        result = first->GetFigure();
    } else {
        result = nullptr;
    }
    return result;
}

template <class T, class TT> TIterator< TQueueItem<T>, T > TQueue<T, TT>::begin() {
    return TIterator< TQueueItem<T>, T >(first);
}

template <class T, class TT> TIterator< TQueueItem<T>, T > TQueue<T, TT>::end() {
    return TIterator< TQueueItem<T>, T >(nullptr);
}

template class TQueue< TBinTree<std::shared_ptr <IFigure> >, IFigure >;
template std::ostream &operator<<(std::ostream &os, TQueue< TBinTree<std::shared_ptr <IFigure> >, IFigure > &queue);
