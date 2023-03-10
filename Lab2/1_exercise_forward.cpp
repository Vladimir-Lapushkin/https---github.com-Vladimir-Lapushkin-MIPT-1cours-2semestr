#include <iostream>
#include <random>

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

int main() {
    int marker = 0;
    for (int m = 3; m<7; m += 1){
        int array[m];
        for (int i = 1; i < m+1; i++){
            array[i] = i-1;
        } 
        array[0] = m;
        forward_step(array, 0, m);
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
