#include <iostream>
#include <cstdlib>
#include <cerrno>

using namespace std;

void main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    cout << endl;
    for (int i = 0; i < argc; i++) cout << argv[i] << endl;

    char* end;
    errno = 0;
    double x = strtod(argv[1], &end);
    cout << x;
    errno = 0;
    int t = strtol(argv[2], &end, 10);
    cout << endl << t << '\n';
    if (errno == ERANGE) {
        cout << "Переполнение или недополнение при преобразовании." << endl;
    }
    else if (*end != '\0') {
        cout << "Некорректный символ: " << *end << endl;
    }
    else 
    {

        double e, s = 0, slag = 0, z = 1;
        if (abs(x) < 1) {
            slag = x;
            s = x;
            e = pow(10, (double)(-t));
            while (abs(slag) > e) {
                slag *= ((x * x) * z) / (z + 2);
                s += slag;
                z += 2;
            }
            cout << s * 2 << '\n';
            cout << log((1 + x) / (1 - x)) << "\n";
        }
        else cout << "модуль х должен быть меньше 1\n";
        system("pause");
    }
}
