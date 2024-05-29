#include<iostream>
using namespace std;
int main () {
	int i=1,n,j;
	char ch;
	cout<<"enter a no\n";
	cin>>n;
	while (i<=n) {
		j=1;
		while (j<=n) {
			ch='A'+j-1;
			cout<<ch<<" ";
			++j;
		}
		cout<<endl;
		++i;
	}
	return 0;
}
