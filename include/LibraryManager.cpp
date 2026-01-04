#include "LibraryManager.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

// Constructor - Initialize all data structures
LibraryManager::LibraryManager() : nextTransactionID(1) {
    bookCatalog = new BST();
    students = new LinkedList();
    requestQueue = new Queue();
    transactionHistory = new Stack();
}

// Destructor - Clean up all data structures
LibraryManager::~LibraryManager() {
    delete bookCatalog;
    delete students;
    delete requestQueue;
    delete transactionHistory;
}

/**
 * GetCurrentDate - Helper to get current date in YYYY-MM-DD format
 */
std::string LibraryManager::getCurrentDate() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    std::stringstream ss;
    ss << (1900 + ltm->tm_year) << "-" 
       << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon) << "-"
       << std::setfill('0') << std::setw(2) << ltm->tm_mday;
    
    return ss.str();
}

/**
 * FindStudent - Helper to find student (used internally)
 */
Student* LibraryManager::findStudent(int studentID) {
    return students->find(studentID);
}

// ============== BOOK MANAGEMENT ==============

/**
 * AddBook - Add a new book to the catalog
 * Returns false if book with same ID already exists
 */
bool LibraryManager::addBook(int bookID, const std::string& title, 
                              const std::string& author, int copies) {
    // Check if book already exists
    if (bookCatalog->search(bookID) != nullptr) {
        std::cout << "Error: Book with ID " << bookID << " already exists." << std::endl;
        return false;
    }
    
    Book newBook(bookID, title, author, copies);
    bookCatalog->insert(newBook);
    std::cout << "Book added successfully!" << std::endl;
    return true;
}

/**
 * SearchBook - Find a book by ID
 * Returns nullptr if not found
 */
Book* LibraryManager::searchBook(int bookID) {
    return bookCatalog->search(bookID);
}

/**
 * DisplayAllBooks - Show all books in sorted order
 */
void LibraryManager::displayAllBooks() const {
    bookCatalog->displayInOrder();
}

// ============== STUDENT MANAGEMENT ==============

/**
 * RegisterStudent - Add a new student
 * Returns false if student with same ID already exists
 */
bool LibraryManager::registerStudent(int studentID, const std::string& name, 
                                     const std::string& department) {
    // Check if student already exists
    if (students->find(studentID) != nullptr) {
        std::cout << "Error: Student with ID " << studentID << " already exists." << std::endl;
        return false;
    }
    
    Student newStudent(studentID, name, department);
    students->append(newStudent);
    std::cout << "Student registered successfully!" << std::endl;
    return true;
}

/**
 * SearchStudent - Find a student by ID
 * Returns nullptr if not found
 */
Student* LibraryManager::searchStudent(int studentID) {
    return students->find(studentID);
}

/**
 * DisplayAllStudents - Show all registered students
 */
void LibraryManager::displayAllStudents() const {
    students->display();
}

// ============== BORROW/RETURN OPERATIONS ==============

/**
 * BorrowBook - Student borrows a book
 * Returns false if operation fails
 */
bool LibraryManager::borrowBook(int studentID, int bookID) {
    std::cout << "Debug: Starting borrowBook for Student " << studentID << ", Book " << bookID << std::endl;
    
    // Find student
    Student* student = findStudent(studentID);
    if (student == nullptr) {
        std::cout << "Error: Student ID " << studentID << " not found." << std::endl;
        return false;
    }
    std::cout << "Debug: Found student: " << student->getName() << std::endl;
    
    // Find book
    Book* book = searchBook(bookID);
    if (book == nullptr) {
        std::cout << "Error: Book ID " << bookID << " not found." << std::endl;
        return false;
    }
    std::cout << "Debug: Found book: " << book->getTitle() << std::endl;
    
    // Check if student already has this book
    std::cout << "Debug: Checking if student has borrowed this book..." << std::endl;
    if (student->hasBorrowedBook(bookID)) {
        std::cout << "Error: Student has already borrowed this book." << std::endl;
        return false;
    }
    std::cout << "Debug: Student hasn't borrowed this book yet" << std::endl;
    
    // Try to borrow the book
    std::cout << "Debug: Attempting to borrow copy..." << std::endl;
    if (!book->borrowCopy()) {
        std::cout << "Error: No copies available. Student added to request queue." << std::endl;
        requestQueue->enqueue(studentID);
        return false;
    }
    std::cout << "Debug: Book copy borrowed successfully" << std::endl;
    
    // Update student's borrowed list
    std::cout << "Debug: Adding book to student's borrowed list..." << std::endl;
    student->addBorrowedBook(bookID);
    std::cout << "Debug: Book added to student's list" << std::endl;
    
    // Create transaction record
    std::cout << "Debug: Creating transaction record..." << std::endl;
    Transaction t(nextTransactionID++, studentID, bookID, 
                  TransactionType::BORROW, getCurrentDate());
    transactionHistory->push(t);
    std::cout << "Debug: Transaction recorded" << std::endl;
    
    std::cout << "Book borrowed successfully!" << std::endl;
    return true;
}

