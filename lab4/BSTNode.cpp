// NAME BLOCK
// Lab:  04
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 04 is to demonstrate Trees (Binary Search Trees) and 
// its algorithms in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <fstream>
#include "Queue.cpp"
using namespace std;

class BSTNode {
private:
    Krone* kr;
public:
    BSTNode (Krone* krone) {
        kr = krone;
    }
    BSTNode* leftChild = nullptr;
    BSTNode* rightChild = nullptr;
    Krone* getKr() {
        return kr;
    }
};

class BST {
private:
    BSTNode* root;
    
    void inOrder(ostream& s, BSTNode* node) {
        if (node != nullptr) {
            inOrder(s, node->leftChild);
            node->getKr()->print(s);
            cout << " ";
            inOrder(s, node->rightChild);
        }
    }
    
    void preOrder(ostream& s,BSTNode* node) {
        if (node != nullptr) {
            node->getKr()->print(s);
            cout << " ";
            preOrder(s, node->leftChild);
            preOrder(s, node->rightChild);
        }
    }
    
    void postOrder(ostream& s, BSTNode* node) {
        if (node != nullptr) {
            postOrder(s, node->leftChild);
            postOrder(s, node->rightChild);
            node->getKr()->print(s);
            cout << " ";
        }
    }
    
public:
    BST(Krone* kr) {
        root = new BSTNode(kr);
    }
    
    ~BST() {
        deleteAll(getRoot());
    }
    
    BSTNode* getRoot(){
        return root;
    }
    void insert (BSTNode* node, Krone* krToBeInserted) {
        if (node->getKr()->isGreater(*krToBeInserted)) {
            if (node->leftChild != nullptr){
                node = node->leftChild;
                insert(node, krToBeInserted);
            }
            else {
                BSTNode* nodeToBeInserted =  new BSTNode(krToBeInserted);
                node->leftChild = nodeToBeInserted;
            }
        }
        else {
            if (node->rightChild != nullptr){
                node = node->rightChild;
                insert(node, krToBeInserted);
            }
            else {
                BSTNode* nodeToBeInserted =  new BSTNode(krToBeInserted);
                node->rightChild = nodeToBeInserted;
            }
            
        }
    }
    
    // method to delete BSTNode created by new
    void deleteAll(BSTNode* node) {
        if (node->leftChild != nullptr) {
            deleteAll(node->leftChild);
        }
        if (node->rightChild != nullptr) {
            deleteAll(node->rightChild);
        }
        delete node;
    }
    
    void breadthFirst(BSTNode* node) {
        ofstream myfile;
        myfile.open("breadthFirst.txt");
        queue<BSTNode*> list;
        list.push(node);
        while (node != nullptr) {
            if(node->leftChild != nullptr) {
                list.push(node->leftChild);
            }
            if(node->rightChild != nullptr) {
                list.push(node->rightChild);
            }
            list.front()->getKr()->print(cout);
            list.front()->getKr()->print(myfile);
            list.pop();
            node = list.front();
        }
        myfile.close();
        
    }
    
    void inOrder(BSTNode* node) {
        ofstream myfile;
        myfile.open("inOrder.txt");
        inOrder(cout, node);
        inOrder(myfile, node);
        myfile.close();
    }
    
    void preOrder(BSTNode* node) {
        ofstream myfile;
        myfile.open("preOrder.txt");
        preOrder(cout, node);
        preOrder(myfile, node);
        myfile.close();
    }
    
    void postOrder(BSTNode* node) {
        ofstream myfile;
        myfile.open("postOrder.txt");
        postOrder(cout, node);
        postOrder(myfile, node);
        myfile.close();
    }
        
};

int main() {
    // Temp array of Krone values
    double arr[] =
        {57.12, 23.44, 87.43, 68.99, 111.22, 44.55,
            77.77, 18.36, 543.21, 20.21, 345.67, 36.18,
            48.48, 101.00, 11.00, 21.00, 51.00, 1.00,
            251.00, 151.00};

    // Create Krone array
    Krone* kr[size(arr)];
    for(int i = 0; i < size(arr); i++) {
        kr[i] = new Krone(arr[i]);
    }
    
    
    BST tree = BST(kr[0]);
    for (int i = 1; i < size(arr); i++) {
        tree.insert(tree.getRoot(),kr[i]);
    }
    tree.breadthFirst(tree.getRoot());
    cout << endl;
    tree.inOrder(tree.getRoot());
    cout << endl;
    tree.preOrder(tree.getRoot());
    cout << endl;
    tree.postOrder(tree.getRoot());
    cout << endl;
    

    for(int i = 0; i < size(arr); i++) {
        delete kr[i];
    }

    
    return 0;
}
