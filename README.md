# Library Management System

## Overview

A console-based Library Management System built in C++ using OOP, STL, and file handling. It manages books, members, and borrow/return transactions with persistent file storage.

---

## Project Structure

```
Library System/
├── main.cpp                     # Entry point
├── Book.h / Book.cpp            # Book class (encapsulation)
├── Member.h / Member.cpp        # Member class
├── Transaction.h / Transaction.cpp  # Borrow/Return transaction class
├── Library.h / Library.cpp      # Main controller (all business logic)
├── data/
│   ├── books.txt                # Book records (auto-created)
│   ├── members.txt              # Member records (auto-created)
│   └── transactions.txt         # Borrow records (auto-created)
└── README.md
```

---

## Features

### Book Management
- Add new books (ID auto-generated)
- Update book title, author, and category
- Delete books (only if not currently issued)
- View all books with availability status

### Member Management
- Register new members
- View all members
- Track full borrowing history per member

### Borrow & Return System
- Issue a book to a member
- Return a book
- Prevents issuing unavailable books
- Updates availability status automatically

### Search
- Search by Book ID
- Search by Title (partial match, case-insensitive)
- Search by Author (partial match, case-insensitive)

### Reports
- Top 5 most borrowed books
- Currently issued books
- Overdue books

---

## Data Storage Format

**`books.txt`**
```
bookID|title|author|category|isAvailable|borrowCount
```

**`members.txt`**
```
memberID|name|contact|activeBorrowCount|histID1,histID2,...
```

**`transactions.txt`**
```
recordID|memberID|bookID|issueDate|returnDate|returned
```

---

## OOP Design

| Class | Responsibility |
|-------|---------------|
| `Book` | Encapsulates book data and serialization |
| `Member` | Encapsulates member data and borrow history |
| `BorrowRecord` | Encapsulates transaction data and date logic |
| `Library` | Controller — all business logic and menus |
| `FileHandler` | Static class for file read/write operations |
