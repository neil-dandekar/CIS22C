// NAME BLOCK
// Lab:  03
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 03 is to demonstrate the List (LinkedList), Stack, 
// and Queue ADTs in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Currency.cpp"
#include "Krone.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "SinglyLinkedList.cpp"

using namespace std;

int main() {
    // Welcome message
    cout << "Welcome to Lab 3 - Lists, Stacks, and Queues\nCreated by Xi and Neil" << endl;
    
    // Temp array of Currency values
    double arr[20] = 
        {57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 
        77.77, 18.36, 543.21, 20.21, 345.67, 36.18, 
        48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 
        251.00, 151.00};

    // Create Currency array
    Currency* curr[20];
    for(int i = 0; i < 20; i++) {
        curr[i] = new Krone(arr[i]);
    }
    
    // Create SinglyLinkedList
    cout << "\nSINGLY_LINKED_LIST: " << endl;
    SinglyLinkedList list;
    for(int i = 0; i < 7; i++) {
        list.addCurrency(curr[i], 0);
    }
    list.printList();

    cout << "\n\nSinglyLinkedList search: " << endl;
    cout << "\tSearching for Kr 87.43: " << list.findCurrency(new Krone(87.43)) << endl;
    cout << "\tSearching for Kr 44.56: " << list.findCurrency(new Krone(44.56)) << endl;

    cout << "\nSinglyLinkedList remove:" << endl;
    cout << "\tRemove node \"Kr 111.22\"" << endl;
    cout << "\tRemove node at index 2" << endl;
    list.removeCurrency(new Krone(111.22));
    list.removeCurrency(2);
    list.printList();

    cout << "\n\nSinglyLinkedList add and remove:" << endl;
    cout << "\tAdd Currencies 9, 10, 11, 12 at index % 5" << endl;
    cout << "\tRemove Currency at index countCurrency() % 6" << endl;
    cout << "\tRemove Currency at index countCurrency() / 7" << endl;
    for(int i = 8; i < 12; i++) {
        list.addCurrency(curr[i], i % 5);
    }
    list.removeCurrency(list.countCurrency() % 6);
    list.removeCurrency(list.countCurrency() / 7);
    list.printList();

    // Create Stack
    cout << "\n\nSTACK: " << endl;
    Stack stack = Stack();
    for(int i = 13; i < 20; i++) {
        stack.push(curr[i]);
    }
    stack.printStack();

    cout << "\n\nStack peek: " << endl;
    stack.peek()->print();

    cout << "\n\nStack pop (x3): " << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.printStack();
 
    cout << "\n\nStack push and pop: " << endl;
    cout << "\tPush Currencies 1, 2, 3, 4, 5" << endl;
    cout << "\tPop (x2)" << endl;
    for(int i = 0; i < 5; i++) {
        stack.push(curr[i]);
    }
    stack.pop();
    stack.pop();
    stack.printStack();

    // Create Queue
    cout << "\n\nQUEUE: " << endl;
    Queue queue = Queue();
    for(int i = 5; i < 19; i += 2) {
        queue.enqueue(curr[i]);
    }
    queue.printQueue();

    cout << "\n\nQueue peek: " << endl;
    cout << "\tPeek front: ";
    queue.peekFront()->print();
    cout << "\n\tPeek rear: ";
    queue.peekRear()->print();

    cout << "\n\nQueue dequeue (x2): " << endl;
    queue.dequeue();
    queue.dequeue();
    queue.printQueue();

    cout << "\n\nQueue enqueue and dequeue: " << endl;
    cout << "\tEnqueue Currencies 10, 11, 12, 13, 14 " << endl;;
    cout << "\tDequeue (x5)" << endl;
    for(int i = 10; i < 15; i++) {
        queue.enqueue(curr[i]);
    }
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.printQueue();

    // Leaving message
    cout << "\n\nThank you for using our program.\nNeil and Xi -02.16.2023" << endl; 
}