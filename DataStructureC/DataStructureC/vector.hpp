#include "vector.h"
#include <iostream>

using namespace std;


template<typename T>
vector<T>::vector(){
	_vectorArray = new T[1];
}

template<typename T>
vector<T>::vector(int size)
{
	_size = size;
	_count = size;
	_vectorArray = new T[size];

	for (int i = 0; i < size; i++) {
		if constexpr (is_same_v<T, string>)_vectorArray[i] = "-1";
		else _vectorArray[i] = 0;
	}
}


template<typename T>
vector<T>::~vector(){
	delete[] _vectorArray;
	_vectorArray = nullptr;
}


template<typename T>
void vector<T>::push(T element)
{
	if (_size == _count) {
		_size *= 2;
		T* _tempArray = new T[_size];
		for (int i = 0; i < _count; i++) {
			_tempArray[i] = _vectorArray[i];
		}
		delete[] _vectorArray;
		_vectorArray = _tempArray;
	}
	_vectorArray[_count] = element;
	_count++;
}

template<typename T>
void vector<T>::pop(){
	if (_count <= 0) return;
	_count--;
}

template<typename T>
void vector<T>::removeAt(int idx)
{
	if (isOutOfRange(idx)) {
		throw out_of_range("index Out of Range! ");
	}

	for (int i = idx + 1; i < _count; i++) {
		_vectorArray[i - 1] = _vectorArray[i];
	}

	_count--;
}

template<typename T>
void vector<T>::clear() {
	_count = 0;
}

template<typename T>
void vector<T>::print(){
	if (_count == 0) {
		cout << "No Element" << endl;
		return;
	}

	for (int i = 0; i < _count; i++) {
		cout << _vectorArray[i] << " ";
	}
	cout << endl;
}

template<typename T>
int vector<T>::size() {
	return _count;
}

template<typename T>
bool vector<T>::isOutOfRange(int idx) const
{
	return (_count <= idx || idx < 0);
}

template<typename T>
bool vector<T>::isEmpty(){
	return _count == 0;
}

template<typename T>
T& vector<T>::get(int idx) const
{
	if (isOutOfRange(idx)) {
		throw out_of_range("index Out of Range!");
	}

	return _vectorArray[idx];
}

template<typename T>
T& vector<T>::operator[](int idx) const
{
	return get(idx);
}