/**
 * ReturnBook - Student returns a book
 * Returns false if operation fails
 */
bool LibraryManager::returnBook(int studentID, int bookID) {
    // Find student
    Student* student = findStudent(studentID);
    if (student == nullptr) {
        std::cout << "Error: Student ID " << studentID << " not found." << std::endl;
        return false;
    }
    
    // Find book
    Book* book = searchBook(bookID);
    if (book == nullptr) {
        std::cout << "Error: Book ID " << bookID << " not found." << std::endl;
        return false;
    }
    
    // Check if student has this book
    if (!student->hasBorrowedBook(bookID)) {
        std::cout << "Error: Student has not borrowed this book." << std::endl;
        return false;
    }
    
    // Return the book
    book->returnCopy();
    student->removeBorrowedBook(bookID);
    
    // Create transaction record
    Transaction t(nextTransactionID++, studentID, bookID, 
                  TransactionType::RETURN, getCurrentDate());
    transactionHistory->push(t);
    
    std::cout << "Book returned successfully!" << std::endl;
    return true;
}

// ============== REQUEST QUEUE MANAGEMENT ==============

/**
 * AddToRequestQueue - Add student to waiting list
 */
void LibraryManager::addToRequestQueue(int studentID) {
    requestQueue->enqueue(studentID);
    std::cout << "Student " << studentID << " added to request queue." << std::endl;
}

/**
 * ProcessNextRequest - Process the next student in queue
 * Returns -1 if queue is empty
 */
int LibraryManager::processNextRequest() {
    if (requestQueue->isEmpty()) {
        std::cout << "Request queue is empty." << std::endl;
        return -1;
    }
    
    int studentID = requestQueue->dequeue();
    std::cout << "Processing request for Student ID: " << studentID << std::endl;
    return studentID;
}

/**
 * DisplayRequestQueue - Show all waiting students
 */
void LibraryManager::displayRequestQueue() const {
    requestQueue->display();
}

// ============== TRANSACTION HISTORY ==============

/**
 * DisplayTransactionHistory - Show all transactions
 */
void LibraryManager::displayTransactionHistory() const {
    transactionHistory->display();
}

/**
 * DisplayRecentTransactions - Show last N transactions
 */
void LibraryManager::displayRecentTransactions(int count) const {
    if (transactionHistory->isEmpty()) {
        std::cout << "No transactions yet." << std::endl;
        return;
    }
    
    std::cout << "\n=== Recent Transactions (Last " << count << ") ===" << std::endl;
    
    // This is a simplified version - in real implementation,
    // you'd need to peek without popping
    Stack tempStack;
    int displayed = 0;
    
    // Copy transactions to temp stack
    while (!transactionHistory->isEmpty() && displayed < count) {
        Transaction t = transactionHistory->pop();
        t.display();
        tempStack.push(t);
        displayed++;
    }
    
    // Restore original stack
    while (!tempStack.isEmpty()) {
        transactionHistory->push(tempStack.pop());
    }
}

// ============== FILE I/O (Placeholder) ==============

bool LibraryManager::saveToFile(const std::string& filename) {
    std::cout << "Save to file: " << filename << " (Not implemented yet)" << std::endl;
    return false;
}

bool LibraryManager::loadFromFile(const std::string& filename) {
    std::cout << "Load from file: " << filename << " (Not implemented yet)" << std::endl;
    return false;
}
