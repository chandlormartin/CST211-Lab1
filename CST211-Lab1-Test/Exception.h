#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string> //from class demo
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Exception : virtual public std::exception
{
private:
		char* m_msg;
public:
	Exception();
	Exception(const char* msg);
	Exception(const Exception& copy);
	Exception(const Exception&& copy);
	~Exception();

	Exception& operator=(const Exception& rhs);
	Exception& operator=(const Exception&& rhs);
	friend ostream& operator<<(ostream& stream, const Exception& except);

	char* getMessage();
	void setMessage(char* msg);
};

//Constructors------------------------------------------
//------------------------------------------------------
Exception::Exception()
{
}

Exception::Exception(const char* msg)
{
}

Exception::Exception(const Exception& copy)
{
}

Exception::Exception(const Exception&& copy)
{
}

Exception::~Exception()
{ 
}

//Overloaded Operators----------------------------------
//------------------------------------------------------
Exception& Exception::operator=(const Exception& rhs)
{
	return *this;
}

Exception& Exception::operator=(const Exception&& rhs)
{
	return *this;
}

ostream& operator<<(ostream& stream, const Exception& except)
{
	return stream << except.m_msg;
}

//Getters-----------------------------------------------
//------------------------------------------------------
char* Exception::getMessage()
{
	return m_msg;
}

//Setters----------------------------------
//------------------------------------------------------
void Exception::setMessage(char* msg)
{
}

#endif