

#include<iostream>
using namespace std;
int count=0;
class table{
	int total;
	int occupied;
	int free;
	bool flag;
	public:
		table() {
			total=4;
			flag=true;
			occupied=0;
			free=total;
		}
		table(int n) {
			if (n==4||n==8) total=n;
			else if (4-n>0) total=4;
			else total=8;
			flag=true;
			occupied=0;
			free=total;
		}
		int gettotal() {
			return total;
		}
		int getoccupied() {
			return occupied;
		}
		bool getflag() {
			return flag;
		}
		void setoccupied(int n) {
			occupied=n;
		}
		void setfree() {
			free=total-occupied;
		}
		void setflag() {
			flag=true;
		}
		void havinglunch() {
			flag=false;
		}
		
};
void emptytable(table* array,int n) {
	array[n].setoccupied(0);
	array[n].setfree();
}
void occupytable(table* array,int size) {
	int i=0;
	while (i<5) {
		if (size<=4) {
			if (array[i].gettotal()==4&&array[i].getoccupied()==0) {
					array[i].setflag();
				count++;
				cout<<"table no:"<<count<<" is available for you that has capacity of "<<array[i].gettotal()<<endl;
				array[i].setoccupied(size);
					array[i].setfree();
				return ;
			}
			//Incase, if all the tables having the capacity of 4 or less are all occupied then we would have to look for the table with 8 chairs
			else {
				if (array[i].gettotal()==8&&array[i].getoccupied()==0) {
					array[i].setflag();
						count++;
				cout<<"table no:"<<count<<" is available for you that has capacity of "<<array[i].gettotal()<<endl;
					array[i].setoccupied(size);
					array[i].setfree();
				return ;
			}
			}
		}
		else {
			if (array[i].gettotal()==8&&array[i].getoccupied()==0) {
					array[i].setflag();
					count++;
				cout<<"table no:"<<count<<" is available for you that has capacity of "<<array[i].gettotal()<<endl;
					array[i].setoccupied(size);
						array[i].setfree();
				return ;
			}
		}
		++i;
	}
	cout<<"oops, no table for you bruh!!"<<endl;
}
int main () {
	table mydhaba[5];
	mydhaba[3]=table(8);
		mydhaba[4]=table(8);
		occupytable(mydhaba,4);
		occupytable(mydhaba,6);
		emptytable(mydhaba,3);
			mydhaba[3].havinglunch();
		cout<<"for table 1:"<<endl;
		cout<<"total capaity:"<<mydhaba[0].gettotal()<<endl;
		cout<<"seats occupied:"<<mydhaba[0].getoccupied()<<endl;
		cout<<"seats free:"<<mydhaba[0].gettotal()-mydhaba[0].getoccupied()<<endl;
		cout<<"cleanliness:"<<mydhaba[0].getflag()<<endl;
		cout<<"for table 2:"<<endl;
		cout<<"total capaity:"<<mydhaba[3].gettotal()<<endl;
		cout<<"seats occupied:"<<mydhaba[3].getoccupied()<<endl;
		cout<<"seats free:"<<mydhaba[3].gettotal()-mydhaba[3].getoccupied()<<endl;
		cout<<"cleanliness:"<<mydhaba[3].getflag()<<endl;
	return 0;
}
