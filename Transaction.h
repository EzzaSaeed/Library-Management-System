#ifndef Transaction_h
#define Transaction_h
#include <iostream>
#include <string>
using namespace std;

  class Transaction{
  	private:
  		int transactionID;
  		int bookID;
  		int memberID;
  		string issuedate;
  		string returndate;
  		bool returned;
  	public:
  		Transaction();
  		Transaction (int tid, int bid, int mid,string issue, string ret="", bool status=false );
  		// getter
  		int gettransactionID() const;
  		int getbookID () const;
  		int getmemberID () const;
  		string getissuedate () const;
  		string getreturndate() const;
  		bool getreturned () const;
  		
  		// setter
  		void setreturndate (string date);
  		void setreturned (bool satus);
  		
  		// function
  		void displaytransaction () const;
  		//file handling
  		string serialize () const;
  		static Transaction deserialize (string data);
  		
  		
  };
  
  #endif
