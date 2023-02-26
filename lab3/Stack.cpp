// NAME BLOCK
// Lab:  03
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 03 is to demonstrate the List (LinkedList), Stack, 
// and Queue ADTs in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include "Currency.cpp"
#include "SinglyLinkedList.cpp"

class Stack: private SinglyLinkedList {
    public:
    // CONSTRUCTORS
    Stack(): SinglyLinkedList() {}
    Stack(Currency* curr): SinglyLinkedList(curr) {}

    // DESTRUCTOR
    ~Stack() {}
    
    // INSTANCE METHODS
    void push(Currency* curr) {
    // PURPOSE:  Adds Currency object to the top of the stack.
    // PRE:    - Method must be called using class instance.
    // POST:   - The Currency object is added to the top of the stack.
    // RETURN: - Nothing is returned.
        SinglyLinkedList::addCurrency(curr, 0);
    }

    Currency* pop() {
    // PURPOSE:  Removes Currency object from the top of the stack.
    // PRE:    - Method must be called using class instance.
    // POST:   - The Currency object is removed from the top of the stack.
    // RETURN: - The removed Currency is returned.
        return SinglyLinkedList::removeCurrency(0);
    }
    
    Currency* peek() {
    // PURPOSE:  Returns the Currency at the top of the stack.
    // PRE:    - Method must be called using class instance.
    // POST:   - Nothing is changed.
    // RETURN: - The top Currency object is returned.
        return SinglyLinkedList::getCurrency(0);
    }
    
    void printStack() {
    // PURPOSE:  Prints the stack.
    // PRE:    - Method must be called using class instance.
    // POST:   - The stack contents are printed.
    // RETURN: - Nothing is returned.
        SinglyLinkedList::printList();
    }
};