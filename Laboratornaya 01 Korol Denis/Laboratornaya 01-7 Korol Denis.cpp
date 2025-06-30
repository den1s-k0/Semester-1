#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, d;
    double b, c;
    cout << "Vvedite chislo i stepen ";
    cin >> a >> b;
    d = b;
    if(a == 0 && b == 0){
        cout << "ne imeet smisla";
    }
    else
    if(a == 0 && b < 0){
        cout << "Na 0 delit nelza";
    }
    else
    if(a < 0 && b - d != 0){
        cout << "Nelza vozvesti v etu stepen";
    }
    else {
        c = pow(a,b);
        cout << c;
    }
    return 0;
}
