#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

inline const char * const boolToString(bool b) {
  return b ? "true" : "false";
}

int main(int argc, char** argv) {
    Stack<char> stack;

    cout << "Checking is stack empty on empty stack: " << endl;
    cout << boolToString(stack.empty()) << endl;
    cout << "Size: " << stack.size() << endl;
    cout << "-----------------------------------------------------" << endl;

    cout << "stack.push('A') on empty list" << endl;
    stack.push('A');
    cout << "Size: " << stack.size() << endl;
    stack.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "Checking is stack empty on stack with one element: " << endl;
    cout << boolToString(stack.empty()) << endl;
    cout << "Size: " << stack.size() << endl;
    cout << "-----------------------------------------------------" << endl;

    cout << "stack.push('B'),stack.push('C'),stack.push('D') on empty list" << endl;
    stack.push('B');
    stack.push('C');
    stack.push('D');
    cout << "Size: " << stack.size() << endl;
    stack.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "stack.peek() " << endl;
    char elem = stack.peek();
    cout << elem << endl;
    cout << "-----------------------------------------------------" << endl;

    cout << "stack.pop()" << endl;
    char elem2 = stack.pop();
    cout << "Poped element: " << elem2 << endl;
    cout << "Size: " << stack.size() << endl;
    stack.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "stack.pop()" << endl;
    char elem3 = stack.pop();
    cout << "Poped element: " << elem3 << endl;
    cout << "Size: " << stack.size() << endl;
    stack.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "stack.pop()" << endl;
    char elem4 = stack.pop();
    cout << "Poped element: " << elem4 << endl;
    cout << "Size: " << stack.size() << endl;
    stack.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "stack.pop()" << endl;
    char elem5 = stack.pop();
    cout << "Poped element: " << elem5 << endl;
    cout << "Size: " << stack.size() << endl;
    cout << "-----------------------------------------------------" << endl;
}

