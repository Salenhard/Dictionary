#pragma once
#include "InorderIterator.h"
#include "Dictionary.h"
#include "KeyValue.h"
template<class K, class T>
class DictionaryIterator : public InorderIterator<KeyValue<K,T>>
{
private:
	Dictionary<K,T> dictionary;
public:
	DictionaryIterator(Dictionary<K,T>& dict) : InorderIterator<KeyValue<K, T>>(dict.getRoot()), dictionary(dict) {};
};

