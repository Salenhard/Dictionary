#pragma once

template<class T>
class BinSTree;
// ќбъ€вление объекта дл€ узла бинарного дерева
template <class T> 
class TreeNode {

private:
	// укзатели левого и правого дочерних узлов
	TreeNode<T>* left;
	TreeNode<T>* right;
public:
	// открытый элемент, допускающий обновление
	T data;

	// конструктор
	TreeNode(const T& item, TreeNode<T>* lptr = nullptr, TreeNode<T>* rptr = nullptr) {
		this->data = item;
		this->left = lptr;
		this->right = rptr;
	}
	TreeNode<T>* Right() const {							//вернуть правый
		return this->right;
	}

	TreeNode<T>* Left() const {								//вернуть левый
		return this->left;
	}
	friend class BinSTree<T>;
};

