#include "Stack.h"
#include <iostream>

// Constructor - Initialize empty stack
Stack::Stack() : topNode(nullptr), size(0) {}

// Destructor - Free all nodes
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

/**
 * Push - Add a transaction to the top of the stack
 * Time Complexity: O(1)
 */
void Stack::push(const Transaction& transaction) {
    Node* newNode = new Node(transaction);
    newNode->next = topNode;  // New node points to current top
    topNode = newNode;        // Update top to new node
    size++;
}

/**
 * Pop - Remove and return the top transaction
 * Assumes stack is not empty (check with isEmpty() first)
 * Time Complexity: O(1)
 */
Transaction Stack::pop() {
    if (isEmpty()) {
        std::cout << "Error: Stack is empty. Cannot pop." << std::endl;
        return Transaction();  // Return default transaction
    }
    
    Node* temp = topNode;
    Transaction data = topNode->data;
    topNode = topNode->next;  // Move top to next node
    delete temp;              // Free the old top node
    size--;
    
    return data;
}

/**
 * Top - View the top transaction without removing it
 * Assumes stack is not empty (check with isEmpty() first)
 * Time Complexity: O(1)
 */
Transaction Stack::top() const {
    if (isEmpty()) {
        std::cout << "Error: Stack is empty. No top element." << std::endl;
        return Transaction();  // Return default transaction
    }
    
    return topNode->data;
}

/**
 * IsEmpty - Check if stack has no elements
 * Time Complexity: O(1)
 */
bool Stack::isEmpty() const {
    return topNode == nullptr;
}

/**
 * GetSize - Return the number of transactions in stack
 * Time Complexity: O(1)
 */
int Stack::getSize() const {
    return size;
}

/**
 * Display - Print all transactions from top to bottom
 * Time Complexity: O(n)
 */
void Stack::display() const {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    
    std::cout << "\n=== Transaction History (Most Recent First) ===" << std::endl;
    Node* current = topNode;
    int count = 1;
    
    while (current != nullptr) {
        std::cout << count++ << ". ";
        current->data.display();
        current = current->next;
    }
    std::cout << "Total transactions: " << size << std::endl;
}
