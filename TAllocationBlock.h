#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <cstdlib>
#include "TBinTree.h"

class TAllocationBlock {
public:
	TAllocationBlock(size_t size, size_t count);
	void* allocate();
	void deallocate(void* ptr);
	bool notFull();
	virtual ~TAllocationBlock();

private:
	size_t _size;
	size_t _count;

	char* _used_blocks;
	TBinTree<void*>* _free_blocks;

	size_t _free_count;
};

#endif //TALLOCATIONBLOCK_H