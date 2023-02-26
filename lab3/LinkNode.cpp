// NAME BLOCK
// Lab:  03
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 03 is to demonstrate the List (LinkedList), Stack, 
// and Queue ADTs in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include "Currency.cpp"

#ifndef LINK_NODE
#define LINK_NODE

class LinkNode {
    public:
    Currency* data;
    LinkNode* next;

    LinkNode() {
        this->data = nullptr;
        this->next = nullptr;
    }
    LinkNode(Currency* c) {
        this->data = c;
        this->next = nullptr;
    }
    ~LinkNode() {}
};

#endif // LINK_NODE