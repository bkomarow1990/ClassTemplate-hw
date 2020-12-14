#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Array
{
private:
	size_t size = 0;
	size_t grow = 1;
	int top = -1;
	T* arr;
public:
	Array(const size_t & grow,const size_t& size);
	Array();
	const int getSize()const;
	void print()const;
};




template<typename T>
inline Array<T>::Array(const size_t& grow, const size_t& size)
	:size(size)
{
	if (grow!=0)
	{
		this->grow = grow;
	}
}

template<typename T>
inline Array<T>::Array()
	:grow(1),size(0)
{
}

template<typename T>
inline const int Array<T>::getSize() const
{
	return size;
}

template<typename T>
inline void Array<T>::print() const
{
	if (size!=0)
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
}
