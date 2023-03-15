#include <iostream>

bool reserve_memory(size_t N, int *dst) {
    if (dst == nullptr) {
        dst = new int[N];
        return true;
    } else {
        return false;
    }
}

void free_memory(const int* ptr) {
    delete[] ptr;
}

int main() {
    int* ptr = nullptr;
    size_t N = 0;
    std::cin >> N;
    std::cout << reserve_memory(N, ptr)<<std::endl;
    free_memory(ptr);
    return 0;
}
