
#include <iostream>
#include <Windows.h>

using namespace std;

int main()

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������� 2 ����� ";
	int a, b, c;
	cin >> a >> b;
	if (a < 0) {
		a *= (-1);
		cout << "����� 1 ������� �� ������" << endl;
	}
	if (b < 0) {
		b *= (-1);
		cout << "����� 2 ������� �� ������" << endl;
	}
	if (a == 0 || b == 0) { cout << "��� � ��� 0 �� ���������� "; }
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
		cout << "��� = " << a + b << '\n' << " ��� = " << (c / (a + b));
	}
	return 0;
}
