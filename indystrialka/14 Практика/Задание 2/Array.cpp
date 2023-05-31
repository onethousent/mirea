#include <iostream>
#include <stdexcept>

using namespace std;

class MyArray {
private:
    int* data;
    int size;

public:
    MyArray(int size) {
        this->size = size;
        data = new int[size];
    }

    int getElement(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }
        return data[index];
    }
};
