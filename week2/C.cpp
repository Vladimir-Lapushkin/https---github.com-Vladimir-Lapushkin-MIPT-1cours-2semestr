#include <iostream>

#ifndef N
#define N 5 // actual size of the array
#endif

void shiftRight_1(int n, int array[]){
    int l = array[n-1];
    for(int i = 0; i < n-1; i++){
        array[n-1-i] = array[n-2-i];
    }
    array[0]=l;
}

void shiftRight(int n, int array[], int k){
    for(int i = 0; i < k; i++){
        shiftRight_1(n, array);
    }
}

int main(){
    int n = N;
    int array[N]={0};
    int k;
    std::cin >> k;
    for(int i = 0; i < N; i++){
        std::cin >> array[i];
    }
    shiftRight(N, array, k);
    for(int i = 0; i < N; i++){
        std::cout << array[i] << " ";
    }
}
