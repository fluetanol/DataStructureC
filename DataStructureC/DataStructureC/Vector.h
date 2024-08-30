#pragma once
#include "vectorBase.h"

template<typename T>
class vector : public arrayBase<T>
{
	public:
		vector();
		vector(int size);
		~vector();	
};



template<typename T>
vector<T>::vector() {
	this->_vectorArray = new T[1];
}

template<typename T>
vector<T>::vector(int size) {
	this->_size = size;
	this->_count = size;
	this->_vectorArray = new T[size];

	for (int i = 0; i < size; i++) {
		this->_vectorArray[i] = 0;
	}
}

template<typename T>
vector<T>::~vector() {
	delete[] this->_vectorArray;
	this->_vectorArray = nullptr;
}