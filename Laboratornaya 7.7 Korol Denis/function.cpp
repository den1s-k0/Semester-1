#include "Header.h"

Stroka :: Stroka() {
	this->SIZE0 = 0;
	this->STR = nullptr;
}

Stroka::Stroka(const Stroka& other) {
	this->SIZE0 = other.SIZE0;
	this->STR = new char[this->SIZE0];
	for (int i = 0; i < this->SIZE0; i++)
	{
		this->STR[i] = other.STR[i];
	}
}

Stroka::Stroka(char*& str) {
	this->SIZE0 = strlen(str) + 1;
	this->STR = new char[this->SIZE0];
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		this->STR[i] = str[i];
	}
	this->STR[this->SIZE0 - 1] = '\0';
} 

Stroka::Stroka(const char str[]) {
	this->SIZE0 = strlen(str) + 1;
	this->STR = new char[this->SIZE0];
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		this->STR[i] = str[i];
	}
	this->STR[this->SIZE0 - 1] = '\0';
}

Stroka::~Stroka() {
	delete[] this->STR;
}

Stroka &Stroka:: operator =(const Stroka& str) {
	delete[] this->STR;
	this->SIZE0 = str.SIZE0;
	this->STR = new char[this->SIZE0];
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		this->STR[i] = str.STR[i];
	}
	this->STR[this->SIZE0 - 1] = '\0';
	return *this;
}

Stroka Stroka:: operator +(int N) const {
	Stroka result;
	result.SIZE0 = this->SIZE0 + N;
	result.STR = new char[result.SIZE0];
	for (int i = 0; i < (result.SIZE0 - N - 1); i++)
	{
		result.STR[i] = this->STR[i];
	}
	for (int i = this->SIZE0 - 1; i < result.SIZE0 - 1; i++)
	{
		result.STR[i] = '|';
	}
	result.STR[result.SIZE0 - 1] = '\0';
	return result;
}

Stroka Stroka:: operator -(int N) const {
	Stroka result;
	result.SIZE0 = this->SIZE0 - N;
	result.STR = new char[result.SIZE0];
	for (int i = 0; i < result.SIZE0 - 1; i++)
	{
		result.STR[i] = this->STR[i];
	}
	result.STR[result.SIZE0 - 1] = '\0';
	return result;
}

Stroka& Stroka:: operator ++() {
	Stroka result(*this);
	this->SIZE0++;
	delete[] this->STR;
	this->STR = new char[this->SIZE0];
	this->STR[0] = '|';
	for (int i = 1; i < this->SIZE0 - 1; i++)
	{
		this->STR[i] = result.STR[i - 1];
	}
	this->STR[this->SIZE0 - 1] = '\0';
	return *this;
}

Stroka& Stroka:: operator ++(int value) {
	Stroka result(*this);
	this->SIZE0++;
	delete[] this->STR;
	this->STR = new char[this->SIZE0];
	for (int i = 0; i < this->SIZE0 - 2; i++)
	{
		this->STR[i] = result.STR[i];
	}
	this->STR[this->SIZE0 - 2] = '|';
	this->STR[this->SIZE0 - 1] = '\0';
	return *this;
}

Stroka& Stroka:: operator --(int value) {
	Stroka result(*this);
	this->SIZE0--;
	delete[] this->STR;
	this->STR = new char[this->SIZE0];
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		this->STR[i] = result.STR[i];
	}
	this->STR[this->SIZE0 - 1] = '\0';
	return *this;
}

Stroka& Stroka:: operator --() {
	Stroka result(*this);
	this->SIZE0--;
	delete[] this->STR;
	this->STR = new char[this->SIZE0];
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		this->STR[i] = result.STR[i + 1];
	}
	this->STR[this->SIZE0 - 1] = '\0';
	return *this;
}

Stroka Stroka:: operator *(int N) const {
	Stroka result;
	result.SIZE0 = this->SIZE0 * N;
	result.STR = new char[result.SIZE0];
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		result.STR[i] = this->STR[i];
	}
	for (int i = this->SIZE0 - 1; i < result.SIZE0 - 1; i++)
	{
		result.STR[i] = '|';
	}
	result.STR[result.SIZE0 - 1] = '\0';
	return result;
}

Stroka Stroka:: operator /(int N) const {
	Stroka result;
	result.SIZE0 = this->SIZE0 / N;
	result.STR = new char[result.SIZE0];
	for (int i = 0; i < result.SIZE0 - 1; i++)
	{
		result.STR[i] = this->STR[i];
	}
	result.STR[result.SIZE0 - 1] = '\0';
	return result;
}

Stroka Stroka:: operator *(const Stroka& str) const {
	Stroka result;
	result.SIZE0 = this->SIZE0 + str.SIZE0 - 1;
	result.STR = new char[result.SIZE0];
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		result.STR[i] = this->STR[i];
	}	
	for (int i = this->SIZE0 - 1; i < result.SIZE0 - 1; i++)
	{
		result.STR[i] = str.STR[i + 1 - this->SIZE0];
	}
	result.STR[result.SIZE0 - 1] = '\0';
	return result;
}

Stroka Stroka:: operator /(const Stroka& str) const {
	Stroka result;
	result.SIZE0 = min(this->SIZE0, str.SIZE0);
	result.STR = new char[result.SIZE0];
	for (int i = 0; i < result.SIZE0 - 1; i++)
	{
		if(this->STR[i] == str.STR[i]) result.STR[i] = this->STR[i];
	}
	result.STR[result.SIZE0 - 1] = '\0';
	return result;
}

Stroka& Stroka:: operator ~() {
	Stroka str(*this);
	for (int i = 0; i < this->SIZE0 - 1; i++) {
		this->STR[i] = str.STR[str.SIZE0 - i - 2];
	}
	this->STR[this->SIZE0 - 1] = '\0';
	return *this;
}

Stroka& Stroka:: operator -() {
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		if (this->STR[i] > 64 && this->STR[i] < 91 || this->STR[i] > 191 && this->STR[i] < 224) this->STR[i] += 32;
	}
	return *this;
}

Stroka& Stroka:: operator +() {
	for (int i = 0; i < this->SIZE0 - 1; i++)
	{
		if (this->STR[i] > 96 && this->STR[i] < 123 || this->STR[i] > 223 && this->STR[i] < 256) this->STR[i] -= 32;
	}
	return *this;
}

istream& operator >> (istream& is, Stroka& str) {
	cout << "¬ведите STR ";
	char buffer[1000];
	is.getline(buffer, sizeof(buffer)); 
	str.SIZE0 = strlen(buffer) + 1;
	str.STR = new char[str.SIZE0]; 
	for (int i = 0; i < str.SIZE0 - 1; i++)
	{
		str.STR[i] = buffer[i];
	}
	str.STR[str.SIZE0 - 1] = '\0';
	return is;
}

ostream& operator << (ostream& os, const Stroka& str) {
	cout << "SIZE0 = " << str.SIZE0 << " STR = " << str.STR << '\n';
	return os;
}