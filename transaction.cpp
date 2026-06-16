#include "Transaction.h"
#include <sstream>

Transaction::Transaction(){
	transactionID=0;
	bookID=0;
	memberID=0;
	issuedate="";
	returndate="";
	returned=false;
}
 // parameterized constructor
 Transaction::Transaction(int tid,int bid, int mid, string issue, string ret, bool status) {
 	transactionID=tid;
 	bookID=bid;
 	memberID=mid;
 	issuedate=issue;
 	returndate=ret;
 	returned=status;
 }
 // getter
  int Transaction::gettransactionID() const {
 	  return transactionID;
 }
  int Transaction::getbookID() const {
	  return bookID;
}
  int Transaction::getmemberID() const {
  	  return memberID;
  }
  string Transaction::getissuedate() const {
  	  return issuedate;
  }
  string Transaction::getreturndate() const{
  	  return returndate;
  }
  bool Transaction::getreturned() const {
  	  return returned;
  }
  
  // setter
  void Transaction::setreturndate(string date) {
  	returndate=date;
  }
  void Transaction::setreturned(bool status) {
  	returned=status;
  }
  
  // display transaction information
  void Transaction::displaytransaction() const{
  	cout<<"transaction id:"<<transactionID<<endl;
  	cout<<"book id:"<<bookID<<endl;
  	cout<<"member id:"<<memberID<<endl;
  	cout<<"issue date:"<<issuedate<<endl;
  	cout<<"return date:";
  	
  	
  	if (returndate.empty()) {
  		cout<<"not returned";
	  }
	else {
		cout<<returndate;
	}
	if (returned) {
		cout<<"yes";
		
	}
	else {
		cout<<"no";
		
	}
	   cout<<endl;
  	
  }
    // convert obj to string
    string Transaction::serialize() const{
    	return to_string (transactionID) + "," +
    	       to_string (bookID) + ","+
    	       to_string (memberID) + "," +
    	       issuedate + "," +
    	       returndate + "," +
    	       to_string (returned);
	}
	
	// convert string to obj
	  Transaction Transaction::deserialize(string data) {
	  	stringstream ss(data);
	  	string tid,bid,mid,issue,ret,status;
	  	getline (ss,tid,',');
	  	getline (ss,bid,',');
	  	getline (ss,mid,',');
	  	getline (ss,issue,',');
	  	getline (ss,ret,',');
	  	getline (ss,status,',');
	  	
	  	return Transaction (stoi(tid),stoi(bid),stoi(mid),issue,ret,stoi(status));
	  }

