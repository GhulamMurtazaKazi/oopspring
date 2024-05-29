#include<iostream>
using namespace std;
int main ()  {
	int i=1,j,n;
	cout<<"enter a no\n";
	cin>>n;
	while (i<=n) {
		j=1;
		while (j<=n) {
			cout<<i<<" ";
			++j;
		}
		cout<<endl;
		++i;
	}
	return 0;
}
