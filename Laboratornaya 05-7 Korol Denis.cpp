#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdio.h>

using namespace std;

unsigned int** rnd_matr(unsigned int** ma, int* n, int* m)
{
    int i, j;
    cout << "Введите размер а и b ";
    cin >> *n >> *m;
    if (*n < 0 || *m < 0) {
    cout << " Такого массива не существует";
    return ma;
    }
    else
    if (*n == 0 || *m == 0) { 
        cout << "Массив пустой"; 
        return ma;
    }
    else 
    if (*n > 0 && *m > 0) {
        ma = new unsigned int* [*n];
        for (i = 0; i < *n; i++)
            ma[i] = new unsigned int[*m];
        for (i = 0; i < *n; i++)
            for (j = 0; j < *m; j++)
                ma[i][j] = rand() % 1000;
        return ma;
    }
}
unsigned int** clean_matr(unsigned int** ma, int n, int m)
{
    int i, j;
    ma = new unsigned int* [n];
    for (i = 0; i < n; i++)
        ma[i] = new unsigned int[m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            ma[i][j] = 0;
    return ma;
}
void print_matr(unsigned int** ma, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ma[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
void delete_matr(unsigned int** ma, int n, int m)
{
    for (int i = 0; i < n; i++)
        delete[]ma[i];
    delete[]ma;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    int i, j, n, m;
    unsigned int** A = NULL;
    unsigned int** B = NULL;
    A = rnd_matr(A, &n, &m);
    if (A == NULL) return 0;
    else {
        B = clean_matr(B, n, m);
        print_matr(A, n, m);
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < m - 1; j++) {
                if (A[i + 1][j] > A[i - 1][j]) B[i][j] = A[i - 1][j];
                else B[i][j] = A[i + 1][j];
            }
        print_matr(B, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%4u ", B[i][j]);
            }
            printf("\n");
        }
        delete_matr(A, n, m);
        delete_matr(B, n, m);
        system("pause");
        return 0;
    }
}
