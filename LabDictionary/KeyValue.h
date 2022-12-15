#pragma once
template <class K, class T>
class KeyValue
{
protected:
	const K key;

public:
	// словарные данные €вл€ютс€ общедоступными
	T value;
	KeyValue(K keyValue, T dataValue);

	// операторы присваивани€. не измен€ют ключ
	KeyValue<K, T>& operator= (const KeyValue<K, T>& rhs) const;

	// операторы сравнени€, сравнивают два ключа
	int operator== (const KeyValue<K, T>& value) const;
	int operator== (const K& keyval) const;
	int operator< (const KeyValue<K, T>& value) const;
	int operator< (const K& keyval) const;

	// метод доступа к ключу
	K Key() const;
};

template <class K, class T>
KeyValue<K, T>::KeyValue(K keyValue, T datavalue) : key(keyValue), value(dataValue) {};
template <class K, class T>
KeyValue<K, T>& KeyValue<K, T>::operator= (const KeyValue<K, T>& rhs) const {
	if (key != rhs.key) {
		key = rhs.key;
		value = rhs.value;
	}
	else
		return
}

template <class K, class T>
int KeyValue<K, T>::operator== (const KeyValue<K, T>& value) const {
	return this->key == value.key;
}
template <class K, class T>
int KeyValue<K, T>::operator== (const K& keyval) const {
	return this->key == keyval;
}
template <class K, class T>
int KeyValue<K, T>::operator< (const KeyValue<K, T>&value) const {
	return this->key < value.key;
}
template <class K, class T>
int KeyValue<K, T>::operator< (const K& keyval) const {
	return this->key < keyval;
}
template <class K, class T>
K KeyValue<K, T>::Key() const {
	return key;
}