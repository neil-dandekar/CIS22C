#include "BST.cpp"

#include <iostream>

using namespace std;

// Define the MinHeap class
class MinHeap {
    private:
    BSTNode *root;

    void swap(Krone &kr1, Krone &kr2) {
        Krone temp = kr1;
        kr1 = kr2;
        kr2 = temp;
    }

    // Helper function to insert a new BSTNode into the heap
    BSTNode* insertHelper(BSTNode* root, Krone* kr) {
        if (!root) {
            BSTNode *node = new BSTNode();
            node->setKr(kr);
            return node;
        }
        if (root->getKr()->isGreater(*kr)) {
            swap(*kr, *root->getKr());
        }
        root->leftChild = insertHelper(root->leftChild, kr);
        return root;
    }

    // Helper function to delete the minimum BSTNode from the heap
    BSTNode* deleteHelper(BSTNode* root) {
        if (!root) {
            return NULL;
        }
        if (!root->leftChild && !root->rightChild) {
            delete root;
            return NULL;
        }
        if (!root->leftChild) {
            BSTNode *temp = root->rightChild;
            delete root;
            return temp;
        }
        if (!root->rightChild) {
            BSTNode *temp = root->leftChild;
            delete root;
            return temp;
        }
        if (root->leftChild->getKr() < root->rightChild->getKr()) {
            swap(*root->getKr(), *root->leftChild->getKr());
            root->leftChild = deleteHelper(root->leftChild);
        }
        else {
            swap(*root->getKr(), *root->rightChild->getKr());
            root->rightChild = deleteHelper(root->rightChild);
        }
        return root;
    }

    // Helper function to search for a BSTNode with given getKr() in the heap
    bool searchHelper(BSTNode* root, Krone* kr) {
        if (!root) {
            return false;
        }
        if (root->getKr()->isEqual(*kr)) {
            return true;
        }
        return searchHelper(root->leftChild, kr) || searchHelper(root->rightChild, kr);
    }

public:
    // Constructor to initialize the heap with a NULL root
    MinHeap() {
        root = NULL;
    }

    // Insert a new BSTNode into the heap
    void insert(Krone* kr) {
        root = insertHelper(root, kr);
    }

    // Delete the minimum BSTNode from the heap
    void deleteMin() {
        root = deleteHelper(root);
    }

    // Search for a BSTNode with given getKr() in the heap
    bool search(Krone* kr) {
        return searchHelper(root, kr);
    }
};

// Driver code to test the MinHeap class
int main() {
    MinHeap heap;
    heap.insert(new Krone(5));
    heap.insert(new Krone(3));
    heap.insert(new Krone(8));
    heap.insert(new Krone(1));
    heap.insert(new Krone(6));

    cout << "Heap: ";
    while (heap.search(new Krone(1))) {
        heap.deleteMin();
        cout << "1 ";
    }
    while (heap.search(new Krone(3))) {
        heap.deleteMin();
        cout << "3 ";
    }
    while (heap.search(new Krone(5))) {
        heap.deleteMin();
        cout << "5 ";
    }
    while (heap.search(new Krone(6))) {
        heap.deleteMin();
        cout << "6 ";
    }
    while (heap.search(new Krone(8))) {
        heap.deleteMin();
        cout << "8 ";
    }
    cout << endl;

    return 0;
}