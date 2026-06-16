#include <iostream>
#include "Library.h"
 using namespace std;
  int main () {
  	
  	Library library;
  	int choice;
  	 do {
  	 	cout<<".....................LIBRARY MANAGEMENT SYSTEM............................."<<endl;
  	 	cout<<"1) ADD BOOK"<<endl;
  	 	cout<<"2) VIEW BOOK"<<endl;
  	 	cout<<"3) UPDATE BOOK"<<endl;
  	 	cout<<"4) DELETE BOOK"<<endl;
  	 	cout<<"5) ADD MEMBER"<<endl;
  	 	cout<<"6) VIEW MEMBER"<<endl;
  	 	cout<<"7) ISSUE BOOK"<<endl;
  	 	cout<<"8) RETURN BOOK"<<endl;
  	 	cout<<"9) SEARCH BOOK BY ID"<<endl;
  	 	cout<<"10) SEARCH BOOK BY TITLE"<<endl;
  	 	cout<<"11) SEARCH BOOK BY AUTHOR"<<endl;
  	 	cout<<"12) CURRENTLY ISSUE BOOK"<<endl;
  	 	cout<<"13) BORROWED BOOK"<<endl;
  	 	cout<<"14  OVERDUE BOOK"<<endl;
  	 	cout<<"15)   EXIT"<<endl;
  	 	
  	cout<<"Enter a choice:";
  	 cin>>choice;
  	  switch (choice) {
  	  	case 1:
  	  	library.addBook() ;
  	  	   break;
  	  	case 2:
  	  	library.viewBooks() ;
  	  	   break;
  	  	case 3:
  	  	library.updateBook() ;
  	  	   break;
  	  	case 4:
  	  	library.deleteBook() ;
  	  	   break;
  	  	case 5:
  	  	library.addMember() ;
  	  	   break;
  	  	case 6:
  	  	library.viewMembers() ;
  	  	   break;
  	  	case 7:
  	  	library.issueBook() ;
  	  	   break;
  	  	case 8:
  	  	library.returnBook() ;
  	  	   break;
  	  	case 9:
  	  	library.searchBookbyID() ;
  	  	   break;
  	  	case 10:
  	  	library.searchBookbyTitle() ;
  	  	   break;
  	  	case 11:
  	  	library.searchBookbyAuthor() ;
  	  	   break;
  	  	case 12:
  	  	library.currentlyIssuedBooks() ;
  	  	   break;
  	  	case 13:
  	  	library.BorrowedBooks() ;
  	  	   break;
  	  	case 14:
  	  	library.overdueBooks();
  	  	   break;
  	  	case 15:
  	  	     cout<<"THANKS FOR VISITING"<<endl;
  	  	   break;
  	  	   
  	  	 default:
  	  	 	cout<<"INVALID CHOICE"<<endl;
		}
		} while (choice!=15);
}
		

	   
  
