#include <iostream>
#include <Windows.h>
#include <time.h>
#include <algorithm>

using namespace std;

void vvod(char*& A, int& a) {
    if (a <= 0) { 
        cout << "Error"; 
        exit(0);
    }
    A = new char[a];
    for (int i = 0; i < a; i++)
        A[i] = rand() % 96 + 31;
        //A[i] = rand() % 127;
}
void vivod(char A[], int a) {
    for (int i = 0; i < a; i++) cout << "<" << A[i] << "> " << static_cast<int>(A[i]) << "   ";;
    cout << '\n';
}

char naib(char A[], int a) {
    char n = 0;
    for (int i = 0; i < a; i++) {
        if (A[i] > n) n = A[i];
    }
    return n;
}

void podsc(char A[], int a) {
    int* B;
    int t = 0, k = 0, l;
    l = naib(A, a) + 1;
    B = new int[l] {};
    for (int i = 0; i < a; i++) B[A[i]]++;
    for (int i = 0; i < l; i++) {
        k = t;
        if (B[i] > 0) {
            for (int j = k; j < a; j++) {
                A[j] = i;
                t++;
                B[i]--;
                if (B[i] == 0) break;
            }
        }
    }
}

void vstavka(char A[], int a) {
    int x;
    for (int i = 1; i < a; i++) {
        for (int j = i; j > 0; j--) {
            if (A[j] < A[j - 1]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
            }
            else break;
        }
    }
}

int comp_char(const void* e1, const void* e2)
{
    return (*(char*)e2 - *(char*)e1);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    int a;
    char* s;
    char b;
    char* A = nullptr;
    cout << " Введите размер массива ";
    cin >> a;
    vvod(A, a);
    cout << "Начальный массив" << '\n';
    vivod(A, a);
    cout << '\n' << "Сортировка подсчетом" << '\n';
    podsc(A, a);
    vivod(A, a);
    cout << '\n' << "Сортировка вставкой" << '\n';
    vstavka(A, a);
    vivod(A, a);
    cout << '\n' << "Сортировка sort" << '\n';
    sort(A, A+a);
    vivod(A, a);
    cout << '\n' << "Сортировка qsort" << '\n';
    qsort(A, a, sizeof(char), comp_char);
    vivod(A, a);
    cout << "Введите элемент для поиска \n";
    cin >> b;
    if (!(s = (char*)bsearch(&b, A, a, sizeof(char), (int(*)(const void*, const void*))comp_char)))
        cout << "Таких элементов нет\n";
    else
        cout << "Индекс такого же элемента " << s - A + 1 << '\n';

    return 0;
}
