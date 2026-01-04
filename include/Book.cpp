#include "Book.h"
#include <iostream>

// Default constructor
Book::Book() : bookID(0), title(""), author(""), totalCopies(0), availableCopies(0) {}

// Parameterized constructor
Book::Book(int id, const std::string& t, const std::string& a, int total)
    : bookID(id), title(t), author(a), totalCopies(total), availableCopies(total) {}

// Getters
int Book::getBookID() const {
    return bookID;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getTotalCopies() const {
    return totalCopies;
}

int Book::getAvailableCopies() const {
    return availableCopies;
}

/**
 * BorrowCopy - Decrease available copies by 1
 * Returns false if no copies available
 */
bool Book::borrowCopy() {
    if (availableCopies > 0) {
        availableCopies--;
        return true;
    }
    return false;
}

/**
 * ReturnCopy - Increase available copies by 1
 */
void Book::returnCopy() {
    if (availableCopies < totalCopies) {
        availableCopies++;
    }
}

/**
 * Display - Print book information
 */
void Book::display() const {
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Available: " << availableCopies << "/" << totalCopies << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}
