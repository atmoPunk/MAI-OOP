#include "TAllocationBlock.h"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count) : _size(size), _count(count) {
	_used_blocks = (char*) malloc(_size * _count);
	_free_blocks = (void**) malloc(sizeof(void*) * _count);

	for(size_t i = 0; i < _count; i++) {
		_free_blocks[i] = _used_blocks + i * _size;
	}
	_free_count = _count;
	std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void* TAllocationBlock::allocate() {
	void* result = nullptr;
	if(_free_count > 0) {
		result = _free_blocks[--(_free_count)];
		std::cout << "TAllocationBlock: Allocate" << std::endl;
	} else {
		std::cout << "TAllocationBlock: No Memory" << std::endl;
	}
	return result;
}

void TAllocationBlock::deallocate(void* ptr) {
	std::cout << "TAllocationBlock: Deallocate" << std::endl;
	_free_blocks[++(_free_count)] = ptr;
}

bool TAllocationBlock::notFull() {
	return _free_count > 0;
}

TAllocationBlock::~TAllocationBlock() {
	if(_free_count < _count) {
		std::cout << "TAllocationBlock: Memory Leak" << std::endl;
	} else {
		std::cout << "TAllocationBlock: Memory free" << std::endl;
	}
	delete _free_blocks;
	delete _used_blocks;
}