/*
Problem

Reverse a singly linked list.

1 → 2 → 3 → 4

Output

4 → 3 → 2 → 1
*/

#include <iostream>

class Node{

    public:
        int value{};
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(int ival){
            value = ival;
        }
        Node(int ival, Node* n){
            value = ival;
            next = n;
        }   
};

class LinkedList{
    public:
        Node* head = nullptr;
        Node* tail = nullptr;
        void AddNode(Node* n){
            if(!head){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                n->prev = tail;
                tail = n;
                tail->next = nullptr;
            }
        }
        void reverse(){
            // 2 - > 1 -> 2 -> 3 -> 4
            // nullptr <- 1 <- 2
            Node* n = head;
            while(n){
                Node* nelm = n->next;
                std::swap(n->prev, n->next);
                n = nelm;
            }
            std::swap(head, tail);
        }
        void AddNewNode(int ival){
             Node* n = new Node(ival);
            if(!head){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
                tail->next = nullptr;
            }
        }
};

int main(){
    std::cout << "HELLO WORLD\n";
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);
    LinkedList LL;
    LL.AddNode(&a);
    LL.AddNode(&b);
    LL.AddNode(&c);
    LL.AddNode(&d);

    LL.reverse();
    // 1 -> 2 -> 3 -> 4
   
    return 0;
}