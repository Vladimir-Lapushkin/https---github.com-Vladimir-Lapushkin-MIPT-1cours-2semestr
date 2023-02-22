#include <iostream>

#ifndef N
#define N 5 // actual size of the array
#endif

int array_negative[N]={0};
int array_positive[N]={0};

void moveNegativeToEnd(int n, int array[]){
    int positive = 0;
    int negative = 0;
    for(int i = 0; i < n-1; i++){
        if(array[i]>0){
            array_positive[positive]=array[i];
            positive = positive + 1;
        }else{
            array_negative[negative]=array[i];
            negative = negative + 1;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(i<positive){
            array[i]=array_positive[i];
        }else{
            array[i]=array_negative[i-positive];
        }
    }
}

int main(){
    int n = N;
    int array[N]={0};
    for(int i = 0; i < N; i++){
        std::cin >> array[i];
    }
    moveNegativeToEnd(N, array);
    for(int i = 0; i < N; i++){
        std::cout << array[i] << " ";
    }
}
