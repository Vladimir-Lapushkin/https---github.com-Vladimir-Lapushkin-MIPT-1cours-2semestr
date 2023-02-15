#include <iostream>

int main() {
    int N;
    std::cin >> N;
    if(N % 400 == 0){
        std::cout << "YES";
    } else{
        if(N % 100 == 0){
            std::cout << "NO";
        } else{
            if(N % 4 == 0){
                std::cout << "YES";
            }
        }
    }
    
}