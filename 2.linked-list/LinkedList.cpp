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

// Add element at the specific index in the list
template <class T>
bool LinkedList<T>::add(const int index, const T item) {
    /*LinkedList::node* temp = new LinkedList::node;
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
    */
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