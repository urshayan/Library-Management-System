#include "BST.h"
#include <iostream>

// Constructor - Initialize empty tree
BST::BST() : root(nullptr) {}

// Destructor - Free all nodes
BST::~BST() {
    destroyTree(root);
}

/**
 * Insert - Add a book to the catalog
 * Time Complexity: O(log n) average, O(n) worst case
 */
void BST::insert(const Book& book) {
    root = insertHelper(root, book);
}

/**
 * InsertHelper - Recursive helper for insertion
 */
BST::Node* BST::insertHelper(Node* node, const Book& book) {
    // Base case: found the insertion point
    if (node == nullptr) {
        return new Node(book);
    }
    
    // Recursive case: traverse left or right
    if (book.getBookID() < node->data.getBookID()) {
        node->left = insertHelper(node->left, book);
    } else if (book.getBookID() > node->data.getBookID()) {
        node->right = insertHelper(node->right, book);
    }
    // If equal, book already exists (do nothing)
    
    return node;
}

/**
 * Search - Find a book by ID
 * Returns pointer to Book if found, nullptr otherwise
 * Time Complexity: O(log n) average, O(n) worst case
 */
Book* BST::search(int bookID) {
    Node* result = searchHelper(root, bookID);
    return result ? &(result->data) : nullptr;
}

/**
 * SearchHelper - Recursive helper for searching
 */
BST::Node* BST::searchHelper(Node* node, int bookID) const {
    // Base cases
    if (node == nullptr || node->data.getBookID() == bookID) {
        return node;
    }
    
    // Recursive case: search left or right subtree
    if (bookID < node->data.getBookID()) {
        return searchHelper(node->left, bookID);
    } else {
        return searchHelper(node->right, bookID);
    }
}

/**
 * Remove - Delete a book from catalog
 * Returns true if removed, false if not found
 * Time Complexity: O(log n) average, O(n) worst case
 */
bool BST::remove(int bookID) {
    if (search(bookID) == nullptr) {
        return false;
    }
    root = deleteHelper(root, bookID);
    return true;
}

/**
 * DeleteHelper - Recursive helper for deletion
 * Handles three cases: no children, one child, two children
 */
BST::Node* BST::deleteHelper(Node* node, int bookID) {
    if (node == nullptr) {
        return nullptr;
    }
    
    // Find the node to delete
    if (bookID < node->data.getBookID()) {
        node->left = deleteHelper(node->left, bookID);
    } else if (bookID > node->data.getBookID()) {
        node->right = deleteHelper(node->right, bookID);
    } else {
        // Found the node to delete
        
        // Case 1: No children (leaf node)
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // Case 2: One child (right only)
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        // Case 2: One child (left only)
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children
        else {
            // Find inorder successor (smallest in right subtree)
            Node* successor = findMin(node->right);
            // Copy successor's data to current node
            node->data = successor->data;
            // Delete the successor
            node->right = deleteHelper(node->right, successor->data.getBookID());
        }
    }
    
    return node;
}

/**
 * FindMin - Find the node with minimum bookID in subtree
 */
BST::Node* BST::findMin(Node* node) const {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

/**
 * DisplayInOrder - Show all books sorted by bookID
 * Time Complexity: O(n)
 */
void BST::displayInOrder() const {
    if (isEmpty()) {
        std::cout << "No books in catalog." << std::endl;
        return;
    }
    
    std::cout << "\n=== Book Catalog (Sorted by ID) ===" << std::endl;
    inorderHelper(root);
}

/**
 * InorderHelper - Recursive inorder traversal (Left-Root-Right)
 */
void BST::inorderHelper(Node* node) const {
    if (node != nullptr) {
        inorderHelper(node->left);
        node->data.display();
        inorderHelper(node->right);
    }
}

/**
 * IsEmpty - Check if tree has no nodes
 * Time Complexity: O(1)
 */
bool BST::isEmpty() const {
    return root == nullptr;
}

/**
 * DestroyTree - Recursively delete all nodes (postorder)
 */
void BST::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
