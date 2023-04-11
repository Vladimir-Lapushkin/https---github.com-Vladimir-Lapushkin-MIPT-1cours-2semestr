#include <iostream>
#include <chrono>
#include <random>


struct LinkedList{
  LinkedList* next;
  int data;

 public:
  LinkedList() : next(nullptr), data(0) {}
  LinkedList(LinkedList* next, int value) : next(next), data(value) {}
  LinkedList(const LinkedList& list) : next(list.next), data(list.data) {}
};

LinkedList* insert_after(LinkedList * const current){
    if (current == nullptr){
        return new LinkedList(nullptr, 0);
    }
    LinkedList* new_node = new LinkedList(current->next, 0);
    current->next = new_node;
    return new_node;
}

LinkedList* remove_after(LinkedList * const current){
    if (nullptr == current || current->next == nullptr){
        return nullptr;
    }
    LinkedList* new_next = current->next->next;
    delete current->next;
    current->next = new_next;
    return current->next;
}


void erase(LinkedList * const head){
    while (head->next != nullptr) {
        head->next = remove_after(head);
    }
    delete head;
}


int iosif_list(int n, int m){
    if (m == 1){
        return n;
    }
    int size = n;
    LinkedList* first = insert_after(nullptr);
    first->data = 1;
    LinkedList* current = insert_after(first);
    current->data = 2;
    for (int i=3; i<=n; i++) {
        current = insert_after(current);
        current->data = i;
    }
    
    current->next = first;
    current = first;
    int i = 1;
    while (size>1) {
        if ((i+1)%m == 0){
            remove_after(current);
            size -= 1;
        }
        else{
            current = current->next;
        }
        i += 1;
    }
    int ans = current->data;
    delete current;
    return ans;
}



int iosif_mass(int n, int m){
    int* mass = new int [n+1];
    mass[0] = -1;
    for (int i = 1; i<=n; i++) {
        mass[i] = i;
    }
    
    int size = n;
    int i = 1;
    int num = 1;
    while (size>1) {
        if (num%m == 0){
            for (int j = i; j<=size; j++) {
                mass[j] = mass[j+1];
            }
            size -= 1;
        }
        else{
            i += 1;
        }
        
        if (i > size){
            i = 1;
        }
        
        if (num == m){
            num = 1;
        }
        else{
            num += 1;
        }
        
    }
    int ans = mass[1];
    delete[] mass;
    return ans;
}


double iosif_time(int(*iosif)(int n, int m), int n) {
    long long repeat = 100000;
    std::__1::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    for (int j = 1; j <= repeat; ++j) {
        iosif(n, 3);
    }
    std::__1::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::__1::chrono::milliseconds time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return ((time_span.count() + 0.0)/repeat);
}



int main(int argc, const char * argv[]) {
    for (int i = 1; i <= 300; i++){
        std::cout << i << ' ' << iosif_time(iosif_mass, i) << '\n';
    }
    
    return 0;
}
