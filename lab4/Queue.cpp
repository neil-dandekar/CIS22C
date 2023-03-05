// NAME BLOCK
// Lab:  03
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 03 is to demonstrate the List (LinkedList), Stack, 
// and Queue ADTs in OOP programming.
///////////////////////////////////////////////////////////////////////////

// MODIFIED FOR LAB 4:
// * Lines 13, 14, 68: Added header guard

#include "Currency.cpp"
#include "SinglyLinkedList.cpp"
#ifndef QUEUE // Header guard
#define QUEUE // Header guard

class Queue: private SinglyLinkedList {
    public:
    // CONSTRUCTORS
    Queue(): SinglyLinkedList() {}
    Queue(Currency* curr): SinglyLinkedList(curr) {}

    // DESTRUCTOR
    ~Queue() {}

    // INSTANCE METHODS
    void enqueue(Currency* curr) {
    // PURPOSE:  Adds Currency object to the queue.
    // PRE:    - Method must be called using class instance.
    // POST:   - The Currency object is added to the queue.
    // RETURN: - Nothing is returned.
        SinglyLinkedList::addCurrency(curr, countCurrency());
    }

    Currency* dequeue() {
    // PURPOSE:  Removes Currency object from the queue.
    // PRE:    - Method must be called using class instance.
    // POST:   - The Currency object is removed from the queue.
    // RETURN: - The removed Currency is returned.
        return SinglyLinkedList::removeCurrency(0);
    }

    Currency* peekFront() {
    // PURPOSE:  Returns the Currency at the front of the queue.
    // PRE:    - Method must be called using class instance.
    // POST:   - Nothing is changed.
    // RETURN: - The front Currency object is returned.
        return SinglyLinkedList::getCurrency(0);
    }

    Currency* peekRear() {
    // PURPOSE:  Returns the Currency at the rear of the queue.
    // PRE:    - Method must be called using class instance.
    // POST:   - Nothing is changed.
    // RETURN: - The rear Currency object is returned.
        return SinglyLinkedList::getCurrency(countCurrency()-1);
    }

    void printQueue() {
    // PURPOSE:  Prints the queue.
    // PRE:    - Method must be called using class instance.
    // POST:   - The queue contents are printed.
    // RETURN: - Nothing is returned.
        SinglyLinkedList::printList();
    }
};

// Header guard:
#endif // QUEUE