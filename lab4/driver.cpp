#include <iostream>
#include "BST.cpp"
#include "Currency.cpp"
#include "Krone.cpp"
#include "Queue.cpp"
#include "SinglyLinkedList.cpp"

using namespace std;

void UI(int i) {
    switch(i) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        default:
        break;
    }
}

int main() {
    // Welcome message
    cout << "Welcome to Lab 4 - Binary Search Trees\nCreated by Xi and Neil" << endl;

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
    
    // Run UI
    while(false) {
        
    }

    BST tree;
    for(int i = 0; i < 20; i++) {
        tree.insert(tree.getRoot(),kr[i]);
    }

    cout << boolalpha << ( tree.search(new Krone(1912834798.00)) == nullptr ) << endl;
    cout << endl;

    tree.print();
    
    cout << tree.isEmpty() << endl;
    
    // Cleanup
    for(int i = 0; i < 20; i++) {
        delete kr[i];
    }
    
    return 0;
}