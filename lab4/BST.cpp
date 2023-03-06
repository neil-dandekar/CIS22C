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

    BSTNode() {
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    BSTNode(Krone* krone) {
        this->kr = krone;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
    
    Krone* getKr() {
        return kr;
    }

    Krone* setKr(double value) {
        this->kr = new Krone(value);
    }

    Krone* setKr(Krone* kr) {
        this->kr = kr;
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

    ~BST() {
        deleteAll(getRoot());
    }
    
    BSTNode* getRoot() {
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

    BSTNode* search(Krone* kr, BSTNode& parent, BSTNode* node) {
        if(node == nullptr) return nullptr;

        if(kr->isEqual(*(node->getKr()))) return node;
        else if(kr->isGreater(*(node->getKr()))) {
            parent = *node;
            return this->search(kr, parent, node->rightChild);
        }
        else {
            parent = *node;
            return this->search(kr, parent, node->leftChild);
        }
    }
    
    BSTNode* search(Krone* kr) {
        BSTNode b;
        return search(kr, b, this->root);
    }

    BSTNode* search(Krone* kr, BSTNode* root) {
        BSTNode b;
        return search(kr, b, root);
    }
    
    BSTNode* search(Krone* kr, BSTNode& parent) {
        return search(kr, parent, this->root);
    }
    
    BSTNode* searchSmallest() {
        BSTNode* searchSmallest(this->root);
    }

    BSTNode* searchSmallest(BSTNode* node) {
        if(node->leftChild == nullptr) return node;
        else return searchSmallest(node->leftChild);
    }
    


    
    bool deleteNode(BSTNode* node, Krone* kr) {
        BSTNode parent;
        BSTNode* removeNode = search(kr, parent, node);
        BSTNode* parentRemove = &parent;

        cout << "Remove node: ";
        // removeNode->getKr()->print();
        // parentRemove->getKr()->print();
        cout << endl;

        if(removeNode == nullptr || node == nullptr) return false;
        if(removeNode->leftChild == nullptr) parentRemove->rightChild = removeNode->rightChild;
        else if(removeNode->rightChild  == nullptr) parentRemove->leftChild = removeNode->leftChild;
        else {
            // cout << "\nNode to remove: ";
            // removeNode->getKr()->print();

            BSTNode* replaceNode = searchSmallest(removeNode->rightChild);

            // cout << "\nReplacement Node: ";
            // replaceNode->getKr()->print();

            // PARENT OF TEMP: ///////////
            // BSTNode parent2;
            // replaceNode = search(replaceNode->getKr(), parent2);
            // BSTNode* parentReplace = &parent2;

            // cout << "\nReplacement Node again: ";
            // replaceNode->getKr()->print();
            // cout << "\nParent of Replacement Node: ";
            // parentReplace->getKr()->print();
            // cout << "\nParent of Replacement Node left child: ";
            // parentReplace->leftChild->getKr()->print();

            removeNode->setKr(replaceNode->getKr());
            BSTNode parent2;
            replaceNode = search(replaceNode->getKr(), parent2, removeNode->rightChild);
            BSTNode* parentUltimateRemove = &parent2;
            cout << "\nReplacement Node: ";
            replaceNode->getKr()->print();
            cout << "\nParent of Replacement Node: ";
            parentUltimateRemove->getKr()->print();
            // replaceNode->rightChild->getKr()->print();
            // replaceNode->leftChild->getKr()->print();
            // parentUltimateRemove->leftChild->getKr()->print();

            // deleteNode(parentUltimateRemove, replaceNode->getKr());
            // return deleteNode(removeNode->rightChild, replaceNode->getKr());

            // cout << "\nNode to remove again: ";
            // removeNode->getKr()->print();

            // cout << "\nRight subtree of removeNode: ";
            // removeNode->rightChild->getKr()->print();
            // replaceNode->getKr()->print();

            // return deleteNode(removeNode->rightChild, replaceNode->getKr());

            // // delete replaceNode;
            // parentReplace->leftChild = nullptr;
            // cout << "\nParent of Replacement Node left child again: ";
            // // parentReplace->leftChild->getKr()->print();
            // cout << boolalpha << (parentReplace->leftChild == nullptr) << endl;
        }
        return true;
    }

    void insert(BSTNode* node, Krone* krToBeInserted) {
        if(node == nullptr) this->root = new BSTNode(krToBeInserted);
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
        myFile.open("output.txt");
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
    
    void empty() {
        if(root->leftChild != nullptr)
            deleteAll(root->leftChild);
        if(root->leftChild != nullptr)
            deleteAll(root->rightChild);
        root = nullptr;
    }

    bool isEmpty() {
        return root == nullptr;
    }
};