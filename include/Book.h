#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int bookID;
    std::string title;
    std::string author;
    int totalCopies;
    int availableCopies;

public:
    // Constructors
    Book();
    Book(int id, const std::string& t, const std::string& a, int total);
    
    // Getters
    int getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getTotalCopies() const;
    int getAvailableCopies() const;
    
    // State modifiers (only LibraryManager should call these)
    bool borrowCopy();  // Returns false if no copies available
    void returnCopy();
    
    // Display
    void display() const;
};

#endif
