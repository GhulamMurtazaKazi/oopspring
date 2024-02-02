You are asked to write a C++ program that calculates the Least Common Multiple (LCM)
and Greatest Common Divisor (GCD) of two numbers. Implement two separate recursive
functions, calculateLCM and calculateGCD, each handling the corresponding task.

 #include<iostream>
using namespace std;
int calculateLCM(int a,int b,int i) {
	if (a%b==0) return a;
	a*=i;
	++i;
	return calculateLCM(a,b,i);
}
int calculateGCD(int a,int b,int c) {
	if (a%c==0&&b%c==0) return c;
	return calculateGCD(a,b,--c);
}
int main () {
	int a,b,c;
	cout<<"enter two numbers\n";
	cin>>a>>b;
	if (a>b) {
		c=b;
	cout<<"LCM:"<<calculateLCM(a,b,1)<<endl;
	cout<<"HCF:"<<calculateGCD(a,b,c);
}
else {
	c=a;
	cout<<"LCM:"<<calculateLCM(b,a,1)<<endl;
	cout<<"HCF:"<<calculateGCD(b,a,c);
}
	return 0;
} 
