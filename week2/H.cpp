#include <iostream>

#ifndef N
#define N 5 // actual size of the array
#endif
#ifndef M
#define M 4 // actual size of the array
#endif

void print_transposed(int array[]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            std::cout << array[j*M+i];
        }
    std::cout << '\n';
    }
}


int main(){

    int array[N*M]={0};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
        std::cin >> array[i*M+j];
    }
    }

    print_transposed(array);
}
