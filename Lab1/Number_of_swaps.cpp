#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

void backward_step(int array[], unsigned const begin_index, unsigned const end_index, unsigned const step, unsigned number_of_swaps) {
    for (unsigned i = begin_index; i > end_index; i=i-step) {
        if (array[i - step] > array[i]) {
            number_of_swaps++;
            int variable = array[i-step];
            array[i-step]=array[i];
            array[i]=variable;

        }
    }
    return;
}


void forward_step(int array[], unsigned const begin_index, unsigned const end_index, unsigned const step, unsigned number_of_swaps) {
    for (unsigned i = begin_index; i < end_index; i=i+step) {
        if (array[i + step] < array[i]) {
            number_of_swaps++;
            int variable = array[i+step];
            array[i+step]=array[i];
            array[i]=variable;
        }
    }
    return;
}

void step_sort(int array[], unsigned const begin_index, unsigned const end_index, unsigned const step, unsigned number_of_swaps) {
    unsigned left = (begin_index/step)*step, right = (end_index/step)*step;
    while (left <= right) {
        forward_step(array, left, right, step, number_of_swaps);
        right=right-step;
        backward_step(array, right, left, step, number_of_swaps);
        left=left+step;
    }
    return;
}

void sort(int array[], unsigned const array_size, unsigned number_of_swaps) {
    unsigned number_of_swaps = 0;
    step_sort(array, 0, array_size, 2, number_of_swaps);
    step_sort(array, 0, array_size, 1, number_of_swaps);
    std::cout << number_of_swaps << std::endl;
    return;
}
int main(){
    double t1 = 0;
    unsigned seed = 1001;
    int s_count = 100;
    for (int m = 100; m<2100; m += 100){
        int array[m];
        for (int i = 0; i < m; i++){
            array[i] = rand();
        } 
        sort(array, m, 0);
    }

    return 0;
}
