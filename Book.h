#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;
 class Book {
 	private:
 		int bookID;
 		string title;
 		string author;
 		string category;
 		bool available;
 	public:
 		Book ();
 		Book (int id, string t, string a, string c, bool avail=true);
 		
 		
 	// getter
 	int getbookID () const;
 	string gettitle()const;
 	string getauthor()const;
 	string getcategory()const;
 	bool isavailable ()const;
 	
 	//setter
 	void settitle (string t);
 	void setauthor (string a);
 	void setcategory (string c);
 	void setavailability (bool avail);
 	
 	// function
 	void display () const;
 	
 	// file handling function
 	string serialize ()const;
 	static Book deserialize (string data);
 	
 	
 };
 
 #endif
