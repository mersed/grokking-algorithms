#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv) {
    LinkedList<char> object;

    object.removeFirst();
    object.removeLast();
    object.print();

    object.add('A');
    object.print();

    object.removeFirst();
    object.print();

    object.addFirst('A');
    object.print();

    object.removeLast();
    object.print();

    object.add('A');
    object.add('B');
    object.add('C');
    object.add('D');
    object.addFirst('0');
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

    object.removeLast();
    object.removeLast();
    object.print();
}