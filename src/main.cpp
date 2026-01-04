#include "LibraryManager.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========" << endl;
    cout << "1.  Add Book" << endl;
    cout << "2.  Display All Books" << endl;
    cout << "3.  Search Book" << endl;
    cout << "4.  Register Student" << endl;
    cout << "5.  Display All Students" << endl;
    cout << "6.  Search Student" << endl;
    cout << "7.  Borrow Book" << endl;
    cout << "8.  Return Book" << endl;
    cout << "9.  Display Request Queue" << endl;
    cout << "10. Display Transaction History" << endl;
    cout << "0.  Exit" << endl;
    cout << "===============================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    LibraryManager library;
    int choice;
    
    // Sample data for testing
    cout << "=== Initializing Sample Data ===" << endl;
    library.addBook(101, "Data Structures", "Tanenbaum", 3);
    library.addBook(102, "Algorithms", "Cormen", 2);
    library.addBook(103, "Operating Systems", "Silberschatz", 5);
    
    library.registerStudent(1, "Shayan Ijaz", "Computer Science");
    library.registerStudent(2, "Zikria Shah ", "Computer Science");
    library.registerStudent(3, "Muhammad Musa", "Computer Science");
    cout << "Sample data loaded!" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int id, copies;
                string title, author;
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Number of Copies: ";
                cin >> copies;
                library.addBook(id, title, author, copies);
                break;
            }
            
            case 2: {
                library.displayAllBooks();
                break;
            }
            
            case 3: {
                int id;
                cout << "Enter Book ID: ";
                cin >> id;
                Book* book = library.searchBook(id);
                if (book) {
                    cout << "\n=== Book Found ===" << endl;
                    book->display();
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            
            case 4: {
                int id;
                string name, dept;
                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, dept);
                library.registerStudent(id, name, dept);
                break;
            }
            
            case 5: {
                library.displayAllStudents();
                break;
            }
            
            case 6: {
                int id;
                cout << "Enter Student ID: ";
                cin >> id;
                Student* student = library.searchStudent(id);
                if (student) {
                    cout << "\n=== Student Found ===" << endl;
                    student->display();
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            
            case 7: {
                int studentID, bookID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Book ID: ";
                cin >> bookID;
                library.borrowBook(studentID, bookID);
                break;
            }
            
            case 8: {
                int studentID, bookID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Book ID: ";
                cin >> bookID;
                library.returnBook(studentID, bookID);
                break;
            }
            
            case 9: {
                library.displayRequestQueue();
                break;
            }
            
            case 10: {
                library.displayTransactionHistory();
                break;
            }
            
            case 0: {
                cout << "Thank you for using Library Management System!" << endl;
                break;
            }
            
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        
    } while (choice != 0);
    
    return 0;
}
