#ifndef TQUEUE_H
#define TQUEUE_H

#include "IFigure.h"
#include "TRectangle.h"
#include "TRhombus.h"
#include "TTrapezoid.h"
#include "TQueueItem.h"
#include "TIterator.h"
#include "TBinTree.h"
#include "TNode.h"
#include "IRemoveCriteria.h"
#include "IRemoveCriteriaAll.h"
#include <memory>

template <class T, class TT> class TQueue {
public:
    TQueue();
    virtual ~TQueue();

    template<class A, class AA> friend std::ostream& operator<<(std::ostream& os, TQueue<A, AA>& queue);

    void Push(std::shared_ptr<T> container);
    void RemoveItemSq(IRemoveCriteria<double>* criteria);
    template <class A> void RemoveItemAll(IRemoveCriteriaAll<TT, A>* criteria) {
        for(auto i : *this) {
            T copy;
            while(!i->empty()) {
                std::shared_ptr<TT> value = i->Pop();
                if(criteria->isIt(&*value)) {
                    std::cout << "Delete item" << std::endl;
                } else {
                    copy.Push(value);
                }
            }
            while(!copy.empty()) {
                i->Push(copy.Pop());
            }
        }
    }
    void Insert(std::shared_ptr<TT> obj);
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
