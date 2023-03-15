#include <iostream>

int main() {
    int array[1000000]={1};
    int i = 0;
    std::cin >> array[0];
    while (array[i] != 0) { 
        ++i;
        std::cin >> array[i];
    }
    for (int j = 0; j < i - 1; ++j) { 
        std::cout << array[j] - array[j+1] << std::endl;
    }
}
