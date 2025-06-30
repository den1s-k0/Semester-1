#include <iostream>

using namespace std;

int main()
{
    int a, b = 1;
    cout << "Vvedite naturalnoe chislo ";
    cin >> a;
    if(a < 0) cout << "Net factoriala otricatelnogo chisla";
    else{
    for (int i = 1; i <= a; i++ )
    {
        b *= i;
    }
    cout << "Factorial chisla = "<< b ;}
    return 0;
}
