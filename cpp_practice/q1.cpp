#include<iostream>
using namespace std;
int main () { 
	char a;
	cout<<"enter a char\n";
	cin>>a;
	if (a>=47&&a<=56) cout<<"it is a digit";
	else if (a>=65&&a<=91) cout<<"it is uppercase";
	else if (a>=97&&a<=123) cout<<"it lowercase";
	else cout<<"it is a special character";
	return 0;
}
