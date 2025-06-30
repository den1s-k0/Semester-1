#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Функция для записи данных в файл
template<typename x>
void fwrite(const string& path, const x& text) {
    ofstream fout;
    fout.open(path, ofstream::app);
    if (!fout.is_open()) {
        cout << "Ошибка записи в файл" << endl;
    }
    else {
        fout << text;
    }
    fout.close();
}
// Функция для чтения из файла
string fread(const string& path) {
    ifstream fin;
    fin.open(path, ifstream::in);
    string A;
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Успешное открытие файла!" << endl;
        char ch;
        while (fin.get(ch)) {
            A += ch;
        }
    }
    fin.close();
    return A;
}
// Функция перевода строки
int* perstringvint(const string& str, int& len) {
    len = str.size();
    int* A = new int[len];
    for (int i = 0; i < len; i++) {
        A[i] = str[i] - '0';
    }
    return A;
}

int poisk(int* A, int a, int x, int kol, int position) {
    if(position == a) return kol;
    if (A[position] == x) kol++;
    if (position < a) poisk(A, a, x, kol, 1 + position);
}

int main()
{
    setlocale(LC_ALL, "ru");
    string path1 = "myFile.txt";
    string path2 = "OutPut.txt";
    int len, x;
    int* A = perstringvint(fread(path1), len);
    for (int i = 0; i < len; i++) cout << A[i] << ' ';
    cout << "\nВведите элемент для поиска ";
    cin >> x;
    fwrite(path2, "Ищем элемент х = ");
    fwrite(path2, x);
    fwrite(path2, '\n');
    int r = poisk(A, len, x, 0, 0);
    cout << "\nКоличество элемента " << x << " равно = " << r;
    fwrite(path2, "Количество элемента ");
    fwrite(path2, x);
    fwrite(path2, " равно = ");
    fwrite(path2, r);
    fwrite(path2, '\n');
    delete[] A;
    return 0;
}
