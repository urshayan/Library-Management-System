#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"

/**
 * LinkedList - Stores and manages Student objects
 * Implemented as a singly linked list
 * Used for maintaining the list of registered students
 */

class LinkedList {
private:
    // Node structure for linked list
    struct Node {
        Student data;
        Node* next;
        
        Node(const Student& s) : data(s), next(nullptr) {}
    };
    
    Node* head;  // Points to first node
    int size;    // Number of students in list

public:
    // Constructor & Destructor
    LinkedList();
    ~LinkedList();
    
    // Core operations
    void append(const Student& student);      // Add student to end
    bool remove(int studentID);               // Remove student by ID
    Student* find(int studentID);             // Find student by ID (returns nullptr if not found)
    bool isEmpty() const;                     // Check if list is empty
    int getSize() const;                      // Get number of students
    
    // Display all students
    void display() const;
};

#endif
