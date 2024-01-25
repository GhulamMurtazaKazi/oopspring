Q4: You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49.

#include<iostream>
using namespace std;
int area(int i,int j,int a,int b) {
	if (a>=b) 	return b*(j-i);
	else  	return a*(j-i);
}
int main () {
	int n,i=0,j,max=0;
	cout<<"enter the no of lines\n";
	cin>>n;
	int * height= new int[n];
	cout<<"enter the heights\n";
	while (i<n) {
		cin>>height[i];
		++i;
	}
	i=0;
	while (i<n) {
		j=i+1;
		while (j<n) {
			if (area(i,j,height[i],height[j])>max) max=area(i,j,height[i],height[j]);
			++j;
		}
		++i;
	}
	cout<<"ans="<<max;
	return 0;
}
