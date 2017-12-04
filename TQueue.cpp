#include "TQueue.h"

template <class T> TQueue<T>::TQueue() : first(nullptr), last(nullptr), size(0) {};

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

template <class T> size_t TQueue<T>::Size() {
    return size;
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

template <class T> std::shared_ptr<T> TQueue<T>::operator[](size_t i) {
    if(i > size - 1) {
	std::cout << "Invalid argument" << std::endl;
	return std::shared_ptr<T>(nullptr);
    }
    size_t j = 0;
    for(auto k : *this) {
	if(j == i) {
	    return k;
	}
	j++;
    }
    return std::shared_ptr<T>(nullptr);
}

template <class T> void TQueue<T>::Sort() {
    if(size > 1) {
	std::shared_ptr<T> middle = Front();
	Pop();
	TQueue<T> left;
	TQueue<T> right;

	while(!Empty()) {
	    std::shared_ptr<T> item = Front();
	    Pop();
	    if(*item < *middle) {
		left.Push(item);
	    } else {
		right.Push(item);
	    }
	}
	left.Sort();
	right.Sort();

	while(!left.Empty()) {
	    Push(left.Front());
	    left.Pop();
	}
	Push(middle);
	while(!right.Empty()) {
	    Push(right.Front());
	    right.Pop();
	}
    }
}

template <class T> std::future<void> TQueue<T>::SortInBackground() {
    std::packaged_task< void(void) > task(std::bind(std::mem_fn(&TQueue<T>::SortParallel), this));
    std::future<void> res(task.get_future());
    std::thread th(std::move(task));
    th.detach();
    return res;
}

template <class T> void TQueue<T>::SortParallel() {
    if(size > 1) {
	std::shared_ptr<T> middle = Front();
	Pop();
	TQueue<T> left;
	TQueue<T> right;

	while(!Empty()) {
	    std::shared_ptr<T> item = Front();
	    Pop();
	    if(*item < *middle) {
		left.Push(item);
	    } else {
		right.Push(item);
	    }
	}

	std::future<void> left_res = left.SortInBackground();
	std::future<void> right_res = right.SortInBackground();
	left_res.get();
	while(!left.Empty()) {
	    Push(left.Front());
	    left.Pop();
	}
	Push(middle);
	right_res.get();
	while(!right.Empty()) {
	    Push(right.Front());
	    right.Pop();
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

template <class T> TIterator< TQueueItem<T>, T > TQueue<T>::begin() {
    return TIterator< TQueueItem<T>, T >(first);
}

template <class T> TIterator< TQueueItem<T>, T > TQueue<T>::end() {
    return TIterator< TQueueItem<T>, T >(nullptr);
}

template class TQueue<IFigure>;
template std::ostream &operator<<(std::ostream &os, TQueue<IFigure> &queue);
