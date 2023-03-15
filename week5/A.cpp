#include <iostream>

int main() {
    double* ptr;
    ptr = new double(0.0);
    std::cout << ptr << " " << *ptr << "\n";
    std::cout << ptr - 3 << " " << *(ptr - 3) << "\n";
    std::cout << ptr + 5 << " " << *(ptr + 5) << "\n";
}
