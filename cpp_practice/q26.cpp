#include<iostream>
using namespace std;
int main ()  {
	int n,i=1,j;
	char ch='A';
	cout<<"enter a no\n";
	cin>>n;
	while (i<=n) {
		j=n;
		while (j>0) {
			cout<<ch<<" ";
			--j;
		}
		cout<<endl;
		ch+=1;
		++i;
	}
	return 0;
}
