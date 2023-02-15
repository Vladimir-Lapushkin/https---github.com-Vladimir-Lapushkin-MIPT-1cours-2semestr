#include <iostream>


int main() {
    int N;
    std::cin >> N; 
    int MAX = 0;
    int MIN = 0;
    int x = 0;
    int y;
    int z;
    std::cin >> y;
    std::cin >> z;
    for(int i = 0; i<N-2; i++){
        x = y;
        y = z;
        std::cin >> z;
        if((y-x)*(y-z)>0){
            if(y>x){
                MAX = MAX + 1;
            }else{
                MIN = MIN + 1;
            }
        }

    }
    if(MIN > MAX){
        std::cout <<"MIN";
    }
    if(MIN < MAX){
        std::cout <<"MAX";
    }
    if(MIN == MAX){
        std::cout <<"EQUAL";
    }
}