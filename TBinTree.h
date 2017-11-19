#ifndef TBINTREE_H
#define TBINTREE_H

#include <cstdlib>
#include "TNode.h"

class TBinTree {
public:
	TBinTree() {
		root = nullptr;
	}

	~TBinTree() {
		delete root;
	}

	void insert(char* blk, TNode** node, TNode* par) {
		if(*node == nullptr) {
			*node = new TNode(blk, par);
			return;
		}
		if(blk < (*node)->block) {
			insert(blk, &(*node)->left, *node);
		}
		else {
			insert(blk, &(*node)->right, *node);
		}
	}

	TNode* findLeaf(TNode* node) {
		if(node->left == nullptr) {
			if(node->right == nullptr) {
				return node;
			}
			return findLeaf(node->right);
		}
		return findLeaf(node->left);
	}
	
	TNode* root;
};

#endif 