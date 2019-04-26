#include "LinkedList.h"
#include <iostream>
#include <cstddef>

using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
}


// Add element at the end of the list
template <class T>
bool LinkedList<T>::add(const T item) {
    LinkedList::node* temp = new LinkedList::node;
    temp->data = item;
    temp->next = NULL;

    if(this->head == NULL) {
        this->head = temp;
        this->tail = temp;
        temp = NULL;
    }
    else {
        this->tail->next = temp;
        this->tail = temp;
    }

    return true;
}

/**
 * Add element at the specific index in the list.
 * If index is greather then total size of the list, the element
 * is added at the end of the list.
 */
template <class T>
bool LinkedList<T>::add(const unsigned int index, const T item) {
    // If its first element in the linked list
    if(this->head == NULL) {
        this->add(item);
        return true;
    }

    int counter = 0;
    LinkedList::node* newNode = new LinkedList::node;
    LinkedList::node* currentNode = new LinkedList::node;
    LinkedList::node* prevNode = new LinkedList::node;
    currentNode = this->head;

    while(currentNode != NULL && counter < index) {
        prevNode = currentNode;
        currentNode = currentNode->next;
        counter++;
    }

    if(currentNode == NULL) {
        this->add(item);
    }
    else {
        newNode->data = item;
        newNode->next = currentNode;
        prevNode->next = newNode;
    }

    return true;
}

// Print whole linked list items separated by comma
template <class T>
void LinkedList<T>::print() {
    LinkedList::node* temp = new LinkedList::node;
    temp = this->head;

    while(temp != NULL) {
        cout << temp->data << ",";
        temp = temp->next;
    }

    cout << endl;
    delete temp;
} 

/*IpV4::IpV4(const string ip) {
    if(this->isValid(ip)) {
        this->ip = ip;
    }
    else {
        throw string("Ip is invalid. Please insert correct ip and try again!");
    }
}

string IpV4::getIp() {
    return this->ip;
}

IpV4::IpV4(const IpV4& orig) {
}

IpV4::~IpV4() {
}
*/