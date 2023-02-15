#include <iostream>

int my_power(int base, int power)
{
    int answer = 1;
    for(int i =0; i<power; i++){
        answer = answer*base;
    }
    return answer;
}

int main() {
    int base;
    std::cin >> base; 
    int power;
    std::cin >> power; 
    std::cout << my_power(base, power);
}