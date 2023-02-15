#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int i = 5;
    int n = 0;
    while(N > i){
        n = n + (N / i);
        i = i * 5;
    }
    std::cout << n;

}
