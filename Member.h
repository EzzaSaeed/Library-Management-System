#ifndef Member_h
#define Member_h
#include<iostream>
#include <string>
using namespace std;
 
   class Member {
   	private:
   		int memberID;
   		string name;
   		string contact;
   		int BorrowCount;
   	public:
   		Member();
   		Member(int id, string n, string c, int borrowcount=0);
   	
   	// getter
   	 int getmemberID() const;
   	 string getname() const;
   	 string getcontact() const;
   	 int getBorrowCount() const;
   	 
   	 // setter
   	 void setname(string n);
   	 void setcontact (string c);
   	 void setBorrowCount (int borrowcount);
   	 
   	 // function
   	 void show () const;
   	 
   	 // file handling function
   	 string serialize () const;
   	 static Member deserialize (string data);
   };
   #endif
 

