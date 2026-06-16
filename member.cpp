#include "Member.h"
#include<sstream>

 Member::Member() {
 	memberID=0;
 	name="";
 	contact="";
 	BorrowCount=0;
 }
  //parametrized constructor
  Member::Member(int id, string n, string c, int borrowcount){
  	memberID=id;
  	name=n;
  	contact=c;
  	BorrowCount=borrowcount;
  }
  
   // getter
   int Member::getmemberID() const{
   	 return memberID;
   }
   string Member::getname() const{
   	 return name;
   }
   string Member::getcontact() const{
   	return contact;
   }
   int Member::getBorrowCount() const{
   	return BorrowCount;
   }
   
   // setter
   void Member::setname(string n){
   	name=n;
   }
   void Member::setcontact(string c){
   	contact=c;
   }
   void Member::setBorrowCount(int borrowcount){
   	BorrowCount= borrowcount;
   }
   
   //display information
   void Member::show() const{
   	 cout<<"Member id:"<<memberID<<endl;
   	 cout<<"name:"<<name<<endl;
   	 cout<<"contact:"<<contact<<endl;
   	 cout<<"borrowcount:"<<BorrowCount<<endl;
   }
   	 
   	 // obj to string
   	 string Member::serialize() const{
   	 	return to_string(memberID) + ","+
   	 	 name + "," +
   	 	 contact +"," +
   	 	 to_string (BorrowCount);
		}
		
	// string to obj 
	 Member Member::deserialize(string data){
	 	stringstream ss (data);
	 	string id,name,contact,borrowcount;
	 	getline(ss,id,',');
	 	getline(ss,name,',');
	 	getline(ss,contact,',');
	 	getline(ss,borrowcount,',');
	 	 return Member (stoi(id),name,contact,stoi(borrowcount));
	 	
	 }
   	 
   
   
