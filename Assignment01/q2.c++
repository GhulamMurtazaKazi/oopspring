You’re bored!
You’re looking at the students going in and out of the seating at the dhaba at FAST. You decide to think of
it as an OOP Scenario! You’re looking at the group of students arriving at the tables outside of the dhaba,
and making mental note of how long each group of student stays at a table. For the above scenario, let’s
write a program about the tables at the dhaba.
1. Each table has some properties:
● Total available seats per table (A table can only have 4 or 8 seats)
● Seats currently occupied at a table (assume only one person can occupy one seat)
● Free seats at a table
● Clean (Boolean flag representing the cleanliness of the table)
2. Each table can have some functionality associated with them:
● A default constructor – which should set the default table capacity to 4. Initially, a table will be
clean and no one will be seated on it.
● A parameterized constructor – which should set the capacity to the capacity sent as parameter. If
the number is not 4 or 8, it should be rounded to 4 or 8 (whichever is closest).
● Initially, a table will be clean and no one will be seated on it.
● Encapsulate the parameters of your class properly. The capacity should not be editable once it has
been set by the constructor.
● A table can be used by a group of friends – In order for the table to be used, the table must first be
clean. Whenever a group of friends is using the table, they will decide to use the table that can fit a
group of that size. (A group of 4 will be seated at a table with 4 seats, meanwhile a group of 6 will
be seated at a table with 8 seats).
● People can have lunch on the table – once the lunch is finished, the table will no longer be clean.
● People can leave the table with or without having lunch.
● Someone can clean the table – the table can only be cleaned when no one is seated at the table.
3. Create a global function called “OccupyTable” that accepts a Table array and size of the group of friends.
It should find a table that is not occupied and assign a table to those people. It should mention which table
has been assigned the group, and the seating capacity of the table.
4. Create a global function called “EmptyTable” that accepts a table number and sets it to empty. This
should make proper changes to the variables present within that table object.
5. In your main function, you are required to perform the following actions with your Table class:
● Create an array of 5 tables.
○ Two tables should be of capacity 8, and 3 should be of capacity 4.
● Call the function OccupyTable and pass the array and 4 as its parameters. (Assume this is table 1)
● Call the function OccupyTable and pass the array and 6 as its parameters. (Assume this is table 2)

● For table 1, call the functions for:
○ Using the table
○ Having lunch on the table
○ Leaving the table
○ Cleaning the table
● Call the function EmptyTable and pass the index of table 2 as its parameter.

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
