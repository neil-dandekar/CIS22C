// NAME BLOCK
// Lab:  06
// Name: Neil Dandekar
// The purpose of lab 06 is to demonstrate Min Heaps and its algorithms in 
// OOP programming.
///////////////////////////////////////////////////////////////////////////

#include "BST.cpp"

class MinHeap: protected BST {
    private:
    BSTNode* root;

    public:

    void reHeapUp(BSTNode* heap, BSTNode* newNode) {
        if(newNode != root) {
        }
    }

    void insert(Krone* kr, BSTNode* root) {
        if(!kr->isEqual(*root->getKr())) {
            
        }
    }

    BSTNode* search(Krone* kr, BSTNode* root) {
        if(!kr->isEqual(*root->getKr())) {
            if(kr->isGreater(*root->getKr())) {
                BSTNode* node = search(kr, root->leftChild);
                if(node == nullptr) {
                    node = search(kr, root->rightChild);
                }
            }
            else return nullptr;
        }
        return root;
    }

    BSTNode* deleteKr();
};