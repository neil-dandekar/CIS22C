// NAME BLOCK
// Lab:  04
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 04 is to demonstrate Trees (Binary Search Trees) and 
// its algorithms in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "BST.cpp"
#include "Currency.cpp"
#include "Krone.cpp"
#include "Queue.cpp"
#include "SinglyLinkedList.cpp"

using namespace std;

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
    cout << "\nInstructions: Type a number (1-5) to select an operation:" << endl;
    cout << "\t1. Add Krone" << endl;
    cout << "\t2. Delete Krone" << endl;
    cout << "\t3. Search Krone" << endl;
    cout << "\t4. Print BST Traversals" << endl;
    cout << "\t5. Print BST Traversals & Exit Program" << endl;

    while(true) {
        int i;
        while(true) {
            string input;
            cout << "\nChoose an operation: ";
            getline(cin, input);
            try {
                i = stoi(input);
            }
            catch(const std::exception& e) {
                cout << "ERROR: Operation # must be an integer. Please try again." << endl;
            }
            if(i < 1 || i > 5) cout << "ERROR: Operation # must be between 1 and 5. Please try again." << endl;
            else break;
        }

        switch(i) {
            // Add Krone:
            case 1:
                cout << "Enter Krone value to add: ";
                break;
            // Delete Krone:
            case 2:
                cout << "Enter Krone value to delete: ";
                break;
            // Search Krone:
            case 3:
                cout << "Enter Krone value to search: ";
                break;
            // Print BST:
            case 4:
                // print
                break;
            // Print BST & Exit:
            case 5:
                cout << "_______________________________\nThank you for using our program. "
                << "\n-Neil Dandekar and Xi Gao, 03.04.2023" << endl;
                break;
            default:
            break;
        }
        if(i == 5) break;
    }

    // BST tree;
    // for(int i = 0; i < 20; i++) {
    //     tree.insert(tree.getRoot(),kr[i]);
    // }

    // cout << boolalpha << ( tree.search(new Krone(1912834798.00)) == nullptr ) << endl;
    // cout << endl;

    // tree.print();
    
    // cout << tree.isEmpty() << endl;
    
    // Cleanup
    for(int i = 0; i < 20; i++) {
        delete kr[i];
    }
    
    return 0;
}