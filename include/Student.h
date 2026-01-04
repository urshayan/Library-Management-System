#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// Forward declaration
class BorrowedBooksList;

class Student {
private:
    int studentID;
    std::string name;
    std::string department;
    BorrowedBooksList* borrowedBookIDs;  // List of book IDs this student has borrowed

public:
    // Constructors
    Student();
    Student(int id, const std::string& n, const std::string& dept);
    Student(const Student& other);              // Copy constructor
    Student& operator=(const Student& other);   // Assignment operator
    ~Student();
    
    // Getters
    int getStudentID() const;
    std::string getName() const;
    std::string getDepartment() const;
    
    // Book management (only LibraryManager should call these)
    void addBorrowedBook(int bookID);
    bool removeBorrowedBook(int bookID);  // Returns false if book not found
    bool hasBorrowedBook(int bookID) const;
    int getBorrowedCount() const;
    
    // Display
    void display() const;
};

#endif
