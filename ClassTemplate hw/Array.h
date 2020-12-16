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
	~Array();
	const int getSize()const;
	void print()const;
	void setSize(const size_t& size, const size_t grow = 1);
	void add(const T& data);
	const int getUpperBound()const;
	const bool isEmpty()const;
	void freeExtra();
	void removeAll();
	const T getAt(const size_t& index);
	void setAt(const int& index, const T& elem);
	int& operator[](int index);
	void concat(const Array& other);
	Array& operator=(const Array& other);
	void showAdressOfArray()const;
	void insertAt(const int& index, const T& elem);
	void removeAt(const int& index);
};




template<typename T>
inline Array<T>::Array(const size_t& grow, const size_t& size)
	:size(size)
{
	arr = new T[size];
	if (grow!=0)
	{
		this->grow = grow;
	}
	else {
		this->grow = grow;
	}
}

template<typename T>
inline Array<T>::Array()
	:Array(1,0)
{
}

template<typename T>
inline Array<T>::~Array()
{
	removeAll();
}

template<typename T>
inline const int Array<T>::getSize() const
{
	return size;
}

template<typename T>
inline void Array<T>::print() const
{
	if (top!=-1)
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
}

template<typename T>
inline void Array<T>::setSize(const size_t& size, const size_t grow)
{
	this->grow = grow;
	if (this->size<size)
	{
		T* tmp = arr;
		this->size = size; 
		arr = new T[size];
		for (size_t i = 0; i < top+1; i++)
		{
			arr[i] = tmp[i];
		}
		delete[]tmp;
		return;
	}
	else if (this->size>size && top!=-1) {
		T *tmp = arr;
		this->size = size;
		arr = new T[size];
		// 10 23 40 60 * * size=6 top=3
		// 
		// 10 23 * * * * size=2 top=3
		top=size-1;
		for (int i = 0; i <= top; i++)
		{
			arr[i] = tmp[i];
		}
		
		delete[]tmp;
	}
}

template<typename T>
inline void Array<T>::add(const T& data)
{
	T* tmp = new T[size];
	tmp = arr;
	size += grow+1;
	++top;
	arr = new T[size];
	if (top!=0)
	{
	for (int i = 0; i < top; i++)
	{
		arr[i] = tmp[i];
	}
	}
	arr[top] = data;
	delete[]tmp;
}

template<typename T>
inline const int Array<T>::getUpperBound() const
{
	return top;
}

template<typename T>
inline const bool Array<T>::isEmpty() const
{
	return top==-1;
}

template<typename T>
inline void Array<T>::freeExtra()
{
	setSize(top + 1, grow);
}

template<typename T>
inline void Array<T>::removeAll()
{
	top = -1;
	arr = nullptr;
	delete[]arr;
}

template<typename T>
inline const T Array<T>::getAt(const size_t& index)
{
	if (!isEmpty() && index>=0 && index<=top)
	{
		
		return arr[index];
	}
	cout << "Enter correct index" << endl;
	return 0;
}

template<typename T>
inline void Array<T>::setAt(const int& index, const T& elem)
{
	if (isEmpty() || index >= size)
	{
		cout << "Enter correct index" << endl;
		return;
	}
	arr[index] = elem;
}

template<typename T>
inline int& Array<T>::operator[](int index)
{
	
		static int error;
		if (!isEmpty() && index >= 0 && index <= top)
		{
			return arr[index];
		}
		cerr << "Error index" << index << endl; // cerr = stream for errors
		return error;

}

template<typename T>
inline void Array<T>::concat(const Array& other)
{
	if (isEmpty() || other.isEmpty())
	{
		cout << "One of array is empty" << endl;
		return;
	}
	T* tmp = new T[(top + 1 )+ (other.top + 1)];
	for (int i = 0; i < top+1; i++)
	{
		tmp[i] = arr[i];
	}
	int j = 0;
	for (int i = top+1; i < (top+1)+(other.top+1); i++)
	{
		tmp[i] = other.arr[j];
		++j;
	}
	top = this->top + other.top+1;
	arr = new T[(top + 1) + (other.top + 1)];
	arr = tmp;
	tmp = nullptr;
	delete[]tmp;
}

template<typename T>
inline Array<T>& Array<T>::operator=(const Array& other)
{

	size = other.size;
	grow = other.grow;
	top = other.top;
	for (size_t i = 0; i < top+1; i++)
	{
		arr[i] = other.arr[i];
	}
	
	return *this;
}

template<typename T>
inline void Array<T>::showAdressOfArray() const
{
	std::cout << &arr << endl;
}

template<typename T>
inline void Array<T>::insertAt(const int& index, const T& elem)
{
	if (isEmpty() || index > top || index<0)
	{
		cout << "Enter correct index" << endl;
		return;
	}
	arr[index] = elem;

}

template<typename T>
inline void Array<T>::removeAt(const int& index)
{
	if (!isEmpty())
	{
	if (index==top || top==0)
	{
		--top;
		freeExtra();
		return;
	}
		T* tmp = arr;
		--size;
		--top;
		arr = new T[size];
		int i = 0;
		while (i != index) {
			arr[i] = tmp[i];
			++i;
		}
		while (i!=top+1)
		{
			arr[i] = tmp[i+1];
			++i;
		}
	}
}


