#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

int findsmallestch(int A[], int startposition, int a) {
    int chposition = -1;
    for (int i = startposition; i < a; i++) {
        if (A[i] % 2 == 0 && A[i] != 0) {
            chposition = i;
            break;
        }
    }
    return chposition;
}
int findsmallestne(int A[], int startposition, int a) {
    int neposition = -1;
    for (int i = startposition; i < a; i++) {
        if (A[i] % 2 == 1) {
            neposition = i;
            break;
        }
    }
    return neposition;
}

void sort(int A[], int a) {
    int n = -1;
    bool t;
    for (int i = 0; i < a; i++) {
        if (n == i && t == true) continue;
        else {
            n = i;
            t = false;
            int ch = findsmallestch(A, i, a);
            if (ch != -1) {
                swap(A[i], A[ch]);
                n++;
            }
            int ne = findsmallestne(A, n, a);
            if (ne != -1) {
                swap(A[n], A[ne]);
                t = true;
            }
        }

    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    int A[15], a = 15;

    //for (int i = 0; i < a; i++) cin >> A[i];

    for (int i = 0; i < a; i++)  A[i] = rand() % 10;
    for (int i = 0; i < a; i++) cout << A[i] << " ";
    cout << '\n';

    sort(A, a);

    for (int i = 0; i < a; i++) cout << A[i] << " ";

    return 0;
}