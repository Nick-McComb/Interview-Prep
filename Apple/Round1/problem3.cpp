/*
3. Detect Cycle in Linked List

Tests pointer reasoning.

Problem

Given a linked list, determine if it contains a cycle.

*/

#include <iostream>
#include <memory>

class Node{

    public:
        int value{};
        Node* next = nullptr;

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
                tail = n;
                tail->next = nullptr;
            }
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

bool cycle(LinkedList LL){
    Node * slow = LL.head; //4,5,7,9
    Node * fast = LL.head; //5,9,5,9
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){

    LinkedList LL;
    //Node F(4);
    //std::cout << F.value << std::endl;
    LL.AddNewNode(4);
    std::cout << "head " << LL.head << " tail " << LL.tail << '\n';
    //Node D(7);
    LL.AddNewNode(5);
    std::cout << "head " << LL.head << " tail " << LL.tail << '\n';
    LL.AddNewNode(7);
    std::cout << "head " << LL.head << " tail " << LL.tail << '\n';
    LL.AddNewNode(9);
    //LL.tail->next = LL.head;
    std::cout << "THIS IS " << cycle(LL) << std::endl;

    return 0;


}