#include<iostream>
using namespace std;
int main () {
	int n,i=1,j;
	char ch='A';
	cout<<"enter a no\n";
	cin>>n;
	while (i<=n) {
		j=1;
		while (j<=i) {
			cout<<ch<<" ";
			++ch;
			++j;
		}
		cout<<endl;
		++i;
	}
	return 0;
}
