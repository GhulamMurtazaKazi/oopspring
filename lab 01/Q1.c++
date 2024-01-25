Q1: Write a C++ program to check whether a given number is prime or not. Allow
the user to input a number and display whether it's prime or not?

#include<iostream>
using namespace std;
int main () {
	int n,i=2;
	cout<<"enter a no\n";
	cin>>n;
	if (n==1||n==0) {
	 cout<<"not prime";
	 return 0;
}
	while (i<n) {
		if (n%i==0) {
			cout<<"not prime";
			return 0;
		}
		++i;
	}
	cout<<"prime no";
	return 0;
}
