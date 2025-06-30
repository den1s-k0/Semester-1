#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, d;
    int c, a1, b1;
    cout << "Введите a и b ";
    cin >> a >> b;
    if (b == 0) cout << '\n' << " На 0 делить нельзя ";
    else {
        c = a / b;
        d = a - c * b;
        cout << '\n' << "Частное a / b = " << c;
        cout << '\n' << "Остаток a / b = " << d;
    }
    a1 = a;
    b1 = b;
    if (b > a) {
        if (a == 0) cout << '\n' << "На 0 делить нельзя ";
        else {
            c = b / a;
            d = b - c * a;
            cout << '\n' << "Частное b / a = " << c;
            cout << '\n' << "Остаток b / a = " << d;
        }
    }
    cout << '\n' << "Округление а " << round(a);
    cout << '\n' << "Округление b " << round(b);
    cout << '\n' << "Преобразование а в int " << a1;
    cout << '\n' << "Преобразование b в int " << b1;
}
