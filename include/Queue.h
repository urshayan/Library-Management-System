#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

/**
 * Queue - FIFO (First In First Out) data structure
 * Stores student IDs for request management
 * Implemented using a singly linked list
 */

class Queue {
private:
    // Node structure for linked list implementation
    struct Node {
        int data;
        Node* next;
        
        Node(int d) : data(d), next(nullptr) {}
    };
    
    Node* frontNode;  // Points to front of queue
    Node* rearNode;   // Points to rear of queue
    int size;         // Number of elements in queue

public:
    // Constructor & Destructor
    Queue();
    ~Queue();
    
    // Core operations
    void enqueue(int studentID);  // Add student ID to rear
    int dequeue();                // Remove and return front student ID
    int front() const;            // View front student ID without removing
    bool isEmpty() const;         // Check if queue is empty
    int getSize() const;          // Get number of waiting students
    
    // Display all student IDs in queue (front to rear)
    void display() const;
};

#endif
