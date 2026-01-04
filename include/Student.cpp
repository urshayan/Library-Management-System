#include "Student.h"
#include <iostream>

/**
 * BorrowedBooksList - Simple linked list to store book IDs
 */
class BorrowedBooksList {
private:
    struct Node {
        int bookID;
        Node* next;
        Node(int id) : bookID(id), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    BorrowedBooksList() : head(nullptr), size(0) {}
    
    ~BorrowedBooksList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    
    void add(int bookID) {
        Node* newNode = new Node(bookID);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    bool remove(int bookID) {
        if (!head) return false;
        
        if (head->bookID == bookID) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        
        Node* current = head;
        while (current->next) {
            if (current->next->bookID == bookID) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    bool contains(int bookID) const {
        Node* current = head;
        while (current) {
            if (current->bookID == bookID) return true;
            current = current->next;
        }
        return false;
    }
    
    int getSize() const { return size; }
    
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << "   - Book ID: " << current->bookID << std::endl;
            current = current->next;
        }
    }
};

// Default constructor
Student::Student() : studentID(0), name(""), department(""), borrowedBookIDs(nullptr) {
    borrowedBookIDs = new BorrowedBooksList();
}

// Parameterized constructor
Student::Student(int id, const std::string& n, const std::string& dept)
    : studentID(id), name(n), department(dept), borrowedBookIDs(nullptr) {
    borrowedBookIDs = new BorrowedBooksList();
}

// Copy constructor (IMPORTANT!)
Student::Student(const Student& other) 
    : studentID(other.studentID), name(other.name), 
      department(other.department), borrowedBookIDs(nullptr) {
    borrowedBookIDs = new BorrowedBooksList();
    // Note: This creates a new empty list. For full copy, would need to copy all book IDs
}

// Assignment operator (IMPORTANT!)
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        studentID = other.studentID;
        name = other.name;
        department = other.department;
        
        // Delete old list
        if (borrowedBookIDs) {
            delete borrowedBookIDs;
        }
        
        // Create new list
        borrowedBookIDs = new BorrowedBooksList();
        // Note: This creates a new empty list. For full copy, would need to copy all book IDs
    }
    return *this;
}

// Destructor
Student::~Student() {
    if (borrowedBookIDs) {
        delete borrowedBookIDs;
        borrowedBookIDs = nullptr;
    }
}

// Getters
int Student::getStudentID() const {
    return studentID;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getDepartment() const {
    return department;
}

/**
 * AddBorrowedBook - Add a book ID to student's borrowed list
 */
void Student::addBorrowedBook(int bookID) {
    if (borrowedBookIDs) {
        borrowedBookIDs->add(bookID);
    }
}

/**
 * RemoveBorrowedBook - Remove a book ID from student's list
 * Returns false if book not found
 */
bool Student::removeBorrowedBook(int bookID) {
    if (borrowedBookIDs) {
        return borrowedBookIDs->remove(bookID);
    }
    return false;
}

/**
 * HasBorrowedBook - Check if student has borrowed a specific book
 */
bool Student::hasBorrowedBook(int bookID) const {
    if (borrowedBookIDs) {
        return borrowedBookIDs->contains(bookID);
    }
    return false;
}

/**
 * GetBorrowedCount - Return number of books currently borrowed
 */
int Student::getBorrowedCount() const {
    if (borrowedBookIDs) {
        return borrowedBookIDs->getSize();
    }
    return 0;
}

/**
 * Display - Print student information
 */
void Student::display() const {
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << "Books borrowed: " << getBorrowedCount() << std::endl;
    if (borrowedBookIDs && getBorrowedCount() > 0) {
        borrowedBookIDs->display();
    }
    std::cout << "-----------------------------------" << std::endl;
}
