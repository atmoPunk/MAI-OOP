#ifndef TBINTREE_H
#define TBINTREE_H

#include <cstdlib>
#include "TNode.h"

template <class T>
class TBinTree {
public:
	TBinTree() {
		root = nullptr;
	}

	~TBinTree() {
		root->destroyNode();
	}

	void insert(T blk, TNode<T>** node, TNode<T>* par) {
		if(*node == nullptr) {
			*node = new TNode<T>(blk, par);
			return;
		}
		if(blk < (*node)->block) {
			insert(blk, &(*node)->left, *node);
		}
		else {
			insert(blk, &(*node)->right, *node);
		}
	}

	TNode<T>* findLeaf(TNode<T>* node) {
		if(node->left == nullptr) {
			if(node->right == nullptr) {
				return node;
			}
			return findLeaf(node->right);
		}
		return findLeaf(node->left);
	}
	
	TNode<T>* root;
};

#endif 
