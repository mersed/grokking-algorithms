#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstddef>

using namespace std;

template <class T>
class LinkedList {
    public:
        struct node {
            T data;
            node* next;
        };

        LinkedList();
        bool add(const T item);
        bool add(const unsigned int index, const T item);
        bool addFirst(const T item);
        LinkedList<T>::node* getFirst();
        void removeFirst();
        void removeLast();
        void remove(const unsigned int index);
        void clear();
        unsigned int size();
        void set(const unsigned int index, const T val);
        ~LinkedList();
        // bool removeByVal(T val) // Remove all elements from linked list with specific value. Returns true if at least one element is removed, false othervise
        // bool removeByValFirstOccurance(T val) // Remove first element with specific value from the list. Returns true if element was found and removed, false othervise.
        // bool removeByValLastOccurance(T val)
        // T getLast();
        // T get(const unsigned int index);
        // T pollFirst(); //It retrieves and removes the first element of a list.
        // T pollLast();  //It retrieves and removes the last element of a list, or returns null if a list is empty.
        // T[] toArray();
        // int indexOf(const T val) --- It is used to return the index in a list of the first occurrence of the specified element, or -1 if the list does not contain any element.
        // bool contains(const T val) // It is used to return true if a list contains a specified element.
        void print();

    private:
        node* head;
        node* tail;
};


// Iterator<E> descendingIterator() --- It is used to return an iterator over the elements in a deque in reverse sequential order.
// int lastIndexOf(Object o) --- It is used to return the index in a list of the last occurrence of the specified element, or -1 if the list does not contain any element.
// ListIterator<E> listIterator(int index) --- It is used to return a list-iterator of the elements in proper sequence, starting at the specified position in the list.
// <T> T[] toArray(T[] a) --- It returns an array containing all the elements in the proper sequence (from first to the last element); the runtime type of the returned array is that of the specified array.



// Just an other way of dealing with templates and separated implementation with classes
#include "LinkedList.cpp"

#endif