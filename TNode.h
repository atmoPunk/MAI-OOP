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

	~TNode() {
		delete left;
		delete right;
	}
};

#endif