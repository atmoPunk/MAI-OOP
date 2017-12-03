#ifndef TNODE_H
#define TNODE_H

#include <cstdlib>
#include <algorithm>

template <class T>
class TNode {
public:
	TNode* left;
	TNode* right;
	TNode* parent;
	T block;
	TNode(T blk, TNode<T>* par) {
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