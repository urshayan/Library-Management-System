#include "Transaction.h"
#include <iostream>

// Default constructor
Transaction::Transaction() 
    : transactionID(0), studentID(0), bookID(0), type(TransactionType::BORROW), date("") {}

// Parameterized constructor
Transaction::Transaction(int tID, int sID, int bID, TransactionType t, const std::string& d)
    : transactionID(tID), studentID(sID), bookID(bID), type(t), date(d) {}

// Getters
int Transaction::getTransactionID() const {
    return transactionID;
}

int Transaction::getStudentID() const {
    return studentID;
}

int Transaction::getBookID() const {
    return bookID;
}

TransactionType Transaction::getType() const {
    return type;
}

std::string Transaction::getDate() const {
    return date;
}

/**
 * GetTypeString - Convert enum to string for display
 */
std::string Transaction::getTypeString() const {
    return (type == TransactionType::BORROW) ? "BORROW" : "RETURN";
}

/**
 * Display - Print transaction information
 */
void Transaction::display() const {
    std::cout << "Transaction ID: " << transactionID 
              << " | Student: " << studentID 
              << " | Book: " << bookID 
              << " | Type: " << getTypeString() 
              << " | Date: " << date << std::endl;
}
