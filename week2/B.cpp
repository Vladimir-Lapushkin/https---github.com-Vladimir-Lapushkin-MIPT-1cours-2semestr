#include <iostream>

#ifndef N
#define N 5 // actual size of the array
#endif

void shiftRight(int n, int array[]){
    int l = array[n-1];
    for(int i = 0; i < n-1; i++){
        array[n-1-i] = array[n-2-i];
    }
    array[0]=l;
}

int main(){
    int n = N;
    int array[N]={0};
    for(int i = 0; i < N; i++){
        std::cin >> array[i];
    }
    shiftRight(N, array);
    for(int i = 0; i < N; i++){
        std::cout << array[i] << " ";
    }
}
