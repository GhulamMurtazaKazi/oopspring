You are a software developer working on a project that requires you to design a system for
managing different types of bank accounts. You need to create a base class called Account
that has common attributes and methods for all types of accounts, such as account number,

balance, and deposit/withdrawal methods. However, the interest calculation and account-
specific rules vary depending on the type of account (e.g., savings, current, credit). Create an

abstract class Account with pure virtual functions for interest calculation and account-
specific rules, and then create concrete subclasses for each type of account.

Write the C++ code for the Account abstract class and two concrete subclasses,
SavingsAccount and CurrentAccount.
 Abstract Class: Account
o Data Members:
 accountNumber (int)
 balance (double)
o Member Functions:
 deposit(amount) (pure virtual)
 withdraw(amount) (pure virtual)
 calculateInterest() (pure virtual)

 getAccountNumber() (concrete)
 getBalance() (concrete)
 Concrete Subclass: SavingsAccount
o Data Members:
 interestRate (double)
o Member Functions:
 deposit(amount) (overrides Account::deposit)
 withdraw(amount) (overrides Account::withdraw)
 calculateInterest() (overrides Account::calculateInterest)

 Concrete Subclass: CurrentAccount
o Data Members:
 overdraftLimit (double)
o Member Functions:
 deposit(amount) (overrides Account::deposit)
 withdraw(amount) (overrides Account::withdraw)
 calculateInterest() (overrides Account::calculateInterest)

#include<iostream>
using namespace std;
class account{
	protected:
		int acc_no;
		double balance;
	public:
		account(int acc_no = 0, double balance = 0) : acc_no(acc_no), balance(balance) { }
		virtual	void deposit(double amount) = 0;
		virtual void withdraw(double amount) = 0;
		virtual double calculateinterest() = 0;
		int getno() const { return acc_no; }
		double getbalance() const { return  balance; }
};
class savingaccount:public account{
	double interestrate=5;
	public:
		savingaccount(int acc_no = 0, double balance = 0) : account(acc_no, balance) { }
		void deposit(double amount) override {
			balance+=amount;
			cout<<"deposited successfully\n";
		}
		void withdraw(double amount) override{
			if (balance-amount>=0) 
				balance-=amount;
			else 
			cout<<"not sufficient balance\n";
		}
		double calculateinterest() override {
		return (balance*interestrate);
		}
};
class currentaccount:public account{
	double overdraftlimit=200;
	public:
		currentaccount(int acc_no = 0, double balance = 0) : account(acc_no, balance) { }
			void deposit(double amount) override {
			balance+=amount;
			cout<<"deposited successfully\n";
		}
		void withdraw(double amount) override {
			if ((balance+overdraftlimit)-amount>=0) {
				if (amount<balance) balance-=amount;
				else {
					amount-=balance;
					balance=0;
					overdraftlimit-=amount;
				}
			}
			else 
			cout<<"insufficient balance\n";
		}
	double calculateinterest() override {
	return (balance*10);
	}	
};
int main() {
	 // lets say our online portal can only entertain 5 users in a day
	 currentaccount obj1;
	 savingaccount obj2;
	  account* ptr1=&obj1;
	  account* ptr2=&obj2;
	 int i=0,n;
	 cout<<"-------------------kazi bank limited online portal-----------------------------\n";
	 while (i<5) {
	 	while (1) {
	 cout<<"enter 1 to create your current account\nenter 2 to your saving account\nenter 3 to deposit\nenter 4 withdraw\nenter 5 to calculate interest\nenter 6 to view balance\nenter 7 to exit\n";
	 cin>>n;
	 if (n==1) {
	 	double a;
	 	cout<<"enter you account number and balance\n";
	 	cin>>n>>a;
	 	obj1=currentaccount(n,a);
	 }
	 if (n==2) {
	 	double a;
	 	cout<<"enter you account number and balance\n";
	 	cin>>n>>a;
	 	obj2=savingaccount(n,a);
	 }
	 if (n==3) {
	 	cout<<"choose account\n";
	 	cin>>n;
	 	cout<<"enter the amount\n";
	 	double amount;
	 	cin>>amount;
	 	if (n==1) 
	 	ptr1->deposit(amount);
	 	else 
	 	ptr2->deposit(amount);
	 }
	 if (n==4) {
	 	cout<<"choose account\n";
	 	cin>>n;
	 	cout<<"enter the amount\n";
	 	double amount;
	 	cin>>amount;
	 	if (n==1) 
	 	ptr1->withdraw(amount);
	 	else 
	 	ptr2->withdraw(amount);
	 }
	 if (n==5) {
	 	cout<<"choose account\n";
	 	cin>>n;
		 if (n==1) 
		 	cout<<"interest ="<<ptr1->calculateinterest()<<endl;
		 	else 
			 cout<<"interest = "<<ptr2->calculateinterest()<<endl;	
	 }
	 if  (n==6) {
	 	cout<<"choose account\n";
	 	cin>>n;
	 	if (n==1) cout<<"your balance in the current account is "<<ptr1->getbalance()<<endl;
	 	else cout<<"your balance in the savings account is "<<ptr2->getbalance()<<endl;
	 }
	 if (n==7) break;
}
++i;
	 cout<<"-------------------kazi bank limited online portal-----------------------------\n";
}
return 0;
}
