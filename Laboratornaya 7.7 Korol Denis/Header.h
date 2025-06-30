#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Stroka {
private:
public:
	char* STR;
	int SIZE0;


	Stroka();
	Stroka(char*& str);
	Stroka(const char str[]);
	Stroka(const Stroka& str);
	~Stroka();
	Stroka & operator =(const Stroka& str);
	Stroka operator +(int N) const;
	Stroka operator -(int N) const;
	Stroka& operator ++();
	Stroka& operator ~();
	Stroka& operator +();
	Stroka& operator -();
	Stroka& operator ++(int value);
	Stroka& operator --();
	Stroka& operator --(int value);
	Stroka operator *(int N) const;
	Stroka operator /(int N) const;
	Stroka operator *(const Stroka& str) const;
	Stroka operator /(const Stroka& str) const;
	friend istream& operator >> (istream& is, Stroka& str);
	friend ostream& operator << (ostream& os, const Stroka& str);

};