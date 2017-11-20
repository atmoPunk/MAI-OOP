#ifndef TNODE_H
#define TNODE_H

#include <cstdlib>
#include <algorithm>

struct TNode {
	TNode* left;
	TNode* right;
	TNode* parent;
	void* block;
	TNode(char* blk, TNode* par) {
		block = blk;
		left = nullptr;
		right = nullptr;
		parent = par;
	}

	void destroyNode() {
		if(this != nullptr) {
			left->destroyNode();
			right->destroyNode();
			delete this;
		}
	}

	~TNode() {
	}
};

#endif