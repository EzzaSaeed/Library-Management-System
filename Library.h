#ifndef Library_h
#define Library_h

#include<iostream>
#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include <vector>
using namespace std;
  
  class Library{
  	private:
  		vector<Book> books;
  		vector<Member> members;
  		vector<Transaction> transactions;
  	public:
  		Library();
  		// file handling
  		void loadBooks();
  		void saveBooks();
  		
  		void loadMembers();
  		void saveMembers();
  		
  		void loadTransactions();
  		void saveTransactions();
  		
  		// book management
  		
  		void addBook();
  		void viewBooks();
  		void updateBook();
  		void deleteBook();
  		
  		//member management
  		void addMember();
  		void viewMembers();
  		
  		// borrow and return 
  		void issueBook();
  		void returnBook();
  		
  		// seacrh
  		
  		void searchBookbyID();
  		void searchBookbyTitle();
  		void searchBookbyAuthor();
  		//reports
  		void currentlyIssuedBooks();
  		void BorrowedBooks();
  		void overdueBooks();
  };
  #endif
