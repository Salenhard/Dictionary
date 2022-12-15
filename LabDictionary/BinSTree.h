#pragma once

#include <iostream>
#include "TreeNode.h"

template <class T>
class BinSTree {
private:					// ���� ������
	TreeNode<T>* current;	// ������� ������� ������
	TreeNode<T>* root;		// ������ ������
	int size;				// ������ (���-�� �����)
public:						// ������ ������
	TreeNode<T>* getCurrent() {
		if (this->current != nullptr)
			return this->current;
		else {
			std::cerr << "Current node is empty!";
			exit(1);
		}
	}
	int getSize()
	{
		return this->size;
	}

	TreeNode<T>* getRoot() {
		if (this->root != nullptr)
			return this->root;
		else {
			std::cerr << "Root is empty!";
			exit(1);
		}
	}

	TreeNode<T>* getTreeNode(T item, TreeNode<T>* lptr = nullptr, TreeNode<T>* rptr = nullptr) {
		TreeNode<T>* p;										// ��������� ������ ����
		p = new TreeNode<T>(item, lptr, rptr);				// ���������� ������ ����	
		if (p == nullptr)									// ���� ���� ������ �� ������� ������
		{
			std::cerr << "Error while memory allocation!\n";
			exit(1);
		}													// ����� ������� ������ �� ���� ����
		return p;
	}

									// �������� ����
	void deleteTreeNode(const T& item)

	{
		TreeNode<T>* dNodePtr, * pNodePtr, * rNodePtr;
		rNodePtr = nullptr;
		dNodePtr = findNode(item, pNodePtr);
		if (dNodePtr == nullptr)
			return;
		//���� ��� ����� ��������
		if (dNodePtr->left == nullptr && dNodePtr->right == nullptr && pNodePtr != nullptr) {
			if (dNodePtr->data < pNodePtr->data)
				pNodePtr->left = rNodePtr;
			else
				pNodePtr->right = rNodePtr;
			freeTreeNode(dNodePtr);
			this->size--;
			return;
		}
		//���� ���� ������ ����� ���
		else if (dNodePtr->right == nullptr)
			rNodePtr = dNodePtr->left;
		//���� ���� ������ ������ ���
		else if (dNodePtr->left == nullptr)
			rNodePtr = dNodePtr->right;
		//���� ���� ��� �������
		else {
			TreeNode<T>* pOfRNodePtr = dNodePtr;
			rNodePtr = dNodePtr->left;

			while (rNodePtr->right != nullptr)
			{
				pOfRNodePtr = rNodePtr;
				rNodePtr = rNodePtr->right;
			}

			if (pOfRNodePtr == dNodePtr)
				rNodePtr->right = dNodePtr->right;

			else 
				pOfRNodePtr->right = rNodePtr->left;
		}

		// ���� ����� �������� �� ��� �������� ���� ������� ���
		if (rNodePtr == nullptr) {
			this->root = rNodePtr;
		}

		else if (pNodePtr != nullptr && dNodePtr->data < pNodePtr->data)
			pNodePtr->left = rNodePtr;

		else if (pNodePtr != nullptr && dNodePtr->data >= pNodePtr->data)
			pNodePtr->right = rNodePtr;

		else if(dNodePtr->data > rNodePtr->data) {
			rNodePtr->right = dNodePtr->right;
			this->root = rNodePtr;
		}

		else {
			rNodePtr->left = dNodePtr->left;
			this->root = rNodePtr;
		}

		freeTreeNode(dNodePtr);
		this->size--;
	}

	BinSTree<T>& operator = (const BinSTree<T>& rhs)
	{
		// ������ ���������� ������ � ���� ����
		if (this == &rhs)
			return *this;

		// �������� ������� ������. ����������� ����� ������ � ������� ������
		clearList(this->root);
		this->root = copyTree(rhs->root);
		// ��������� �������� ��������� �������� ����� � ������ ������ ������
		this->current = this->root;
		this->size = rhs->size;
		// ���������� ������ �� ������� ������
		return *this;
	}

	void clearList(TreeNode<T>* t = root) {
		if (t != nullptr)
		{
			clearList(t->left);
			clearList(t->right);
			freeTreeNode(t);
		}
	}
	
	TreeNode<T>* copyTree(TreeNode<T>* t) {
		TreeNode<T>* newlptr, * newrptr, * newnode;

		if (t == nullptr)
			return nullptr;

		if (t->left != nullptr)
			newlptr = copyTree(t->left);
		else
			newlptr = nullptr;

		if (t->right != nullptr)
			newrptr = copyTree(t->right);
		else
			newrptr = nullptr;
		newnode = getTreeNode(t->data, newlptr, newrptr);

		return newnode;
	}
	// �������� item � ������ ������
	void insert(const T& item)
	{
		//t -������� ����, parent - ���������� ����
		TreeNode<T>* t = root, * parent = nullptr, * newNode = new TreeNode<T>(item);
		// ��������� �� ������ ������
		while (t != nullptr)
		{
			// �������� ������� ��������� 
			parent = t;
			if (item < t->data)
				t = t->left;
			else
				t = t->right;
		}
		// ���� �������� ������, �� � ������� � ������
		if (parent == nullptr)
			root = newNode;
		// ���� item ������ �������������
		else if (item < parent->data)
			parent->left = newNode;
		else
			parent->right = newNode;
		current = newNode;
		size++;
	}


	void freeTreeNode(TreeNode<T>* p) {
		delete p;
	}

	TreeNode<T>* findNode(const T& item, TreeNode<T>* &parent = nullptr) const {
		TreeNode<T>* t = this->root;
		parent = nullptr;

		while (t != nullptr)
		{
			if (item == t->data)
				break;
			else
			{
				parent = t;
				if (item < t->data)
					t = t->left;
				else
					t = t->right;
			}
		}
		return t;
	}

	BinSTree() {
		this->current = nullptr;
		this->size = 0;
		this->root = nullptr;
	}

	BinSTree(TreeNode<T>* root) {
		this->current = root;
		this->size = 1;
		this->root = root;
	}
	BinSTree(const T &item) {
		this->root = new TreeNode<T>(item);
		this->current = root;
		this->size = 1;
	}
};

