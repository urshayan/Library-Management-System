#ifndef STACK_H
#define STACK_H

#include "Transaction.h"

/**
 * Stack - LIFO (Last In First Out) data structure
 * Stores Transaction objects for history tracking
 * Implemented using a singly linked list
 */

class Stack {
private:
    // Node structure for linked list implementation
    struct Node {
        Transaction data;
        Node* next;
        
        Node(const Transaction& t) : data(t), next(nullptr) {}
    };
    
    Node* topNode;  // Points to the top of the stack
    int size;       // Number of elements in stack

public:
    // Constructor & Destructor
    Stack();
    ~Stack();
    
    // Core operations
    void push(const Transaction& transaction);  // Add transaction to top
    Transaction pop();                          // Remove and return top transaction
    Transaction top() const;                    // View top transaction without removing
    bool isEmpty() const;                       // Check if stack is empty
    int getSize() const;                        // Get number of transactions
    
    // Display all transactions (top to bottom)
    void display() const;
};

#endif
