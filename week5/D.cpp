#include <iostream>

void input_array(int* ptr,size_t N) {
    for(size_t i = 0; i < N; ++i){
       std::cin >> *(ptr+i);
    }
}

void reverse(int* ptr,size_t N) {
    for (size_t i = 0; i < N / 2; ++i) {
        std::swap(ptr[i], ptr[N - 1 - i]);
    }
}

void print(const int* ptr,size_t N) {
    for(size_t i = 0; i < N; ++i){
       std::cout << *(ptr+i);
    }
}

int main() {
    int* ptr;
    size_t N = 0;
    std::cin >> N;
    ptr = new int[N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
}
