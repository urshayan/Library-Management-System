#include "Queue.h"

// Constructor - Initialize empty queue
Queue::Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

// Destructor - Free all nodes
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

/**
 * Enqueue - Add a student ID to the rear of the queue
 * Time Complexity: O(1)
 */
void Queue::enqueue(int studentID) {
    Node* newNode = new Node(studentID);
    
    if (isEmpty()) {
        // First element - both front and rear point to it
        frontNode = rearNode = newNode;
    } else {
        // Add to rear
        rearNode->next = newNode;
        rearNode = newNode;
    }
    size++;
}

/**
 * Dequeue - Remove and return the front student ID
 * Returns -1 if queue is empty
 * Time Complexity: O(1)
 */
int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Error: Queue is empty. Cannot dequeue." << std::endl;
        return -1;
    }
    
    Node* temp = frontNode;
    int data = frontNode->data;
    frontNode = frontNode->next;
    
    // If queue becomes empty, update rear as well
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    
    delete temp;
    size--;
    return data;
}

/**
 * Front - View the front student ID without removing it
 * Returns -1 if queue is empty
 * Time Complexity: O(1)
 */
int Queue::front() const {
    if (isEmpty()) {
        std::cout << "Error: Queue is empty. No front element." << std::endl;
        return -1;
    }
    return frontNode->data;
}

/**
 * IsEmpty - Check if queue has no elements
 * Time Complexity: O(1)
 */
bool Queue::isEmpty() const {
    return frontNode == nullptr;
}

/**
 * GetSize - Return the number of students waiting
 * Time Complexity: O(1)
 */
int Queue::getSize() const {
    return size;
}

/**
 * Display - Print all student IDs from front to rear
 * Time Complexity: O(n)
 */
void Queue::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    
    std::cout << "\n=== Request Queue (Front to Rear) ===" << std::endl;
    Node* current = frontNode;
    int position = 1;
    
    while (current != nullptr) {
        std::cout << position++ << ". Student ID: " << current->data << std::endl;
        current = current->next;
    }
    std::cout << "Total waiting: " << size << std::endl;
}
