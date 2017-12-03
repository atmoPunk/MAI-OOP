#ifndef TBINTREE_H
#define TBINTREE_H

#include <cstdlib>
#include <memory>
#include <iostream>
#include "IFigure.h"
#include "TNode.h"

template <class T>
class TBinTree {
public:
	TBinTree() {
		root = nullptr;
		size = 0;
	}

	~TBinTree() {
		root->destroyNode();
	}

	void Push(T blk) {
		insert(blk, &root, nullptr);
	}

	void insert(T blk, TNode<T>** node, TNode<T>* par) {
		if(*node == nullptr) {
			*node = new TNode<T>(blk, par);
			size++;
			return;
		}
		if(*blk < *(*node)->block) {
			insert(blk, &(*node)->left, *node);
		}
		else {
			insert(blk, &(*node)->right, *node);
		}
	}

	void Print(TNode<T>* node, int depth) {
		if(node != nullptr) {
			Print(node->right, depth + 4);
			for(int i = 0; i < depth; i++) {
				std::cout << " ";
			}
			// std::cout << node->block->Print() << std::endl;
			node->block->Print();
			Print(node->left, depth + 4);
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
	
	template <class A> friend std::ostream& operator<<(std::ostream& os, TBinTree<A>& obj) {
		os << "========================\n";
		obj.Print(obj.root, 0);
		os << "=========================\n";
		return os;
	}

	TNode<T>* root;
	size_t size;
};

template <class T>
class TBinTree<T*> {
public:
	TBinTree() {
		root = nullptr;
		size = 0;
	}

	~TBinTree() {
		root->destroyNode();
	}

	void Push(T* blk) {
		insert(blk, &root, nullptr);
	}

	void insert(T* blk, TNode<T*>** node, TNode<T*>* par) {
		if(*node == nullptr) {
			*node = new TNode<T*>(blk, par);
			size++;
			return;
		}
		if(blk < (*node)->block) {
			insert(blk, &(*node)->left, *node);
		}
		else {
			insert(blk, &(*node)->right, *node);
		}
	}

	void Print(TNode<T*>* node, int depth) {
		if(node != nullptr) {
			Print(node->right, depth + 4);
			for(int i = 0; i < depth; i++) {
				std::cout << " ";
			}
			// std::cout << node->block->Print() << std::endl;
			node->block->Print();
			Print(node->left, depth + 4);
		}
	}

	TNode<T*>* findLeaf(TNode<T*>* node) {
		if(node->left == nullptr) {
			if(node->right == nullptr) {
				return node;
			}
			return findLeaf(node->right);
		}
		return findLeaf(node->left);
	}
	
	template <class A> friend std::ostream& operator<<(std::ostream& os, TBinTree<A>& obj) {
	obj.Print(obj.root, 0);
	return os;
	}

	TNode<T*>* root;
	size_t size;
};


#endif 
