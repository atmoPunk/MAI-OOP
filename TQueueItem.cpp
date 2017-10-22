#include "TQueueItem.h"

TQueueItem::TQueueItem(const std::shared_ptr<IFigure>& figure) {
    this->figure = figure;
    this->next = nullptr;
    std::cout << "\nQueue item: created\n";
}

TQueueItem::TQueueItem(const TQueueItem& original) {
    this->figure = original.figure;
    this->next = original.next;
    std::cout << "\nQueue item: copied\n";
}

TQueueItem::~TQueueItem() {
    std::cout << "\nQueue item: destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const TQueueItem &obj) {
    std::shared_ptr<IFigure> fig = obj.figure;
    fig->Print();
    return os;
}

std::shared_ptr<TQueueItem> TQueueItem::SetNext(std::shared_ptr<TQueueItem> next) {
    std::shared_ptr<TQueueItem> old = this->next;
    this->next = next;
    return old;
}

std::shared_ptr<TQueueItem> TQueueItem::GetNext() {
    return this->next;
}

std::shared_ptr<IFigure> TQueueItem::GetFigure() const {
    return this->figure;
}
