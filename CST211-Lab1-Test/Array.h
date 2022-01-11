#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"
#include <string> 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename T>
class Array
{
private:
	T*	m_array;

	int	m_start_index;
	int	m_length;

public:
	Array() : m_array(new T[100]), m_length(0) {};
	Array(int length, int start_index = 0);
	Array(const Array<T>& copy);
	Array(Array<T>&& copy);
	~Array();

	Array& operator =(const Array<T>& rhs);
	Array& operator =(Array<T>&& rhs);

	T& operator [] (int index);

	int		GetStartIndex();
	int		GetLength();

	void	SetStartIndex(int start_index);
	void	SetLength(int length);

};

//Constructors---------------------------------------------------
//----------------------------------------------------------------
template <typename T>
Array<T>::Array(int length, int start_index)
{
	m_length		= length;
	this->m_array	= new T[m_length];

	this->SetStartIndex(start_index);
}

template <typename T>
Array<T>::Array(const Array<T>& copy)
{
	*this = copy;						//Arthur helped me modify mine into this
}

template<typename T>
inline Array<T>::Array(Array<T>&& copy)
{
	*this = std::move(copy);			//Arthur also helped me modify what I had into this
}

template<typename T>
inline Array<T>::~Array()
{
	delete[]m_array;
}

//Array Setters---------------------------------------------------
//----------------------------------------------------------------
template <typename T>
void Array<T>::SetStartIndex(int start_index)
{
	this->m_start_index = start_index;
}

template <typename T>
void Array<T>::SetLength(int length)
{
	if (length < 0)
		throw Exception();
	else if (length > m_length)
	{
		T* temparr = new T[length];
		
		for (int i = 0; i < m_length; i++)
			temparr[i] = m_array[i];

		delete[] m_array;
		
		m_array = nullptr;
		m_array = temparr;

		for (int i = m_length; i < length; i++)
			m_array[i] = T(); //Got this part from Gabe

		this->m_length = length;
	}
	else
		this->m_length = length;
}

//Array Getters---------------------------------------------------
//----------------------------------------------------------------
template <typename T>
int Array<T>::GetLength()
{
	return this->m_length;
}

template <typename T>
int Array<T>::GetStartIndex()
{
	return this->m_start_index;
}

//Operator Overloads----------------------------------------------
//----------------------------------------------------------------
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) //This was in the class example
{
	if (this != &rhs)
	{
		delete[] m_array;

		m_array = nullptr;

		if (rhs.m_array != nullptr)
		{
			m_array	= new T[rhs.m_length];
			m_length= rhs.m_length;

			for (int i = 0; i < rhs.m_length; i++)
				m_array[i] = rhs.m_array[i];
		}
	}

	this->SetStartIndex(rhs.m_start_index);
	this->SetLength(rhs.m_length);

	return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& rhs)
{
	if (this != rhs)
	{
		delete[] m_array;

		m_array = nullptr;

		if (rhs.m_array != nullptr)
		{
			m_array	= new T[rhs.m_length];
			m_length= rhs.m_length;

			for (int i = 0; i < rhs.m_length; i++)
				m_array[i] = rhs.m_array[i];
		}
	}

	this->SetStartIndex(rhs.m_start_index);
	this->SetLength(rhs.m_length);

	return *this;
}

template<typename T>
T& Array<T>::operator [] (int index)
{
	int lowerbound = this->GetStartIndex();
	int upperbound = this->GetLength()+lowerbound;

	if (index < lowerbound)
		throw Exception();
	else if (index > upperbound)
		throw Exception();
	else
		return m_array[index - lowerbound];
}
#endif
