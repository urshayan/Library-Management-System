#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

enum class TransactionType {
    BORROW,
    RETURN
};

class Transaction {
private:
    int transactionID;
    int studentID;
    int bookID;
    TransactionType type;
    std::string date;  // Format: YYYY-MM-DD

public:
    // Constructor
    Transaction();
    Transaction(int tID, int sID, int bID, TransactionType t, const std::string& d);
    
    // Getters only - IMMUTABLE
    int getTransactionID() const;
    int getStudentID() const;
    int getBookID() const;
    TransactionType getType() const;
    std::string getDate() const;
    std::string getTypeString() const;
    
    // Display
    void display() const;
};

#endif
