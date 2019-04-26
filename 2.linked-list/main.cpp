#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv) {
    LinkedList<char> object;

    object.removeFirst();
    object.add('A');
    object.add('B');
    object.add('C');
    object.add('D');
    object.print();
    object.add('E');
    object.print();
    object.add(2, 'Z');
    object.print();
    object.add(6, 'O');
    object.print();
    object.removeFirst();
    object.removeFirst();
    object.print();
}

#include "LinkedList.cpp"