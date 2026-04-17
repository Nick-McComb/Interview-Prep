#include <iostream>
#include <cassert>
#include <array>

/*
1.2 Swapping two integers using pointers

Write a function:

void swap(int* a, int* b);

Constraint: do not use a temporary variable.

Hint: Use arithmetic operations or bitwise XOR.
*/

void swap(int* a, int* b){
    std::swap(*a, *b);
    return;
}

/*
1.3 Dynamic memory

Allocate an array of N integers dynamically and initialize it with 0…N-1. Then free it properly.

int* arr = ...;

Question: Why is it important to call delete[]?
*/
void allocate_array(int&& N){
    int* array = new int[N];
    for(int i = 0; i < N; ++i){
        array[i] = i;
    }

    delete[] array;
}




int main(){
    std::cout<<"Pointer Arithmetic Test\n";
    int a = 10;
    int* p = &a;
    *p += 5;
    assert(a==15);
    std::cout << "a: " << a << '\n';

    std::cout<<"Swapping Pointers\n";
    int b = 10;
    int c = 20;
    int* p1 = &b;
    int* p2 = &c;
    std::cout<< "p1: " <<*p1 << " p2: " << * p2 << '\n';
    swap(p1, p2);
    assert(*p1 == 20);
    assert(*p2 == 10);
    std::cout<< "p1: " <<*p1 << " p2: " << * p2 << '\n';

    std::cout<<"Allocating Array\n";
    allocate_array(6);
    allocate_array(10);


    return 0;
}