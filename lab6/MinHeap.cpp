// NAME BLOCK
// Lab:  06
// Name: Neil Dandekar
// The purpose of lab 06 is to demonstrate Heaps (Min Heap) and its 
// algorithms in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

class MinHeap : public BST {

    void swap(Krone &kr1, Krone &kr2) {
        // PURPOSE: Swaps two Krone object values.
        // PRE:    - Method must be called using class instance.
        //         - kr1, kr2: Krone objects to be swapper.
        // POST:   - kr1 has the value of kr2 originally and vice
        //           kr2 has the value of kr1 originally.
        // RETURN: - Nothing is returned.
        Krone temp = kr1;
        kr1 = kr2;
        kr2 = temp;
    }

    BSTNode* insertHelper(BSTNode* root, Krone* kr) {
        // PURPOSE: Inserts a Krone object into the MinHeap.
        // PRE:    - Method must be called using class instance.
        //         - root: root of Heap (sub) tree.
        //         - kr: Krone to be inserted.
        // POST:   - kr is inserted into the MinHeap.
        // RETURN: - Returns pointer to new node.
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

    BSTNode* deleteHelper(BSTNode* root) {
        // PURPOSE: Deletes the root (minimum) of the MinHeap
        // PRE:    - Method must be called using class instance.
        //         - root: root of Heap (sub) tree.
        // POST:   - The root is deleted from MinHeap.
        // RETURN: - Returns pointer to new root.
        if (!root) {
            return nullptr;
        }
        if (!root->leftChild && !root->rightChild) {
            delete root;
            return nullptr;
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

    bool searchHelper(BSTNode* root, Krone* kr) {
        // PURPOSE: Searches for a Krone in MinHeap.
        // PRE:    - Method must be called using class instance.
        //         - root: root of Heap (sub) tree.
        //         - kr: krone to be searched for.
        // POST:   - Nothing is changed.
        // RETURN: - Returns pointer to found node.
        //         - Returns null if not found.
        if (!root) {
            return false;
        }
        if (root->getKr()->isEqual(*kr)) {
            return true;
        }
        return searchHelper(root->leftChild, kr) || searchHelper(root->rightChild, kr);
    }

    public:
    // METHODS FOR PUBLIC USE (Calls previous methods):

    void insert(Krone* kr) {
        root = insertHelper(root, kr);
    }

    void deleteMin() {
        root = deleteHelper(root);
    }

    bool search(Krone* kr) {
        return searchHelper(root, kr);
    }
};