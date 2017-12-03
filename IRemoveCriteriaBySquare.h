#ifndef IREMOVECRITERIABYSQR_H
#define IREMOVECRITERIABYSQR_H

#include "IRemoveCriteria.h"

template <class T>
class IRemoveCriteriaBySquare : public IRemoveCriteria<T> {
public:
	IRemoveCriteriaBySquare(T value) : _value(value) {};
	bool isIt(T* value) override {
		return _value == *value;
	}
private:
	T _value;
};

#endif