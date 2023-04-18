#include <iostream>

using namespace std;
class DynamicArray {
private:
    int size;
    float* array;

public:
    DynamicArray(int size) {
        this->size = size;
        array = new float[size];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void fillArray() {
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                array[i] = i - 1.9;
            }
            else {
                array[i] = i;
            }
        }
    }

    void reverseArray() {
        for (int i = 0; i < size / 2; i++) {
            float temp = array[i];
            array[i] = array[size - 1 - i];
            array[size - 1 - i] = temp;
        }
    }

    void printArray() {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

void processArray(DynamicArray* arr) {
    arr->fillArray();
    cout << "Original ";
    arr->printArray();

    arr->reverseArray();
    cout << "Reversed ";
    arr->printArray();
}

int main() {
    int size = 14;
    DynamicArray* arr = new DynamicArray(size);
    processArray(arr);

    delete arr;
    return 0;
}
