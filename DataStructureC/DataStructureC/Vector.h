#pragma once

template<typename T>
class vector
{
	public:
		int k;
		vector();
		vector(int size);
		~vector();
		void push(T element);
		void remove(int idx);
		void clear();
		void print();
		bool isEmpty();
		T get(int idx) const;
		T& operator[](T idx) const;


	private:
		T* _vectorArray;
		int _size = 0;

};

