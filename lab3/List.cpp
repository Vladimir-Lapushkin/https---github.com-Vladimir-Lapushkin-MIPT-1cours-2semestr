#include <iostream>

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

LinkedList* reverse_itr(LinkedList * const head){
    LinkedList* curr = head;
    LinkedList* temp = head->next;
    head->next = nullptr;
    while (temp != nullptr) {
        LinkedList* prev = curr;
        curr = temp;
        temp = curr->next;
        curr->next = prev;
    }
    return curr;
}

LinkedList* reverse_rec(LinkedList * const head){
    if (head->next != nullptr){
        LinkedList* temp = head->next;
        LinkedList* n = reverse_rec(temp);
        temp->next = head;
        head->next = nullptr;
        return n;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    LinkedList* first = insert_after(nullptr);
    first->data = 1;
    LinkedList* current = insert_after(first);
    current->data = 2;
    for (int i=3; i<8; i++) {
        current = insert_after(current);
        current->data = i;
    }
    
    current = insert_after(first->next->next->next->next);
    current->data = 15;
    
    current = first;
    while (nullptr != current){
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';
    
    remove_after(first->next->next->next->next);
    
    first = reverse_itr(first);
    current = first;
    while (nullptr != current){
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';
    
    first = reverse_rec(first);
    current = first;
    while (nullptr != current){
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';
    
    erase(first);
    
    return 0;
}
