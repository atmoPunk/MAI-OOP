#include "TAllocationBlock.h"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count) : _size(size), _count(count) {
	_used_blocks = (char*) malloc(_size * _count);
	_free_blocks = new TBinTree<void*>();
	for(size_t i = _count / 2; i < _count; i++) {
		_free_blocks->insert((void*) (_used_blocks + i * _size), &(_free_blocks->root), nullptr);
	}
	for(size_t i = 0; i < _count / 2; i++) {
		_free_blocks->insert((void*) (_used_blocks + i * _size), &(_free_blocks->root), nullptr);
	}
	_free_count = _count;
	std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void* TAllocationBlock::allocate() {
	void* result = nullptr;
	if(_free_count > 0) {
		TNode<void*>* resNode;
		resNode = _free_blocks->findLeaf(_free_blocks->root);
		result = resNode->block;
		if(resNode->parent == nullptr) {
			_free_blocks->root = nullptr;
		}
		else if(resNode->parent->left == resNode) {
			resNode->parent->left = nullptr;
		}
		else {
			resNode->parent->right = nullptr;
		}
		delete resNode;
		_free_count--;
		std::cout << "TAllocationBlock: Allocate" << std::endl;
	} else {
		std::cout << "TAllocationBlock: No Memory" << std::endl;
	}
	return result;
}

void TAllocationBlock::deallocate(void* ptr) {
	std::cout << "TAllocationBlock: Deallocate" << std::endl;
	_free_blocks->insert((void*) ptr, &(_free_blocks->root), nullptr);
	_free_count++;
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
	delete _used_blocks;
	delete _free_blocks;
}
