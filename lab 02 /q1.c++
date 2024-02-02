Your assignment is to develop a C++ function that interchanges the values of two
variables. Construct a recursive function called recursiveSwap that accepts two
variables as arguments and swaps their values recursively.

  #include<iostream>
using namespace std;
void swap(int * a,int * b) {
	if (*a==*b) 
		return ;
	--(*a);
	swap(a,b);
	++(*b);
}
int main () {
	int a,b;
	cout<<"enter two numbers\n";
	cin>>a>>b;
	if (a>b)
	swap(&a,&b);
	else swap(&b,&a);
	cout<<"a="<<a<<",b="<<b;
	return 0;
}
