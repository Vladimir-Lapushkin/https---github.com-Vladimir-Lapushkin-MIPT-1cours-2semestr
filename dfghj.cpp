
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int numbers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    while(N > 0){
        numbers[i] = N % 10;
        i=i+1;
        N = N / 10;
    }
    std::string condition = "YES";
    for(int j = 0; j < i / 2 + 1; j++){
        if (numbers[i-1-j]!=numbers[j]){
            condition = "NO";
        }
    }
    std::cout << condition;
}