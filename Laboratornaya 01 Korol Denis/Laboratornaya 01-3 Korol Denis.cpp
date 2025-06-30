
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main()

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, s = 0;
	cout << "Введите число ";
	cin >> a;
	if (a > 0) {
		while (a > 0) {
			s = s + a % 10;
			a /= 10;
		}
		cout << "Сумма = " << s;
	}
	else
	if (a < 0) {
		a *= (-1);
		while (a > 0) {
			s = s + a % 10;
			a /= 10;
		}
		cout << "Сумма = " << s;
	}
	else
	if (a == 0) cout << "0";
	return 0;
}
