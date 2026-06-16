#include "Book.h"
#include <sstream>

Book::Book() {
	bookID=0;
	title="";
	author="";
	category="";
	available=true;
	
}
  // parametrized constructor
  Book::Book(int id, string t, string a, string c,bool avail){
  	bookID=id;
  	title=t;
  	author=a;
  	category=c;
  	available=avail;
  }
  
   // getter
   int Book::getbookID() const {
   	return bookID;
   }
   string Book::gettitle() const{
   	return title;
   }
   string Book::getauthor() const {
   	 return author;
   }
   string Book::getcategory() const {
   	 return category;
   }
   bool Book::isavailable() const{
   	return available;
   }
   
   //setter
   void Book::settitle(string t){
   	title=t;
   } 
   void Book::setauthor(string a){
   	author =a;
   }
   void Book::setcategory(string c){
   	category=c;
   }
   void Book::setavailability(bool avail){
   	available=avail;
   }
   
   // display information 
   void Book::display() const {
   	 cout<<"Book id:"<<bookID<<endl;
   	 cout<<"Title:"<<title<<endl;
   	 cout<<"Author:"<<author<<endl;
   	 cout<<"Category:"<<category<<endl;
   	 cout<<"Available:"<<available<<endl;
   	  
   	   if (available){
   	   	cout<<"yes";
		  }
		else {
			cout<<"no";
		}
	  cout<<endl;
   }
   
   // convert obj to string
   string Book::serialize() const{
   	 return to_string (bookID) + ","+
   	        title + "," +
   	        author + "," +
   	        category + ","+
   	        to_string (available);
   }
   
    // convert string to obj
   Book Book::deserialize(string data)  {
    	stringstream ss(data);
    	string id, title,author,category, available;
    	getline(ss,id, ',');
    	getline(ss,title, ',');
    	getline(ss,author ,',');
    	getline(ss,category, ',');
    	getline(ss,available, ',');
    	
    	return Book (stoi(id), title,author,category,stoi(available)) ;
	}
	
