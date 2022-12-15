#pragma once

template<class T>
class BinSTree;
// ���������� ������� ��� ���� ��������� ������
template <class T> 
class TreeNode {

private:
	// �������� ������ � ������� �������� �����
	TreeNode<T>* left;
	TreeNode<T>* right;
public:
	// �������� �������, ����������� ����������
	T data;

	// �����������
	TreeNode(const T& item, TreeNode<T>* lptr = nullptr, TreeNode<T>* rptr = nullptr) {
		this->data = item;
		this->left = lptr;
		this->right = rptr;
	}
	TreeNode<T>* Right() const {							//������� ������
		return this->right;
	}

	TreeNode<T>* Left() const {								//������� �����
		return this->left;
	}
	friend class BinSTree<T>;
};

