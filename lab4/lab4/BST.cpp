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

//BSTNode acts as item node in BST
class BSTNode {
private:
    Krone* kr;
public:
    // BSTNode default constructor
    BSTNode () {
        
    }
    // BSTNode constructor that sets the node point to a Krone
    BSTNode (Krone* krone) {
        kr = krone;
    }
    
    BSTNode* leftChild = nullptr;
    BSTNode* rightChild = nullptr;
    
    // getter
    Krone* getKr() {
        return kr;
    }
};

// BST class acts like binary search tree
class BST {
private:
    BSTNode* root = nullptr;
    
    // PURPOSE:  This method does the breadth-first traversal
    // PRE:    - node: the root of the tree
    //         - s: the stream to print the tree to
    //         - can't be any cycles
    // POST:   - print the tree in breadth-first traversal to the stream s
    // RETURN: - No return value.
    void breadthFirst(BSTNode* node, ostream& s = cout) {
        Queue list;
        list.enqueue(reinterpret_cast<Krone*>(node));
        while (node != nullptr) {
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
    
    // PURPOSE:  This method does the in-Order traversal
    // PRE:    - node: the root of the tree
    //         - s: the stream to print the tree to
    //         - can't be any cycles
    // POST:   - print the tree in in-Order traversal to the stream s
    // RETURN: - No return value.
    void inOrder(BSTNode* node, ostream& s = cout) {
        if (node != nullptr) {
            inOrder(node->leftChild, s);
            node->getKr()->print(s);
            s << " ";
            inOrder(node->rightChild, s);
        }
    }
    
    // PURPOSE:  This method does the pre-Order traversal
    // PRE:    - node: the root of the tree
    //         - s: the stream to print the tree to
    //         - can't be any cycles
    // POST:   - print the tree in pre-Order traversal to the stream s
    // RETURN: - No return value.
    void preOrder(BSTNode* node, ostream& s = cout) {
        if (node != nullptr) {
            node->getKr()->print(s);
            s << " ";
            preOrder(node->leftChild, s);
            preOrder(node->rightChild, s);
        }
    }
    
    // PURPOSE:  This method does the post-Order traversal
    // PRE:    - node: the root of the tree
    //         - s: the stream to print the tree to
    //         - can't be any cycles
    // POST:   - print the tree in post-Order traversal to the stream s
    // RETURN: - No return value.
    void postOrder(BSTNode* node, ostream& s = cout) {
        if (node != nullptr) {
            postOrder(node->leftChild, s);
            postOrder(node->rightChild, s);
            node->getKr()->print(s);
            s << " ";
        }
    }
    
    // PURPOSE:  search for a specific krone and its parent of the node that holds it
    // PRE:    - root: the root of the tree
    //         - kr: the krone object user wants to search for
    //         - parent: point to the parent of the node that holds the Krone object that user wants to search for
    // POST:   - parent will point to the parent of the node that holds the Krone object that user wants to search for
    // RETURN: - the BSTNode pointer that holds the Krone object that user wants to search for; nullpointer if the BSTNode doesn't exit
    BSTNode* search(Krone* kr, BSTNode* root, BSTNode*& parent) {
            if(root == nullptr) return nullptr;
            if(kr->isEqual(*(root->getKr()))) return root;
            else if(kr->isGreater(*(root->getKr()))) {
                parent = root;
                return this->search(kr, root->rightChild, parent);
            }
            else {
                parent = root;
                return this->search(kr, root->leftChild, parent);
            }
        }
    
public:
    // BST class default constructor
    BST() {
    }
    
    // BST class constructor that assign a krone object to a BSTNode and sets the root point to the BSTNode
    BST(Krone* kr) {
        root = new BSTNode(kr);
    }
    
    //getter
    BSTNode* getRoot(){
        return root;
    }
    
    // PURPOSE:  delete BSTNode created by new
    // PRE:    - node: the root of the tree
    // POST:   - the tree is deleted
    // RETURN: - No return value.
   
    void deleteAll(BSTNode* node) {
        if (node->leftChild != nullptr) {
            deleteAll(node->leftChild);
        }
        if (node->rightChild != nullptr) {
            deleteAll(node->rightChild);
        }
        delete node;
    }
    
    //BST destructor make sure that none of the node in the tree outlive the tree
    ~BST() {
        if (root != nullptr)
            deleteAll(getRoot());
    }
    
    // PURPOSE:  for user to call
    // PRE:    - kr: the krone object user wants to search for
    //         - parent: point to the parent of the node that holds the Krone object that user wants to search for
    // POST:   - parent will point to the parent of the node that holds the Krone object that user wants to search for
    // RETURN: - the BSTNode pointer that holds the Krone object that user wants to search for; nullpointer if the BSTNode doesn't exit
    BSTNode* search(Krone* kr, BSTNode*& parent) {
            return search(kr, this->root, parent);
        }

    
    
    // PURPOSE:  insert a BSTNode with the Krone object the user wants to add
    // PRE:    - node: root of the tree or root of the subtree
    //         - krToBeInserted: Krone object the user wants to add to the tree
    // POST:   - tree contains the inserted node
    void insert (BSTNode* node, Krone* krToBeInserted) {
        if (node == nullptr) {
            root = new BSTNode(krToBeInserted);
        }
        else {
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
       
    }
    
    // PURPOSE:  print the tree is breadth-first, in-order, pre-order, post-order sequence of the tree both on screen and an output file
    // PRE:    - no cycles
    // POST:   - printed breadth-first, in-order, pre-order, post-order sequence of the tree on screen and an output file
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
    
    // PURPOSE:  count the BSTNode inside the tree
    // PRE:    - node: the root of the tree
    // RETURN: - the number of BST nodes in the tree
    int count(BSTNode* node) {
        int i = 0;
        Queue list;
        list.enqueue(reinterpret_cast<Krone*>(node));
        while (node != nullptr) {
            if(node->leftChild != nullptr) {
                list.enqueue(reinterpret_cast<Krone*>(node->leftChild));
            }
            if(node->rightChild != nullptr) {
                list.enqueue(reinterpret_cast<Krone*>(node->rightChild));
            }
            i++;
            list.dequeue();
            node = reinterpret_cast<BSTNode*>(list.peekFront());
        }
        return i;
    }
    
    // PURPOSE:  to check if the tree is empty
    // RETURN: - true if the tree is empty; return false if the tree is not empty
    bool isEmpty() {
        if (root == nullptr)
            return true;
        return false;
    }
    
    // PURPOSE:  to empty the tree
    // POST:   - the tree becomes empty
    void empty() {
        if (root->leftChild != nullptr)
            deleteAll(root->leftChild);
        if (root->leftChild != nullptr)
            deleteAll(root->rightChild);
        root = nullptr;
    }
   
        
};


