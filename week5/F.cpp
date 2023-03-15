#include <iostream>

char* resize(const char* buf, size_t size, size_t new_size) {
    char* new_buf = new char[new_size];
    size_t min_size = std::min(size, new_size);
    for (size_t i = 0; i < min_size; ++i) {
        new_buf[i] = buf[i];
    }
    delete[] buf;
    return new_buf;
}

int main() {
    char* a = new char[10];
    std::cout << resize(a, 10, 10) << std::endl;
    return 0;
}
