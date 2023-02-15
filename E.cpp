#include <iostream>

int recursive_power(int base, int power)
{
    if(power == 1){
        return base;
    }
    else{
        return recursive_power(base, power - 1)*base;
    }
}

int main() {
    int base;
    std::cin >> base; 
    int power;
    std::cin >> power; 
    std::cout << recursive_power(base, power);
}