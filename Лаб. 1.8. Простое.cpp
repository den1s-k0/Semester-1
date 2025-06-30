#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a;
    bool b = true;
    cout << "Vvedite naturalnoe chislo ";
    cin >> a;
    if(a == 1) {
        cout << "Ne prostoe i ne sostavnoe";
    }
    else{
    for (int i = 2; i <= sqrt(a); i++){
        if( a % i == 0){
            cout << "Sostavnoe";
            b = false;
            break;
        }
    }
    if( b == true){
        cout << "Prostoe";
    }
    }
    return 0;
}
