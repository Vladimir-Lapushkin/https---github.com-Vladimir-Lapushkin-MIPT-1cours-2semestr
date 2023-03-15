#include <iostream>

void print(size_t size, short* arr) {
    for(size_t i = 0; i < size; ++i){
       std::cout << *(arr+i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    short* arr;
    size_t size = 10;
    arr = new short[size];
    for(size_t i = 0; i < size; ++i){
       arr[i] = i; 
       std::cout << arr + i << " ";
    }
    std::cout << std::endl;
    print(size, arr);
    for(size_t i = 0; i < size; i += 2){
       *(arr + i) *= *(arr + i);
    }
    print(size, arr);
}
