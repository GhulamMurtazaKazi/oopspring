#include<iostream>
using namespace std;
int main() {
	int n,i=1,j;
	cout<<"enter a no\n";
	cin>>n;
	while (i<=n) {
		j=1;
		while(j<=(n-(i-1))) {
			cout<<j;
			++j;
		}
		j=2*(i-1);
		while (j) {
			cout<<"*";
			--j;
		}
		j=n-(i-1);
		while (j) {
			cout << j;
			--j;
		}
		++i;
		cout<<endl;
	}
	return 0;
}
