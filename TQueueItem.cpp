#include "TQueueItem.h"

template <class T> TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& figure) {
    this->figure = figure;
    this->next = nullptr;
    std::cout << "\nQueue item: created\n";
}

template <class T> TQueueItem<T>::~TQueueItem() {
    std::cout << "\nQueue item: destroyed\n";
}

template <class A> std::ostream &operator<<(std::ostream &os, const TQueueItem<A> &obj) {
    std::shared_ptr<A> fig = obj.figure;
    fig->Print();
    return os;
}

template <class T> std::shared_ptr< TQueueItem<T> > TQueueItem<T>::SetNext(std::shared_ptr< TQueueItem<T> > next) {
    std::shared_ptr< TQueueItem<T> > old = this->next;
    this->next = next;
    return old;
}

template <class T> std::shared_ptr< TQueueItem<T> > TQueueItem<T>::GetNext() {
    return this->next;
}

template <class T> std::shared_ptr<T> TQueueItem<T>::GetFigure() const {
    return this->figure;
}

template class TQueueItem<IFigure>;
template std::ostream &operator<<(std::ostream &os, const TQueueItem<IFigure> &obj);
