Transform the Office class by replacing the furniture array with a pointer. Modify the
constructor to accept the size of the furniture array instead of the array itself, dynamically
allocating memory for the furniture array within the constructor. Implement a destructor to
deallocate memory allocated for the furniture pointer. In the main function, dynamically allocate
an Office object, pass required values to the constructor, and then delete

#include<iostream>
using namespace std;
class office{
	string location;
	int seatingcapacity;
	string* furniture;
	public:
		office (int size,string str,int capacity) { 
		furniture=new string[size];
		location=str;
		seatingcapacity=capacity;
		int i=0;
		while (i<size) {
			furniture[i]="";
			++i;
	}
		}
		string getlocation() {
			return location;
		}
		int getcapacity() {
			return seatingcapacity;
		}
			string * getfurniture() {
			return furniture;
		}
		~office() {
			delete[] furniture;
		}
};
int main () {
	int size,i=0;
	cout<<"enter the size\n";
	cin>>size;
	office * obj=new office(size," ",0);
			cout<<"location is "<<(*obj).getlocation()<<endl;
			cout<<"seating capacity is "<<(*obj).getcapacity()<<endl;
			cout<<"furniture "<<endl;
			while (i<size) {
				cout<<(*obj).getlocation()[i]<<endl;
				++i;
			}
			return 0;
}
