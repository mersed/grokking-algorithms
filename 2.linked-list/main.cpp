#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv) {
    LinkedList<char> object;

    cout << "removeFirst(),removeLast(),set(),remove(0),remove(15) and clear() on empty list" << endl;
    object.removeFirst();
    object.removeLast();
    object.set(0, 'E');
    object.remove(0);
    object.remove(15);
    object.clear();
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;


    cout << "add('A') on empty list" << endl;
    object.add('A');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "removeFirst() on list with one element" << endl;
    object.removeFirst();
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "addFirst('A') on empty list" << endl;
    object.addFirst('A');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "removeLast() on list with one element" << endl;
    object.removeLast();
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "add('A') on empty list" << endl;
    object.add('A');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "remove(0) on list with one element" << endl;
    object.remove(0);
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "add('A'), add('B') on empty list" << endl;
    object.add('A');
    object.add('B');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "remove(1), remove(1), remove(0) on list with two elements" << endl;
    object.remove(1);
    object.remove(1);
    object.remove(0);
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "add('A'), add('B'), add('C'), add('D'), addFirst('0')" << endl;
    object.add('A');
    object.add('B');
    object.add('C');
    object.add('D');
    object.addFirst('0');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "add('E')" << endl;
    object.add('E');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "add(2, 'Z')" << endl;
    object.add(2, 'Z');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "add(6, 'O')" << endl;
    object.add(6, 'O');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "2 x removeFirst()" << endl;
    object.removeFirst();
    object.removeFirst();
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "2 x removeLast()" << endl;
    object.removeLast();
    object.removeLast();
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "set(0, 'A'), set(1, 'B'), set(2, 'C'), set(3, 'D'), set(4, 'E'), set(5, 'F')" << endl;
    object.set(0, 'A');
    object.set(1, 'B');
    object.set(2, 'C');
    object.set(3, 'D');
    object.set(4, 'E');
    object.set(5, 'F');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "add('E'), add('F')" << endl;
    object.add('E');
    object.add('F');
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "remove(5), remove(4), remove(0) on list with two elements" << endl;
    object.remove(5);
    object.remove(4);
    object.remove(0);
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;

    cout << "getFirst(), and writing its value" << endl;
    LinkedList<char>::node* head = object.getFirst();
    cout << "Value of head: " << head->data << endl;
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;


    cout << "clear()" << endl;
    object.clear();
    cout << "Size: " << object.size() << endl;
    object.print();
    cout << "-----------------------------------------------------" << endl;
}