#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include "Book.h"
#include "Student.h"
#include "Transaction.h"
#include "BST.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include <string>

/*
 * LibraryManager is the only class allowed to change system state.
 * 
 * All operations that modify books, students, or transactions
 * must go through this class.
 */

class LibraryManager {
private:
    BST* bookCatalog;                          // All books (key: bookID)
    LinkedList* students;                       // All registered students
    Queue* requestQueue;                        // Student IDs waiting for books
    Stack* transactionHistory;                  // All transactions
    
    int nextTransactionID;                      // Auto-increment for transactions
    
    // Helper functions
    std::string getCurrentDate() const;
    Student* findStudent(int studentID);
    
public:
    // Constructor & Destructor
    LibraryManager();
    ~LibraryManager();
    
    // Book Management
    bool addBook(int bookID, const std::string& title, const std::string& author, int copies);
    Book* searchBook(int bookID);
    void displayAllBooks() const;
    
    // Student Management
    bool registerStudent(int studentID, const std::string& name, const std::string& department);
    Student* searchStudent(int studentID);
    void displayAllStudents() const;
    
    // Borrow/Return Operations
    bool borrowBook(int studentID, int bookID);
    bool returnBook(int studentID, int bookID);
    
    // Request Queue Management
    void addToRequestQueue(int studentID);
    int processNextRequest();  // Returns -1 if queue empty
    void displayRequestQueue() const;
    
    // Transaction History
    void displayTransactionHistory() const;
    void displayRecentTransactions(int count) const;
    
    // File I/O (to be implemented later)
    bool saveToFile(const std::string& filename);
    bool loadFromFile(const std::string& filename);
};

#endif
