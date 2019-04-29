#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

#define STACK_MAX 100

template <class T>
class Stack {
    private:
        int tail = -1;
        T stack[STACK_MAX];

    public:
        Stack();
        T push(const T element);
        T peek();
        T pop();
        int size();
        bool empty();
        void print();

};

#endif