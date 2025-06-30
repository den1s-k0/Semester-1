#include <iostream>

using namespace std;

int main()
{
    cout << "Vvedite chislo ";
    int a, b = 0, c;
    cin >> a;
    if( a < 0 ) a *= (-1);
    c = a;
    while(a > 0){
        b = (b * 10) + (a % 10) ;
        a /= 10;
    }
    if(b == c)
        cout << "Chislo palindrom";
    else
        cout << "Chislo ne palindrom";
    return 0;
}
