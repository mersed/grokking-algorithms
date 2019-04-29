#include "Stack.h"

template <class T>
Stack<T>::Stack() {}

// Pushes the element onto the stack. Element is also returned.
template <class T>
T Stack<T>::push(const T element) {
    if(STACK_MAX < this->tail) {
        throw "Stack overflow!";
    }

    this->tail++;
    this->stack[this->tail] = element;
    return element;
}


template <class T>
T Stack<T>::peek() {
    return this->stack[this->tail];
}


template <class T>
T Stack<T>::pop() {
    if(this->tail < 0) {
        throw "Stack undeflow. No elements in stack!";
    }
    this->tail--;
    return this->stack[this->tail+1];
}


// Returns number of elements in stack
template <class T>
int Stack<T>::size() {
    return this->tail + 1;
}


// Returns true if stack is empty or false if its not
template <class T>
bool Stack<T>::empty() {
    return (this->tail > -1) ? false : true;
}


// Print all elements in stack
template <class T>
void Stack<T>::print() {
    for(int i=0; i<=this->tail - 1; i++) {
        cout << this->stack[i] << ",";
    }
    if(this->tail > -1) {
        cout << this->stack[this->tail] << endl;
    }
}