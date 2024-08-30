#pragma once
#include "datastructure.h"
#include <iostream>

using namespace std;

template<typename T>
class arrayBase : public datastructureBase
{
	public:
		void push(T element);
		void pop();
		void removeAt(int idx);
		void set(int idx, T element);
		T& get(int idx) const;
		T& operator[](int idx) const;
		virtual void clear() override;
		virtual void print() override;
		virtual bool isEmpty() override;
		virtual int size() override;

	protected:
		T* _vectorArray;
		int _size = 1;
		int _count = 0;
		bool isOutOfRange(int idx) const;
};


template<typename T>
void arrayBase<T>::push(T element)
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
void arrayBase<T>::pop() {
	if (_count <= 0) return;
	_count--;
}

template<typename T>
void arrayBase<T>::removeAt(int idx)
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
void arrayBase<T>::clear() {
	_count = 0;
}

template<typename T>
void arrayBase<T>::print() {
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
int arrayBase<T>::size() {
	return _count;
}

template<typename T>
bool arrayBase<T>::isOutOfRange(int idx) const
{
	return (_count <= idx || idx < 0);
}

template<typename T>
bool arrayBase<T>::isEmpty() {
	return _count == 0;
}

template<typename T>
T& arrayBase<T>::get(int idx) const
{
	if (isOutOfRange(idx)) {
		throw out_of_range("index Out of Range!");
	}

	return _vectorArray[idx];
}

template<typename T>
T& arrayBase<T>::operator[](int idx) const
{
	return get(idx);
}
