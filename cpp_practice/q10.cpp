#include<iostream>
using namespace std;
int main () {
	int n,i=1,j,k;
	cout<<"enter a no\n";
	cin>>n;
	while(i<=n) 
	{ 
		j=i;
		k=1;
		while (k<=i) {
			cout<<j<<" ";
			++k;
		}
		cout<<endl;
		++i;
	} 
	return 0;
}
