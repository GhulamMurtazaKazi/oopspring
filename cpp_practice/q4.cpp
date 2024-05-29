#include<iostream>
using namespace std;
int main () {
	int n,i=2;
	cout<<"enter a no\n";
	cin>>n;
	if (n==1||n==0) {
		cout<<"not a prime no";
		return 0;
	}
	while (i<n) {
		if (n%i==0) {
			cout<<"not a prime no";
			return 0;
		}
		++i;
	}
	cout<<"prime no";
	return 0;
}
