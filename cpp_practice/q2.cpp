#include<iostream>
using namespace std;
int main () {
	int i=2,sum=0,n;
	cout<<"enter a no\n";
	cin>>n;
	while (i<=n) {
		sum+=i;
		i+=2;
	}
	cout<<sum;
	return 0;
}
