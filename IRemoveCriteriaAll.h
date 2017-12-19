#ifndef IREMOVECRITERIAALL_H
#define IREMOVECRITERIAALL_H

#include "IRemoveCriteria.h"

template <class T, class C>
class IRemoveCriteriaAll : public IRemoveCriteria<T> {
public:
	bool isIt(T* ptr) override {
		C* v = dynamic_cast<C*>(ptr);
		if(v == nullptr) {
			return false; 
		}
		return true;
	}
private:
};

#endif
