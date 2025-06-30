#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x, e, s = 0, slag = 0, z = 1 ;
    int t;
    cout << "Введите х и t ";
    cin >> x >> t;
    if (abs(x) < 1) {
        slag = x;
        s = x;
        e = pow(10, (double)(-t));
        while (abs(slag) > e) {
            slag *= ((x * x) * z) / (z + 2);
            s += slag;
            z += 2;
        }

        cout << '\n' << s * 2;
        cout << '\n' << log((1 + x) / (1 - x));
    }
    else cout << "модуль х должен быть меньше 1";
    return 0;
}