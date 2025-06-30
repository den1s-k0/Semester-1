
#include <iostream>
#include <Windows.h>

using namespace std;

int main()

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите 2 числа ";
	int a, b, c;
	cin >> a >> b;
	if (a < 0) {
		a *= (-1);
		cout << "Число 1 берется по модулю" << endl;
	}
	if (b < 0) {
		b *= (-1);
		cout << "Число 2 берется по модулю" << endl;
	}
	if (a == 0 || b == 0) { cout << "Нок и Нод 0 не существует "; }
	else {
		c = a * b;
		while (a != 0 && b != 0) {
			if (a > b) {
				a -= b;
			}
			else {
				b -= a;
			}
		}
		cout << "Нод = " << a + b << '\n' << " Нок = " << (c / (a + b));
	}
	return 0;
}
