#ifndef IREMOVECRITERIAALL_H
#define IREMOVECRITERIAALL_H

#include "IRemoveCriteria.h"

template <class T>
class IRemoveCriteriaAll {
public:
	IRemoveCriteriaAll(int a) { abc = a; }
	bool isIt(IFigure* ptr) {
		T* v = dynamic_cast<T*>(ptr);
		if(v == nullptr) {
			return false; 
		}
		return true;
	}
private:
	int abc;
};

#endif