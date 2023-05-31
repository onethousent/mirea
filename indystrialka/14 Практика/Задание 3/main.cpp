#include <iostream>
#include <set>
#include "SetException.cpp"

using namespace std;

int main() {
    try {
        set<int> mySet;
        mySet.insert(1);
        mySet.insert(2);
        mySet.insert(3);

        int element;
        cout << "Введите элемент для поиска: ";
        cin >> element;

        if (mySet.empty()) {
            throw SetException();
        }

        if (mySet.count(element) > 0) {
            cout << "Элемент найден!" << endl;
        }
        else {
            cout << "Элемент не найден!" << endl;
        }
    }
    catch (const SetException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
