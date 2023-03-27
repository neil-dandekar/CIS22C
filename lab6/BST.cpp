// NAME BLOCK
// Lab:  04
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 04 is to demonstrate Trees (Binary Search Trees) and 
// its algorithms in OOP programming.
///////////////////////////////////////////////////////////////////////////

// MODIFIED FOR LAB 6:
// * File Output capability removed

#include "Queue.cpp"

using namespace std;

// BSTNode acts as item node in BST
class BSTNode {
    private:
    Krone* kr;

    public:
    BSTNode* leftChild;
    BSTNode* rightChild;

    // BSTNode default constructor
    BSTNode() {
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    // BSTNode constructor that sets the node point to a Krone
    BSTNode(Krone* krone) {
        this->kr = krone;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
    
    // getters and setters
    Krone* getKr() {
        return kr;
    }

    void setKr(double value) {
        this->kr = new Krone(value);
    }

    void setKr(Krone* kr) {
        this->kr = kr;
    }
};

// BST class acts like binary search tree
class BST {
    protected:
    BSTNode* root;

    // PURPOSE:  This method does the breadth-first traversal
    // PRE:    - node: the root of the tree
    //         - s: the stream to print the tree to
    //         - can't be any cycles
    // POST:   - print the tree in breadth-first traversal to the stream s
    // RETURN: - No return value.
    void breadthFirst(BSTNode* node) {
        Queue list;
        list.enqueue(reinterpret_cast<Krone*>(node));
        while (node != nullptr) {
            if(node->leftChild != nullptr) {
                list.enqueue(reinterpret_cast<Krone*>(node->leftChild));
            }
            if(node->rightChild != nullptr) {
                list.enqueue(reinterpret_cast<Krone*>(node->rightChild));
            }
            reinterpret_cast<BSTNode*>(list.peekFront())->getKr()->print();
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
    void inOrder(BSTNode* node) {
        if (node != nullptr) {
            inOrder(node->leftChild);
            node->getKr()->print();
            inOrder(node->rightChild);
        }
    }
    
    // PURPOSE:  This method does the pre-Order traversal
    // PRE:    - node: the root of the tree
    //         - s: the stream to print the tree to
    //         - can't be any cycles
    // POST:   - print the tree in pre-Order traversal to the stream s
    // RETURN: - No return value.
    void preOrder(BSTNode* node) {
        if (node != nullptr) {
            node->getKr()->print();
            preOrder(node->leftChild);
            preOrder(node->rightChild);
        }
    }
    
    // PURPOSE:  This method does the post-Order traversal
    // PRE:    - node: the root of the tree
    //         - s: the stream to print the tree to
    //         - can't be any cycles
    // POST:   - print the tree in post-Order traversal to the stream s
    // RETURN: - No return value.
    void postOrder(BSTNode* node) {
        if (node != nullptr) {
            postOrder(node->leftChild);
            postOrder(node->rightChild);
            node->getKr()->print();
        }
    }
    
    // PRE:    - krToBeDeleted: Krone to be deleted
    //         - nodeToBeDeleted: Node to be deleted
    // POST:   - The node with the specified krone value is deleted, if it exists
    // RETURN: - True if node is deleted
    //         - False if node is not deleted (specified value does not exist)
    bool deleteKr(Krone* kr, BSTNode* node) {
        // Return false if Krone is not in BST:
        if(this->search(kr) == nullptr) return false;

        // Searching for node to delete (deleteNode):
        while(!kr->isEqual(*node->getKr())) {
            // Subtree is empty
            if(node == nullptr) return false;
            // Krone is in right subtree
            else if(kr->isGreater(*(node->getKr()))) node = node->rightChild;
            // Krone is in left subtree
            else node = node->leftChild;
        }

        // Finding parent of node:
        BSTNode temp;
        this->search(node->getKr(), temp);
        BSTNode* nodeParent = this->search(temp.getKr());

        // If node is a leaf:
        if(node->leftChild == nullptr && node->rightChild == nullptr) {
            // node is right child:
            if(node->getKr()->isGreater(*nodeParent->getKr())) nodeParent->rightChild = nullptr;
            // node is left child:
            else nodeParent->leftChild = nullptr;
        }
        // deleteNode only has right subtree:
        else if(node->leftChild == nullptr) {
            cout << "right" << endl;
            nodeParent->rightChild = node->rightChild;
            delete node;
        }
        // deleteNode only has left subtree:
        else if(node->rightChild == nullptr) {
            nodeParent->leftChild = node->leftChild;
            delete node;
        }
        // deleteNode has two children:
        else {
            BSTNode* temp = searchSmallest(node->rightChild);
            temp = this->search(temp->getKr());

            deleteKr(temp->getKr(), node->rightChild);
            node->setKr(temp->getKr());
        }
        return true;
    }

    public:
    // BST class default constructor

    BST() {
        root = nullptr;
    }

    // BST class constructor that assign a krone object to a BSTNode and sets the root point to the BSTNode
    BST(Krone* kr) {
        root = new BSTNode(kr);
    }

    //BST destructor make sure that none of the node in the tree outlive the tree
    ~BST() {
        deleteAll(getRoot());
    }
    
    //getter
    BSTNode* getRoot() {
        return root;
    }
    
    // PURPOSE:  delete BSTNode created by new
    // PRE:    - node: the root of the tree
    // POST:   - the tree is deleted
    // RETURN: - No return value.
    void deleteAll(BSTNode* node) {
        if(node->leftChild != nullptr) {
            deleteAll(node->leftChild);
        }
        if(node->rightChild != nullptr) {
            deleteAll(node->rightChild);
        }
        delete node;
    }

    // PURPOSE:  search for a specific krone and its parent of the node that holds it
    // PRE:    - node: the root of the tree
    //         - kr: the krone object user wants to search for
    //         - parent: point to the parent of the node that holds the Krone object that user wants to search for
    // POST:   - parent will point to the parent of the node that holds the Krone object that user wants to search for
    // RETURN: - the BSTNode pointer that holds the Krone object that user wants to search for; nullpointer if the BSTNode doesn't exit
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
    
    // search() overloaded methods:
    BSTNode* search(Krone* kr) {
        BSTNode b;
        return search(kr, b, this->root);
    }

    BSTNode* search(Krone* kr, BSTNode* node) {
        BSTNode b;
        return search(kr, b, node);
    }
    
    BSTNode* search(Krone* kr, BSTNode& parent) {
        return search(kr, parent, this->root);
    }
    

    // PURPOSE:  search for a the smallest Krone value in a subtree
    // PRE:    - node: the root of the tree --> default value: tree root
    // POST:   - nothing is changed.
    // RETURN: - the BSTNode pointer that holds the Krone object with the lowest value in the subtree
    BSTNode* searchSmallest(BSTNode* node) {
        if(node->leftChild == nullptr) return node;
        else return searchSmallest(node->leftChild);
    }
    // searchSmallest() overloaded methods:
    BSTNode* searchSmallest() {
        return searchSmallest(this->root);
    }

    // PURPOSE:  delete a specified Krone value from tree
    // PRE:    - krToBeDeleted: Krone to be deleted
    //         - nodeToBeDeleted: Node to be deleted
    // POST:   - The node with the specified krone value is deleted, if it exists
    // RETURN: - True if node is deleted
    //         - False if node is not deleted (specified value does not exist)
    bool deleteKr(Krone* kr) {
        return deleteKr(kr, this->root);
    }

    // PURPOSE:  insert a BSTNode with the Krone object the user wants to add
    // PRE:    - node: root of the tree or root of the subtree
    //         - krToBeInserted: Krone object the user wants to add to the tree
    // POST:   - tree contains the inserted node
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
    
    // PURPOSE:  print the tree is breadth-first, in-order, pre-order, post-order sequence of the tree both on screen and an output file
    // PRE:    - no cycles
    // POST:   - printed breadth-first, in-order, pre-order, post-order sequence of the tree on screen and an output file
    virtual void print() {
        std::cout << "BreadthFirst traversal:" << endl;
        breadthFirst(root);
        std::cout << endl;
        std::cout << "inOrder traversal:" << endl;
        inOrder(root);
        std::cout << endl;
        std::cout << "preOrder traversal:" << endl;
        preOrder(root);
        std::cout << endl;
        std::cout << "postOrder traversal:" << endl;
        postOrder(root);
        std::cout << endl;
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

    // PURPOSE:  to empty the tree
    // POST:   - the tree becomes empty
    void empty() {
        if(root->leftChild != nullptr)
            deleteAll(root->leftChild);
        if(root->leftChild != nullptr)
            deleteAll(root->rightChild);
        root = nullptr;
    }

    // PURPOSE:  to check if the tree is empty
    // RETURN: - true if the tree is empty; return false if the tree is not empty
    bool isEmpty() {
        return root == nullptr;
    }
};