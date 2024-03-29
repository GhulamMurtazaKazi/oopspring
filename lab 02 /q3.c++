You’re given an integer array and a target sum. Your job is to write a recursive function
in C++ that checks if there’s a subset of the array whose elements sum up to the target
sum. • Develop a recursive function named hasSubsetSum that accepts an integer array,
the array’s size, and a target sum as input and returns a boolean indicating whether a
subset with the specified sum exists. • The function should have the following signature:
bool hasSubsetSum(int arr[], int size, int targetSum).

#include<iostream>
using namespace std;
int i=0,j=1;
bool hasSubsetSum(int * arr,int n,int target) {
	if (i==n) return false ;
	if (arr[i]+arr[j]==target) 
		return true;
	if (j==n) {
		++i;
		j=i+1;
	}
	else {
		++j;
	}
	return hasSubsetSum(arr,n,target);
}
int main  () {
	int n,target;
	cout<<"enter the size of the array and target sum\n";
	cin>>n>>target;
	int*arr=new int[n];
	cout<<"enter the numbers\n";
	while (i<n) {
		cin>>arr[i];
		++i;
	}
	i=0;
	cout<<hasSubsetSum(arr,n,target);
	 return 0;
}

