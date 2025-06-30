#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

void printList(const list<int>& lst) {
    if (lst.empty()) {
        cout << "Список пуст\n";
    }
    else {
        copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

void addElement(list<int>& lst) {
    int value;
    cout << "Введите значение для добавления: ";
    cin >> value;
    lst.push_back(value);
}

void removeElement(list<int>& lst) {
    int value;
    cout << "Введите значение для удаления: ";
    cin >> value;
    lst.remove(value);
}

void spliceLists(list<int>& lst1, list<int>& lst2) {
    lst1.splice(lst1.end(), lst2);
}

void calculateProduct(const list<int>& lst) {
    if (lst.empty()) {
        cout << "Список пуст." << endl;
    }
    else {
        int product = accumulate(lst.begin(), lst.end(), 1, multiplies<int>());
        cout << "Произведение элементов: " << product << endl;
    }
}

void createMultimap() {
    multimap<int, int> Map;
    int number;
    cout << "Введите число элементов словаря: ";
    cin >> number;
    for (int i = 0; i < number; i++) {
        int key = rand() % 100 + 1;
        int value = rand() % 100 + 1;
        Map.insert(make_pair(key, value));
    }
    for(auto val : Map)
        cout << "Ключ: " << val.first << ", Значение: " << val.second << endl;
}

void main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    list<int> List1;
    list<int> List2 = { 10, 20, 30 };
    int choice;

    do {
        cout << "Меню:\n"
            << "1. Просмотреть состояние списка\n"
            << "2. Добавить элемент\n"
            << "3. Удалить элемент\n"
            << "4. Перемещение элементов из другого списка (splice)\n"
            << "5. Вычислить произведение элементов (accumulate)\n"
            << "6. Выход из программы\n"
            << "7. Записать multimap\n"
            << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printList(List1);
            system("pause");
            system("cls");
            break;
        case 2:
            addElement(List1);
            system("pause");
            system("cls");
            break;
        case 3:
            removeElement(List1);
            system("pause");
            system("cls");
            break;
        case 4:
            spliceLists(List1, List2);
            system("pause");
            system("cls");
            break;
        case 5:
            calculateProduct(List1);
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "Выход из программы " << endl;
            system("pause");
            system("cls");
            break;
        case 7:
            createMultimap();
            system("pause");
            system("cls");
            break;
        default:
            cout << "Нет такой операции " << endl;
            system("pause");
            system("cls");
        }
    } while (choice != 6);
}
