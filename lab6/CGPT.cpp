#include <iostream>

using namespace std;

// Define the node structure
struct Node {
    int data;
    Node *left, *right;
};

// Define the MinHeap class
class MinHeap {
    private:
    Node *root;

    // Helper function to insert a new node into the heap
    Node* insertHelper(Node* root, int data) {
        if (!root) {
            Node *node = new Node;
            node->data = data;
            node->left = node->right = NULL;
            return node;
        }
        if (data < root->data) {
            swap(data, root->data);
        }
        root->left = insertHelper(root->left, data);
        return root;
    }

    // Helper function to delete the minimum node from the heap
    Node* deleteHelper(Node* root) {
        if (!root) {
            return NULL;
        }
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        if (!root->left) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left->data < root->right->data) {
            swap(root->data, root->left->data);
            root->left = deleteHelper(root->left);
        }
        else {
            swap(root->data, root->right->data);
            root->right = deleteHelper(root->right);
        }
        return root;
    }

    // Helper function to search for a node with given data in the heap
    bool searchHelper(Node* root, int data) {
        if (!root) {
            return false;
        }
        if (root->data == data) {
            return true;
        }
        return searchHelper(root->left, data) || searchHelper(root->right, data);
    }

public:
    // Constructor to initialize the heap with a NULL root
    MinHeap() {
        root = NULL;
    }

    // Insert a new node into the heap
    void insert(int data) {
        root = insertHelper(root, data);
    }

    // Delete the minimum node from the heap
    void deleteMin() {
        root = deleteHelper(root);
    }

    // Search for a node with given data in the heap
    bool search(int data) {
        return searchHelper(root, data);
    }
};

// Driver code to test the MinHeap class
int main() {
    MinHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.insert(6);

    cout << "Heap: ";
    while (heap.search(1)) {
        heap.deleteMin();
        cout << "1 ";
    }
    while (heap.search(3)) {
        heap.deleteMin();
        cout << "3 ";
    }
    while (heap.search(5)) {
        heap.deleteMin();
        cout << "5 ";
    }
    while (heap.search(6)) {
        heap.deleteMin();
        cout << "6 ";
    }
    while (heap.search(8)) {
        heap.deleteMin();
        cout << "8 ";
    }
    cout << endl;

    return 0;
}