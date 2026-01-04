#include "LinkedList.h"
#include <iostream>

// Constructor - Initialize empty list
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Destructor - Free all nodes
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

/**
 * Append - Add a student to the end of the list
 * Time Complexity: O(n)
 */
void LinkedList::append(const Student& student) {
    Node* newNode = new Node(student);
    
    if (head == nullptr) {
        // List is empty
        head = newNode;
    } else {
        // Traverse to end
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

/**
 * Remove - Remove a student by ID
 * Returns true if removed, false if not found
 * Time Complexity: O(n)
 */
bool LinkedList::remove(int studentID) {
    if (head == nullptr) {
        return false;
    }
    
    // Check if head needs to be removed
    if (head->data.getStudentID() == studentID) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }
    
    // Search for student in rest of list
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data.getStudentID() == studentID) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return true;
        }
        current = current->next;
    }
    
    return false;  // Student not found
}

/**
 * Find - Search for a student by ID
 * Returns pointer to Student if found, nullptr otherwise
 * Time Complexity: O(n)
 */
Student* LinkedList::find(int studentID) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.getStudentID() == studentID) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;  // Not found
}

/**
 * IsEmpty - Check if list has no elements
 * Time Complexity: O(1)
 */
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

/**
 * GetSize - Return the number of students in list
 * Time Complexity: O(1)
 */
int LinkedList::getSize() const {
    return size;
}

/**
 * Display - Print all students in the list
 * Time Complexity: O(n)
 */
void LinkedList::display() const {
    if (isEmpty()) {
        std::cout << "No students registered." << std::endl;
        return;
    }
    
    std::cout << "\n=== Registered Students ===" << std::endl;
    Node* current = head;
    int count = 1;
    
    while (current != nullptr) {
        std::cout << count++ << ". ";
        current->data.display();
        current = current->next;
    }
    std::cout << "Total students: " << size << std::endl;
}
