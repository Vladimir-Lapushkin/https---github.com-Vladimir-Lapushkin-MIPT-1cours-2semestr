#include <iostream>
#include <random>

void backward_step(unsigned array[], unsigned const begin_index, unsigned const end_index) {
    for (unsigned i = begin_index; i > end_index; i--) {
        if (array[i - 1] > array[i]) {
            int variable = array[i-1];
            array[i-1]=array[i];
            array[i]=variable;

        }
    }
    return;
}


void forward_step(unsigned array[], unsigned const begin_index, unsigned const end_index) {
    for (unsigned i = begin_index; i < end_index; i++) {
        if (array[i + 1] < array[i]) {
            int variable = array[i+1];
            array[i+1]=array[i];
            array[i]=variable;
        }
    }
    return;
}

void sort(unsigned array[], unsigned const array_size) {
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
    unsigned array1[10] = {0, 3, 0, 5, 6, 5, 4, 6, 9, 9};
    unsigned array2[3] = {1, 3, 2};
    unsigned answer_array1[10] = {0, 0, 3, 4, 5, 5, 6, 6, 9, 9};
    unsigned answer_array2[3] = {1, 2, 3};
    sort(array1, 9);
    sort(array2, 2);
    int marker = 0;
    if ((array1[0] == answer_array1[0])and(array1[1] == answer_array1[1])and(array1[2] == answer_array1[2])and(array1[3] == answer_array1[3])and(array1[4] == answer_array1[4])and(array1[5] == answer_array1[5])and(array1[6] == answer_array1[6])and(array1[7] == answer_array1[7])and(array1[8] == answer_array1[8])and(array1[9] == answer_array1[9])) {
        marker++;
    } else {
        marker = 0;
    }
    if ((array2[0] == answer_array2[0])and(array2[1] == answer_array2[1])and(array2[2] == answer_array2[2])) {
        marker++;
    } else {
        marker = 0;
    }
    if (marker == 2) {
        std::cout << "OK";
    } else {
        std::cout << "Not OK";
    }
    return 0;
}
