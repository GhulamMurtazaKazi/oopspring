Q3: Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may
not use the same element twice.You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

  #include<iostream>
using namespace std;
int main () {
	int no,target,i=0,j;
	cout<<"enter total no.of integers and target\n";
	cin>>no>>target;
	int * arr=new int[no];
	cout<<"enter the integers:";
	while (i<no) {
		cin>>arr[i];
		++i;
	}
	i=0;
	while (i<no) {
		j=i+1;
		while (j<no) {
			if (arr[i]+arr[j]==target) {
				cout<<arr[i]<<"+"<<arr[j]<<"="<<target<<endl;
				cout<<"["<<i<<","<<j<<"]";
				return 0;
			}
			++j;
		}
		++i;
	}
	cout << "no pair found";
	return 0;
}
