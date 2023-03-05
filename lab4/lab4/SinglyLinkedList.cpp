// NAME BLOCK
// Lab:  03
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 03 is to demonstrate the List (LinkedList), Stack, 
// and Queue ADTs in OOP programming.
///////////////////////////////////////////////////////////////////////////

// MODIFIED FOR LAB 4:
// * Line 206: printList() method

#include <iostream>
#include "Currency.cpp"
#include "Krone.cpp"
#include "LinkNode.cpp"

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

class SinglyLinkedList {
    private:
    int count;
    LinkNode* start;
    LinkNode* end;

    public:
    // CONSTRUCTORS
    SinglyLinkedList() {
        this->count = 0;
        this->start = nullptr;
        this->end = nullptr;
    }

    SinglyLinkedList(Currency* curr) {
        LinkNode* n = new LinkNode(curr);
        this->count = 1;
        this->start = n;
        this->end = n;
    }

    // DESTRUCTOR
    ~SinglyLinkedList() {};

    // GETTER METHODS
    // PURPOSE:  These methods return information about the object to the
    //           caller.
    // PRE:    - Method must be called using class instance.
    // POST:   - Nothing is changed
    // RETURN: - Returns the specified information.
    LinkNode* getStart() {
        return this->start;
    }
    LinkNode* getEnd() {
        return this->end;
    }

    // INSTANCE METHODS
    void addCurrency(Currency* curr, int index) {
    // PURPOSE:  Adds Currency object to SinglyLinkedList at a specified index.
    // PRE:    - curr: a pointer to a Currency object.
    //         - index: an integer greater than or equal to 0 and less than
    //           count representing the index to be added at.
    // POST:   - The Currency object will be inserted into SinglyLinkedList at
    //           the specified index.
    // RETURN: - Nothing is returned.

        LinkNode* n = new LinkNode(curr); // New node to be inserted.

        // Inserting node to empty list.
        if(isListEmpty()) {
            if(index != 0) return; // Return if index is not the start;
            this->start = n;
            this->end = n;
        }

        // Inserting node at the start.
        else if(index == 0) {
            n->next = this->start;
            this->start = n;
        }

        // Inserting node at the end.
        else if(index == count) {
            this->end->next = n;
            this->end = n;
        }

        // Inserting node in the middle.
        else {
            LinkNode* temp = start;
            for(int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }

        // Increase list length by 1.
        this->count++;
    }

    Currency* removeCurrency(Currency* curr) {
    // PURPOSE:  Removes the specified Currency object from SinglyLinkedList.
    // PRE:    - curr: a pointer to a Currency object.
    // POST:   - The Currency object will be removed from SinglyLinkedList.
    // RETURN: - A copy of the removed object is returned.
    //         - Returns nullptr if the list is empty.
        if(isListEmpty()) return nullptr;

        LinkNode* temp = start;

        int index = 0;
        while(!(curr->isEqual( *(temp->data) ))) {
            temp = temp->next;
            index++;
        }
        return removeCurrency(index);
    }
   
    Currency* removeCurrency(int index) {
    // PURPOSE:  Removes a Currency object from SinglyLinkedList at a specified
    //           index.
    // PRE:    - index: an integer greater than or equal to 0 and less than
    //           count representing the index to get from.
    // POST:   - The Currency object will be removed from SinglyLinkedList.
    // RETURN: - A copy of the removed object is returned.
    //         - Returns nullptr if the list is empty.
        if(isListEmpty()) return nullptr;

        LinkNode* temp = start;
        Currency* copy = nullptr;

        // Removing node at the start.
        if(index == 0) {
            start = temp->next;
            copy = temp->data;
        }

        // Removing node in the middle or end.
        else {
            for(int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            copy = temp->next->data;

            // If node is at the end.
            if(index == count - 1) {
                temp->next = nullptr;
                end = temp;
                
            }
            // If node is in the middle.
            else {
                temp->next = temp->next->next;
            }
        }

        // Decrease list length by 1.
        this->count--;
        return copy;
    }

    int findCurrency(Currency* curr) {
    // PURPOSE:  Finds specified Currency object in SinglyLinkedList.
    // PRE:    - curr: a pointer to a Currency object.
    // POST:   - Nothing is changed.
    // RETURN: - The index of the Currency object is returned.
    //         - Returns -1 if the list is empty or object not found.
        if(isListEmpty()) return -1;
        LinkNode* temp = start;
        int index = 0;

        while( !(curr->isEqual(*(temp->data))) ) {
            temp = temp->next;
            index++;
            if(index > count - 1) return -1;
        }
        return index;
    }

    Currency* getCurrency(int index) {
    // PURPOSE:  Returns a Currency object from SinglyLinkedList at a specified
    //           index.
    // PRE:    - index: an integer greater than or equal to 0 and less than
    //           count representing the index to get from.
    // POST:   - Nothing is changed.
    // RETURN: - A copy of the Currency object is returned.
    //         - Returns nullptr if the list is empty.
        if(isListEmpty()) return nullptr;
        LinkNode* temp = start;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        Currency* copy = temp->data;
        return copy;
    }

    // MODIFIED - added 'std::cout' due to change in print method in Currency.cpp
    void printList() {
    // PURPOSE:  Prints the SinglyLinkedList.
    // PRE:    - Must be called on a SinglyLinkedList instance.
    // POST:   - Nothing is changed.
    // RETURN: - Nothing is returned.
        if(isListEmpty()) return; // Return if list is empty.
        LinkNode* temp = start;
        for (int i = 0; i < count; i++) {
            temp->data->print(std::cout); // MODIFIED for file output
            std::cout << "\t";
            temp = temp->next;
        }
    }

    bool isListEmpty() {
    // PURPOSE:  Checks if the list is empty.
    // PRE:    - Must be called on a SinglyLinkedList instance.
    // POST:   - Nothing is changed.
    // RETURN: - Returns true if list is empty (count is 0).
    //         - Returns false if list is not empty (count is not 0).
        return this->count == 0;
    }

    int countCurrency() {
    // PURPOSE:  Returns the count of the SinglyLinkedList.
    // PRE:    - Must be called on a SinglyLinkedList instance.
    // POST:   - The list contents are printed.
    // RETURN: - The integer count is returned.
        return count;
    }
};

#endif // SINGLY_LINKED_LIST