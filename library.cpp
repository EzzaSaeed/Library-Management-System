#include "Library.h"
#include <fstream>
#include<map>
#include <sstream>

Library::Library()
{
    loadBooks();
    loadMembers();
    loadTransactions();
}
        // save data
  void Library::saveBooks()
{
    ofstream file("books.txt");

    for (size_t i = 0; i < books.size(); i++)
    {
        file << books[i].serialize() << endl;
    }

    file.close();
}
      //load data

  void Library::loadBooks()
{
    books.clear();

    ifstream file("books.txt");

    string line;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            books.push_back(Book::deserialize(line));
        }
    }

    file.close();
}
            // save members
   void Library::saveMembers()
{
    ofstream file("members.txt");

    for (size_t i = 0; i < members.size(); i++)
    {
        file << members[i].serialize() << endl;
    }

    file.close();
}

       //load members
       
    void Library::loadMembers()
{
    members.clear();

    ifstream file("members.txt");

    string line;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            members.push_back(Member::deserialize(line));
        }
    }

    file.close();
}


        // save transactions
		
		void Library::saveTransactions()
{
    ofstream file("transactions.txt");

    for (size_t i = 0; i < transactions.size(); i++)
    {
        file << transactions[i].serialize() << endl;
    }

    file.close();
}

       // load transactions
	   
	  void Library::loadTransactions()
{
    transactions.clear();

    ifstream file("transactions.txt");

    string line;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            transactions.push_back(
                Transaction::deserialize(line));
        }
    }

    file.close();
}

      // add book
      
      void Library::addBook()
{
    int id;
    string title, author, category;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Category: ";
    getline(cin, category);

    // Check duplicate Book ID
    for (size_t i = 0; i < books.size(); i++)
    {
        if (books[i].getbookID() == id)
        {
            cout << "Book ID already exists!" << endl;
            return;
        }
    }

    books.push_back(Book(id, title, author, category, true));

    saveBooks();

    cout << "Book added successfully!" << endl;
}
       // view books
       
       void Library::viewBooks()
{
    if (books.empty())
    {
        cout << "No books available." << endl;
        return;
    }

    for (size_t i = 0; i < books.size(); i++)
    {
        books[i].display();
        cout << "---------------------" << endl;
    }
}

             // update book
        void Library::updateBook()
{
    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;
    cin.ignore();

    for (size_t i = 0; i < books.size(); i++)
    {
        if (books[i].getbookID() == id)
        {
            string title, author, category;

            cout << "Enter New Title: ";
            getline(cin, title);

            cout << "Enter New Author: ";
            getline(cin, author);

            cout << "Enter New Category: ";
            getline(cin, category);

            books[i].settitle(title);
            books[i].setauthor(author);
            books[i].setcategory(category);

            saveBooks();

            cout << "Book updated successfully!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

            // delete book
            
        void Library::deleteBook()
{
    int id;

    cout << "Enter Book ID to delete: ";
    cin >> id;

    for (size_t i = 0; i < books.size(); i++)
    {
        if (books[i].getbookID() == id)
        {
            books.erase(books.begin() + i);

            saveBooks();

            cout << "Book deleted successfully!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

          // add member
        void Library::addMember()
{
    int id;
    string name, contact;

    cout << "Enter Member ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    cout << "Enter Contact: ";
    getline(cin, contact);

    // Check duplicate ID
    for (size_t i = 0; i < members.size(); i++)
    {
        if (members[i].getmemberID() == id)
        {
            cout << "Member ID already exists!" << endl;
            return;
        }
    }

    members.push_back(Member(id, name, contact));

    saveMembers();

    cout << "Member added successfully!" << endl;
}


           //view member
           
    void Library::viewMembers()
{
    if (members.empty())
    {
        cout << "No members found." << endl;
        return;
    }

    for (size_t i = 0; i < members.size(); i++)
    {
        members[i].show();

        cout << "---------------------" << endl;
    }
}


             // issue book
             
        void Library::issueBook()
{
    int bookID, memberID;
    string issueDate;

    cout << "Enter Book ID: ";
    cin >> bookID;

    cout << "Enter Member ID: ";
    cin >> memberID;
    cin.ignore();

    cout << "Enter Issue Date (DD-MM-YYYY): ";
    getline(cin, issueDate);

    // Find Book
    int bookIndex = -1;
    for (size_t i = 0; i < books.size(); i++)
    {
        if (books[i].getbookID() == bookID)
        {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    // Check Availability
    if (!books[bookIndex].isavailable())
    {
        cout << "Book is currently unavailable!" << endl;
        return;
    }

    // Find Member
    int memberIndex = -1;
    for (size_t i = 0; i < members.size(); i++)
    {
        if (members[i].getmemberID() == memberID)
        {
            memberIndex = i;
            break;
        }
    }

    if (memberIndex == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }

    // Update Book Status
    books[bookIndex].setavailability(false);

    // Update Borrow Count
    members[memberIndex].setBorrowCount(
        members[memberIndex].getBorrowCount() + 1
    );

    // Create Transaction
    int transactionID = transactions.size() + 1;

    transactions.push_back(
        Transaction(transactionID,
                    bookID,
                    memberID,
                    issueDate)
    );

    // Save Changes
    saveBooks();
    saveMembers();
    saveTransactions();

    cout << "Book issued successfully!" << endl;
}

          // return book
        void Library::returnBook()
{
    int transactionID;
    string returnDate;

    cout << "Enter Transaction ID: ";
    cin >> transactionID;
    cin.ignore();

    cout << "Enter Return Date (DD-MM-YYYY): ";
    getline(cin, returnDate);

    for (size_t i = 0; i < transactions.size(); i++)
    {
        if (transactions[i].gettransactionID() == transactionID &&
            !transactions[i]. getreturned())
        {
            // Update Transaction
            transactions[i].setreturndate(returnDate);
            transactions[i].setreturned(true);

            // Make Book Available Again
            for (size_t j = 0; j < books.size(); j++)
            {
                if (books[j].getbookID() ==
                    transactions[i].getbookID())
                {
                    books[j].setavailability(true);
                    break;
                }
            }

            // Decrease Member Borrow Count
            for (size_t j = 0; j < members.size(); j++)
            {
                if (members[j].getmemberID() ==
                    transactions[i].getmemberID())
                {
                    members[j].setBorrowCount(
                        members[j].getBorrowCount() - 1
                    );
                    break;
                }
            }

            saveBooks();
            saveMembers();
            saveTransactions();

            cout << "Book returned successfully!" << endl;
            return;
        }
    }

    cout << "Transaction not found or already returned!"
         << endl;
}
       // search by ID
       void Library::searchBookbyID() {
       	int id;
       	cout<<"Enter book id:";
       	cin>>id;
      
       for (size_t i=0; i<books.size(); i++) {
       	 if (books[i].getbookID()==id) {
       	 	books[i].display();
       	 	return;
			}
	   }
	      cout<<"Book not found"<<endl;
	   }
	// serch by title
	   void Library::searchBookbyTitle(){
	   	string title;
	   	 cin.ignore();
	   	cout<<"enter title:";
	   	 getline(cin,title);
	   	for (size_t i=0;i<books.size(); i++) {
	   		 if (books[i].gettitle()==title) {
	   		 	books[i].display();
				}
		   } 
	   }

        // serach by author
        void Library::searchBookbyAuthor() {
        	string author;
        	cin.ignore();
        	cout<<"Enter a author:";
        	getline(cin,author);
       	for (size_t i=0;i<books.size(); i++) {
	   		 if (books[i].getauthor()==author) {
	   		 	books[i].display();
				}
		   } 
        	
		}
	  // report currently issue book
	   void Library::currentlyIssuedBooks() {
	   	bool found=false;
	   	for (size_t i=0; i<transactions.size(); i++ ){
	   		if (!transactions[i].getreturned()) {
	   			transactions[i].displaytransaction();
	   		cout<<".........................."<<endl;
	   		found =true;
	   		
			   }
	   		
		   } 
		if (!found) {
			cout<<"not books are currently issued"<<endl;
		}
	   }
	   
	    // borrowed book
	    void Library::BorrowedBooks() {
	    	map<int,int> BorrowCount;
	    for (size_t i=0; i<transactions.size(); i++ ) {
	    	BorrowCount[transactions[i].getbookID()] ++;
		}
		  if (BorrowCount.empty()) {
		  	cout<<"NOT RECORD FOUND"<<endl;
		  	  return;
		  }
		    cout<<"Borrowed books"<<endl;
		for (map<int,int>::iterator it=BorrowCount.begin(); it!=BorrowCount.end(); it++) {
			cout<<"book id:"<<it->first <<"times borrowed:"<<it->second<<endl;
		}
	    	
		}
	   // overdue book
	   void Library::overdueBooks() {
	   	cout<<"overdue tracking requires comparing issue date"<<"with the current dates"<<endl;
	   	cout<<"you can enhance this later"<<"date calculation"<<endl;
	   }
	  

          

             
    
