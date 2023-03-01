#include <iostream>

#ifndef N
#define N 3
#endif

void rot(int massive_1[], int i){
    int t;
    int beg = 0;
    while (beg < i){
        t = massive_1[beg];
        massive_1[beg] = massive_1[i];
        massive_1[i] = t;
        beg = beg + 1;
        i = i - 1;
    }
}
  

int Maximal(int a[], int n)
{
    int mi;
    int i;
    for (mi = 0, i = 0; i < n; ++i){
        if (a[i] > a[mi]){
            mi = i;
        }
    }
    return mi;
}


void Sort(int (&a)[N]){
    for (int i = N; i > 1; i = i - 1){
        int mi = Maximal(a, i);
        if (mi != i - 1){
            rot(a, mi);
            rot(a, i - 1);
        }
    }
}
  

void print(int a[N]){
    for(int i = 0; i < N; i++){
        std::cout << a[i] << " ";
    }
}

void input(int (&a)[N]){
    int el;
    for(int i = 0; i < N; i++){
        std::cin >> el;
        a[i] = el;
    }
}

int main(){
    int a[N] = {0};
    input(a);
    Sort(a);
    print(a);
}
