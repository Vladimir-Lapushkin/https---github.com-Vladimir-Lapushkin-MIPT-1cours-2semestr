#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    for(int i = 0; i < N; i++){
        x = y;
        std::cin >> y;
        if(x < y){
            a = a + 1;
        }
        if(x > y){
            b = b + 1;
        }
    }
    if(a > b){
        std::cout << "MAX";
    }
    if(a < b){
        std::cout << "MIN";
    }
}
