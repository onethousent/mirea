#include <iostream>
#include "Array.cpp"

using namespace std;

int main() {
    try {
        MyArray arr(5);
        cout << arr.getElement(2) << std::endl; // True
        cout << arr.getElement(6) << std::endl; // False
    }
    catch (const std::out_of_range& e) {
        cout << "Ошибка обращения к элементу массива: " << e.what() << endl;
    }
    return 0;
}
