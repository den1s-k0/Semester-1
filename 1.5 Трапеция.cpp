#include <iostream>

using namespace std;

int main()
{
    int l , n;
    cout << "Vvedite dliny mensego osnovania i visoty trapecii " ;
    cin >> l >> n ;
    if(l <=0 || n <= 0) cout << "Dlina dolzna bit naturalnoi";
    else{
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < l ; j++){
            cout << '*';
        }
        l++;
        cout << '\n';
    }
    }
    return 0;
}
