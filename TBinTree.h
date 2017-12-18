#ifndef TBINTREE_H
#define TBINTREE_H

#include <cstdlib>
#include "TNode.h"

template <class T>
class TBinTree {
public:
	TBinTree() {
		root = nullptr;
		count = 0;
	}

	~TBinTree() {
		root->destroyNode();
	}

	void insert(T blk, TNode<T>** node, TNode<T>* par) {
		if(*node == nullptr) {
			*node = new TNode<T>(blk, par);
			count++;
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
	
	void delLeaf() {
		TNode<T>* resNode = findLeaf(root);
		if(resNode->parent == nullptr) {
			delete resNode;
			root = nullptr;
		}
		else if(resNode->parent->left == resNode) {
			resNode->parent->left = nullptr;
			delete resNode;
		}
		else {
			resNode->parent->right = nullptr;
			delete resNode;
		}
		count--;
	}

	bool empty() {
		return count == 0;
	}

	TNode<T>* root;
	int count;
};

#endif 
