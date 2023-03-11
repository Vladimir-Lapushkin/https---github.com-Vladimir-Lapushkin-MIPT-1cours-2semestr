#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
int number_of_swaps = 0;
void backward_step(int array[], unsigned const begin_index, unsigned const end_index, unsigned const step) {
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


void forward_step(int array[], unsigned const begin_index, unsigned const end_index, unsigned const step) {
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

void step_sort(int array[], unsigned const begin_index, unsigned const end_index, unsigned const step) {
    unsigned left = (begin_index/step)*step, right = (end_index/step)*step;
    while (left <= right) {
        forward_step(array, left, right, step);
        right=right-step;
        backward_step(array, right, left, step);
        left=left+step;
    }
    return;
}

void sort(int array[], unsigned const array_size) {
    step_sort(array, 0, array_size, 2);
    step_sort(array, 0, array_size, 1);
    return;
}
int main(){
    double t1 = 0;
    unsigned seed = 1001;
    for(int m = 100; m<2100; m += 100){
        int array[m];
        for(int i = 0; i < m; i++){
            array[i] = rand();
        }
        sort(array, m); 
        std::cout << number_of_swaps << std::endl;
        int number_of_swaps = 0;
    }
    return 0;
}
