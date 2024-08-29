#pragma once


template<typename T>
class vector
{
	public:
		vector();
		vector(int size);
		~vector();
		void push(T element);
		void pop();
		void removeAt(int idx);
		void clear();
		void print();
		int size();
		bool isEmpty();
		void set(int idx, T element);
		T& get(int idx) const;
		T& operator[](int idx) const;
		


	private:
		T* _vectorArray;
		int _size = 1;
		int _count = 0;
		bool isOutOfRange(int idx) const;

};

