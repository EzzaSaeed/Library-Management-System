# Library-Management-System

  A console-based Library Management System developed in C++ using OOP, STL, and File Handling. It enables users to manage books and members, issue and return books, search records, and maintain transaction data efficiently.
  
Overview:

A console-based Library Management System built in C++ using Object-Oriented Programming (OOP), STL, and File Handling. The system manages books, members, and borrow/return transactions with persistent file storage.

Project Structure:

Library-System/
│
├── main.cpp                # Entry point
├── Book.h
├── Book.cpp                # Book class (Encapsulation)
├── Member.h
├── Member.cpp              # Member class
├── Transaction.h
├── Transaction.cpp         # Borrow/Return transaction class
├── Library.h
├── Library.cpp             # Main controller (Business Logic)
│
├── data/
│   ├── books.txt           # Book records (auto-created)
│   ├── members.txt         # Member records (auto-created)
│   └── transactions.txt    # Transaction records (auto-created)
│
└── README.md

Features:

📚 Book Management:

Add new books (ID auto-generated)
Update book title, author, and category
Delete books (only if not currently issued)
View all books with availability status

👥 Member Management:

Register new members
View all members
Track complete borrowing history for each member

🔄 Borrow & Return System:

Issue books to members
Return borrowed books
Prevent issuing unavailable books
Automatically update book availability status

🔍 Search Functionality:

Search by Book ID
Search by Title (partial match, case-insensitive)
Search by Author (partial match, case-insensitive)

📊 Reports:

Top 5 most borrowed books
Currently issued books
Overdue books
Data Storage Format

books.txt:

bookID|title|author|category|isAvailable|borrowCount

members.txt:

memberID|name|contact|activeBorrowCount|historyIDs

transactions.txt:

recordID|memberID|bookID|issueDate|returnDate|returned

OOP Design:

Class
Responsibility
Book
Encapsulates book data and serialization
Member
Encapsulates member data and borrowing history
BorrowRecord
Encapsulates transaction data and date logic
Library
Main controller containing business logic
FileHandler
Handles file read/write operations

Technologies Used:

C++
Object-Oriented Programming (OOP)
Standard Template Library (STL)
File Handling
Console-Based User Interface

Learning Outcomes
This project demonstrates:
Encapsulation
Class Design
File Handling
Data Persistence
STL Usage
Modular Programming
Real-World OOP Application Development

Author
EzzaSaeed
