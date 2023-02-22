#include <iostream>

#ifndef N
#define N 3 // actual size of the array
#endif

void reverseArray(int n, int array[]){
    for(int i = 0; i < n/2; i++){
        int l = array[i];
        array[i] = array[n-1-i];
        array[n-1-i] = l;
    }
}

int main(){
    int n = N;
    int array[N]={0};
    for(int i = 0; i < N; i++){
        std::cin >> array[i];
    }
    reverseArray(N, array);
    for(int i = 0; i < N; i++){
        std::cout << array[i] << " ";
    }
}
