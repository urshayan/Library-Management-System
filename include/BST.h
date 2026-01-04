#ifndef BST_H
#define BST_H

#include "Book.h"

/**
 * BST - Binary Search Tree for Book catalog
 * Stores books organized by bookID for fast searching
 * Left subtree: bookID < parent, Right subtree: bookID > parent
 */

class BST {
private:
    // Node structure for tree
    struct Node {
        Book data;
        Node* left;
        Node* right;
        
        Node(const Book& b) : data(b), left(nullptr), right(nullptr) {}
    };
    
    Node* root;  // Root of the tree
    
    // Helper functions (recursive)
    Node* insertHelper(Node* node, const Book& book);
    Node* searchHelper(Node* node, int bookID) const;
    Node* deleteHelper(Node* node, int bookID);
    Node* findMin(Node* node) const;
    void inorderHelper(Node* node) const;
    void destroyTree(Node* node);

public:
    // Constructor & Destructor
    BST();
    ~BST();
    
    // Core operations
    void insert(const Book& book);        // Add a book to catalog
    Book* search(int bookID);             // Find a book by ID (returns nullptr if not found)
    bool remove(int bookID);              // Remove a book by ID
    void displayInOrder() const;          // Display all books in sorted order
    bool isEmpty() const;                 // Check if catalog is empty
};

#endif
