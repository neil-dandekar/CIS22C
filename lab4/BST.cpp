// NAME BLOCK
// Lab:  04
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 04 is to demonstrate Trees (Binary Search Trees) and 
// its algorithms in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Queue.cpp"
using namespace std;

class BSTNode {
    private:
    Krone* kr;

    public:
    BSTNode* leftChild;
    BSTNode* rightChild;

    BSTNode(Krone* krone) {
        this->kr = krone;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
    
    Krone* getKr() {
        return kr;
    }
};

class BST {
    private:
    BSTNode* root;
    
    void breadthFirst(BSTNode* node, ostream& s = std::cout) {
        Queue list;
        list.enqueue(reinterpret_cast<Krone*>(node));
        while(node != nullptr) {
            if(node->leftChild != nullptr) {
                list.enqueue(reinterpret_cast<Krone*>(node->leftChild));
            }
            if(node->rightChild != nullptr) {
                list.enqueue(reinterpret_cast<Krone*>(node->rightChild));
            }
            reinterpret_cast<BSTNode*>(list.peekFront())->getKr()->print(s);
            s << " ";
            list.dequeue();
            node = reinterpret_cast<BSTNode*>(list.peekFront());
        }
    }
    
    void inOrder(BSTNode* node, ostream& s = std::cout) {
        if(node != nullptr) {
            inOrder(node->leftChild, s);
            node->getKr()->print(s);
            s << " ";
            inOrder(node->rightChild, s);
        }
    }
    
    void preOrder(BSTNode* node, ostream& s = std::cout) {
        if(node != nullptr) {
            node->getKr()->print(s);
            s << " ";
            preOrder(node->leftChild, s);
            preOrder(node->rightChild, s);
        }
    }
    
    void postOrder(BSTNode* node, ostream& s = std::cout) {
        if(node != nullptr) {
            postOrder(node->leftChild, s);
            postOrder(node->rightChild, s);
            node->getKr()->print(s);
            s << " ";
        }
    }
    
    public:
    BST() {
        root = nullptr;
    }

    BST(Krone* kr) {
        root = new BSTNode(kr);
    }
    
    BSTNode* getRoot(){
        return root;
    }
    
    // method to delete BSTNode created by new
    void deleteAll(BSTNode* node) {
        if(node->leftChild != nullptr) {
            deleteAll(node->leftChild);
        }
        if(node->rightChild != nullptr) {
            deleteAll(node->rightChild);
        }
        delete node;
    }
    
    ~BST() {
        deleteAll(getRoot());
    }
    
    ////////////
    
    void insert(BSTNode* node, Krone* krToBeInserted) {
        if(node == nullptr) {
            root = new BSTNode(krToBeInserted);
        }
        else {
            if(node->getKr()->isGreater(*krToBeInserted)) {
                if(node->leftChild != nullptr){
                    node = node->leftChild;
                    insert(node, krToBeInserted);
                }
                else {
                    BSTNode* nodeToBeInserted =  new BSTNode(krToBeInserted);
                    node->leftChild = nodeToBeInserted;
                }
            }
            else {
                if(node->rightChild != nullptr){
                    node = node->rightChild;
                    insert(node, krToBeInserted);
                }
                else {
                    BSTNode* nodeToBeInserted =  new BSTNode(krToBeInserted);
                    node->rightChild = nodeToBeInserted;
                }
                
            }
            
        }
       
    }
    
    void print() {
        cout << "BreadthFirst traversal:" << endl;
        breadthFirst(root);
        cout << endl;
        cout << "inOrder traversal:" << endl;
        inOrder(root);
        cout << endl;
        cout << "preOrder traversal:" << endl;
        preOrder(root);
        cout << endl;
        cout << "postOrder traversal:" << endl;
        postOrder(root);
        cout << endl;

        ofstream myFile;
        myFile.open("FourTraversalOutPut.txt");
        myFile << "BreadthFirst traversal:" << endl;
        breadthFirst(root, myFile);
        myFile << endl;
        myFile << "inOrder traversal:" << endl;
        inOrder(root, myFile);
        myFile << endl;
        myFile << "preOrder traversal:" << endl;
        preOrder(root, myFile);
        myFile << endl;
        myFile << "postOrder traversal:" << endl;
        postOrder(root, myFile);
        myFile.close();
    }
    
    bool isEmpty() {
        return root == nullptr;
    }

    BSTNode* search(Krone* kr) {
        return search(kr, this->root);
    }

    BSTNode* search(Krone* kr, BSTNode* root) {
        if(root == nullptr) return nullptr;

        if(kr->isEqual(*(root->getKr()))) return root;
        else if(kr->isGreater(*(root->getKr()))) return this->search(kr, root->rightChild);
        else return this->search(kr, root->leftChild);
    }
};