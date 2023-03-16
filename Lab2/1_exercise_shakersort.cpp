#include <iostream>
#include <random>

void backward_step(int array[], unsigned const begin_index, unsigned const end_index) {
    for (unsigned i = begin_index; i > end_index; i--) {
        if (array[i - 1] > array[i]) {
            int variable = array[i-1];
            array[i-1]=array[i];
            array[i]=variable;

        }
    }
    return;
}


void forward_step(int array[], unsigned const begin_index, unsigned const end_index) {
    for (unsigned i = begin_index; i < end_index; i++) {
        if (array[i + 1] < array[i]) {
            int variable = array[i+1];
            array[i+1]=array[i];
            array[i]=variable;
        }
    }
    return;
}

void sort(int array[], unsigned const array_size) {
    unsigned left = 0, right = array_size;
    while (left <= right) {
        forward_step(array, left, right);
        right--;
        backward_step(array, right, left);
        left++;
    }
    return;
}
int main() {
    int marker = 0;
    for (int m = 3; m<7; m += 1){
        int* array = new int[m];
        for (int i = 0; i < m+1; i++){
            array[i] = m-i;
        } 
        sort(array, m);
        int something = 0;
        for(int j = 0; j < m; j++){
            if(array[j]==j){
                something++;
            }
        }
        if(something == m){
            marker++;
        }
    }

    if (marker == 4) {
        std::cout << "OK";
    } else {
        std::cout << "Not OK";
    }
    return 0;
}
