#pragma once
#include "InorderIterator.h"
#include "Dictionary.h"
#include "KeyValue.h"
template<class K, class T>
class DictionaryIterator : public InorderIterator<KeyValue<K,T>>
{
public:
	DictionaryIterator(Dictionary<K,T>& dict) : InorderIterator<KeyValue<K, T>>(dict.getRoot()) {}

	void SetList(Dictionary<K, T>& dict) {
		this->SetTree(dict.GetRoot());
	}
};

