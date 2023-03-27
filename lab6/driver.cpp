// NAME BLOCK
// Lab:  06
// Name: Neil Dandekar
// The purpose of lab 06 is to demonstrate Heaps (Min Heap) and its 
// algorithms in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "BST.cpp"
#include "Currency.cpp"
#include "Krone.cpp"
#include "Queue.cpp"
#include "SinglyLinkedList.cpp"
#include "MinHeap.cpp"

using namespace std;

int main() {
    cout << "Welcome to Lab 6 - Heaps\nCreated by Neil\n" << endl;

    // Temp array of Krone values
    double arr[20] =
        {57.12, 23.44, 87.43, 68.99, 111.22, 44.55,
        77.77, 18.36, 543.21, 20.21, 345.67, 36.18,
        48.48, 101.00, 11.00, 21.00, 51.00, 1.00,
        251.00, 151.00};

    // Create Krone array
    Krone* kr[20];
    for(int i = 0; i < 20; i++) {
        kr[i] = new Krone(arr[i]);
    }
    
    // MinHeap heap
    MinHeap heap;

    // Insert first 10 Krones
    for(int i = 0; i < 10; i++) {
        heap.insert(kr[i]);
    }

    // MinHeap print
    cout << "FIRST TEN KRONES:" << endl;
    heap.print();

    cout << endl;

    // Insert last 10 Krones
    for(int i = 10; i < 20; i++) {
        heap.insert(kr[i]);
    }

    // MinHeap print
    cout << "LAST TEN KRONES:" << endl;
    heap.print();

    // Thank you message
    cout << "_______________________________\nThank you for using my program. "
                << "\n-Neil Dandekar, 03.26.2023" << endl;
    return 0;
}