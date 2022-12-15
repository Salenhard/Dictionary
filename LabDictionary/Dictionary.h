#pragma once
#include "keyval.h"
#include "bstree.h"
#include "treeiter.h"
template <class K, class T>
class Dictionary: public BinsTree<KeyValue<K,T>>
{
private:

	T defaultValue;
public:
	Dictionary(cosnt T& defaultval);
	T& operator[] (const K& index);
	int InDictionary(const K& keyval);
	void DeleteKey(const K& keyval);
};
template <class K, class T>
Dictionary<K, T>::Dictionary(const T& defaultval):BinSTree<KeyValue<K,T>(), defaultValue(defaultval) {}

template <class K, class T>
T& Dictionary<K, T>::operator[] (const K& index) {
	KeyValue<K, T> targetKey(index, defaultValue);

	if (!Find(targetKey))
		Insert(targetKey);
	return this->current->data.value;
}
template <class K, class T>
int Dictionary<K, T>::InDictionary(const K& keyval) {
	KeyValue<K, T> tmp(index, defaultValue);
	return !Find(tmp);
}


template <class K, class T>
int Dictionary<K, T>::DeleteKey(const K& keyval) {
	KeyValue<K, T> tmp(index, defaultValue);
	Delete(tmp);
}