#include<iostream>
using namespace std;
int main () {
	int n,i=1,j;
	cout<<"enter a no\n";
	cin>>n;
	while (i<=n) {
		j=1;
		while (j<=i) {
			cout<<"* ";
			++j;
		}
		cout<<endl;
		++i;
	}
	return 0;
}
