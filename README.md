# Library-Management-System

Digital Library Management System implemented in C++.

---

## Features Implemented
- Add and search books (using Binary Search Tree - BST)  
- Register and search students (using Linked List)  
- Borrow and return books with validation (max 3 books per student)  
- Request queue for unavailable books (FIFO)  
- Transaction history tracking (Stack)  
- Display operations for all entities (books, students, requests, transactions)  

---

## To Be Implemented (Easy to Add)
- File I/O (save/load data)  
- Graphical User Interface (Qt / wxWidgets / Dear ImGui)  
- Search by book title or author  
- Due date tracking for borrowed books  
- Fine calculation for overdue returns  

---

## How to Build and Run

### Prerequisites
- g++ compiler with C++11 support  
- `make` utility  

### Build and Run
```bash
# Compile all sources
g++ -std=c++11 -Iinclude src/main.cpp include/*.cpp -o library_system

# Run
./library_system
```

---

## Data Structures Used

| Data Structure | Purpose                          | Time Complexity |
|----------------|---------------------------------|----------------|
| BST            | Book catalog (sorted by ID)      | Search/Insert: O(log n) average |
| Linked List    | Student records                  | Search: O(n) |
| Queue          | Request queue (FIFO)             | Enqueue/Dequeue: O(1) |
| Stack          | Transaction history (LIFO)      | Push/Pop: O(1) |

---

## Architecture

### Design Principles
- **Separation of Concerns:** Each class has a single responsibility  
- **Single Source of Truth:** Only `LibraryManager` modifies the system state  
- **Encapsulation:** Entities don't know about data structures  
- **UI-Ready:** All logic in manager, so GUI can be added easily  

### Class Responsibilities

#### Entities (Data Only)
- **Book:** Stores attributes like ID, title, author, available copies  
- **Student:** Stores borrowed book IDs  
- **Transaction:** Immutable record of borrow/return actions  

#### Data Structures (Generic)
- **BST:** Generic tree for searchable data  
- **LinkedList:** Generic list for students  
- **Queue:** Generic FIFO for requests  
- **Stack:** Generic LIFO for history

