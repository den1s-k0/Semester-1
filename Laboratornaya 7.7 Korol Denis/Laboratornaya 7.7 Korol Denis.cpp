#include "Header.h"


int main()
{
	setlocale(LC_ALL, "RU");
	Stroka a("LoXopEd");
	cout << "a = " << a;
	Stroka b(a);
	cout << "b = " << b;
	Stroka c;
	cin >> c;
	cout << "c = " << c;
	b = a + 5;
	cout << "b = a + 5\t" << b;
	c = b - 3;
	cout << "c = b - 3\t" << c;
	cout << "a++\t" << a++;
	cout << "++a\t" << ++a;
	cout << "a--\t" << a--;
	cout << "--a\t" << --a;
	b = a * 3;
	cout << "b = a * 3\t" << b;
	b = b / 2;
	cout << "b = b / 2\t" << b;
	b = b * c;
	cout << "b = b * c\t" << b;
	b = b / a;
	cout << "b = b / a\t" << b;
	~b;
	cout << "~b\t" << b;
	-b;
	cout << "-b\t" << b;
	+b;
	cout << "+b\t" << b;
}
