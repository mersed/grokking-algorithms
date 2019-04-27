#include "LinkedList.h"

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


// Add element at the beggining of the list
template <class T>
bool LinkedList<T>::addFirst(const T item) {
    LinkedList::node* temp = new LinkedList::node;
    temp->data = item;
    temp->next = NULL;

    if(this->head == NULL) {
        this->head = temp;
        this->tail = temp;
        temp = NULL;
    }
    else {
        temp->next = this->head;
        this->head = temp;
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


// Remove first element in the list
template <class T>
void LinkedList<T>::removeFirst() {
    if(this->head == NULL) {
        return;
    }

    LinkedList::node* temp = new LinkedList::node;
    temp = this->head;
    this->head = this->head->next;
    delete temp;
}


// Remove last element in the list
template <class T>
void LinkedList<T>::removeLast() {
    if(this->tail == NULL) {
        return;
    }

    LinkedList::node* current = new LinkedList::node;
    LinkedList::node* previous = new LinkedList::node;
    current = this->head;
    previous = NULL;

    while(current->next != NULL) {
        previous = current;
        current = current->next;
    }

    delete current;
    if(previous != NULL) {
        this->tail = previous;
        this->tail->next = NULL;
    }
    else {
        this->head = NULL;
        this->tail = NULL;
    }
}


// Remove element at the specific index
template <class T>
void LinkedList<T>::remove(const unsigned int index) {
    // No elements, return
    if(this->head == NULL) {
        return;
    }

    // If we want to remove first element
    if(index == 0) {
        this->removeFirst();
        return;
    }

    // Deal with rest of the cases
    bool indexFound = false;
    unsigned int counter = 0;

    LinkedList::node* current = new LinkedList::node;
    LinkedList::node* previous = new LinkedList::node;
    current = this->head;
    previous = NULL;

    while(current != NULL) {
        if(counter == index) {
            indexFound = true;
            break;
        }

        previous = current;
        current = current->next;
        counter++;
    }

    if(indexFound) {
        // Removing last element
        if(current->next == NULL) {
            previous->next = NULL;
            this->tail = previous;
            delete current;
        }
        else {
            previous->next = current->next;
            delete current;
        }
    }
}


// Removes all elements from the list
template <class T>
void LinkedList<T>::clear() {
    LinkedList::node* temp = new LinkedList::node;
    temp = this->head;

    while(temp != NULL) {
        delete temp;
        temp = temp->next;
    }

    this->head = NULL;
    this->tail = NULL;
}


// Return size of the linked list
template <class T>
unsigned int LinkedList<T>::size() {
    int size = 0;
    LinkedList::node* temp = new LinkedList::node;
    temp = this->head;

    while(temp != NULL) {
        size++;
        temp = temp->next;
    }

    return size;
}


// Set value of element at specific index (to different value)
template <class T>
void LinkedList<T>::set(const unsigned int index, const T val) {
    bool indexFound = false;
    unsigned int counter = 0;
    LinkedList::node* temp = new LinkedList::node;
    temp = this->head;

    while(temp != NULL) {
        if(counter == index) {
            indexFound = true;
            break;
        }

        counter++;
        temp = temp->next;
    }

    if(indexFound) {
        temp->data = val;
    }
}


// Print whole linked list items separated by comma
template <class T>
void LinkedList<T>::print() {
    if(this->head == NULL) {
        cout << "--- Empty list ---";
    }

    LinkedList::node* temp = new LinkedList::node;
    temp = this->head;

    while(temp != NULL) {
        cout << temp->data << ",";
        temp = temp->next;
    }

    cout << endl;
    delete temp;
} 

template <class T>
LinkedList<T>::~LinkedList() {
    this->clear();
}