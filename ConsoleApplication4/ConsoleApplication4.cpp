//1
#include <iostream>
class Array {
private:
    int* arr;
    int size;
public:
    Array() : arr(nullptr), size(0) {}

    Array(int newSize) : size(newSize) {
        arr = new int[size];
    }

    Array(const Array& other) : size(other.size) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    void initializeArray(int newSize, int minValue, int maxValue) {
        delete[] arr;
        size = newSize;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = minValue + rand() % (maxValue - minValue + 1);
        }
    }

    void initializeArray(int minValue, int maxValue) {
        for (int i = 0; i < size; ++i) {
            arr[i] = minValue + rand() % (maxValue - minValue + 1);
        }
    }

    void initializeArray(int (*randomFunc)()) {
        for (int i = 0; i < size; ++i) {
            arr[i] = randomFunc();
        }
    }

    ~Array() {
        delete[] arr;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int customRandomFunction() {
    return rand() % 100;
}

int main() {
    Array a1(5);
    a1.initializeArray(1, 10);
    a1.print();

    Array a2;
    a2.initializeArray(10, 20);
    a2.print();

    Array a3(3);
    a3.initializeArray(customRandomFunction);
    a3.print();

    return 0;
}
//2
#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    int length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* inputStr) {
        length = std::strlen(inputStr);
        str = new char[length + 1];
        std::strcpy(str, inputStr);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    int getLength() const {
        return length;
    }

    bool equals(const String& other) const {
        return length == other.length && std::strcmp(str, other.str) == 0;
    }

    ~String() {
        delete[] str;
    }

    void print() const {
        if (str) {
            std::cout << str << std::endl;
        }
        else {
            std::cout << "Порожній рядок" << std::endl;
        }
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1;

    s1.print();
    s2.print();
    s3.print();

    if (s1.equals(s3)) {
        std::cout << "Рядки однакові" << std::endl;
    }
    else {
        std::cout << "Рядки різні" << std::endl;
    }

    return 0;
}
