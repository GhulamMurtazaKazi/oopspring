Craft a class denominated "Calendar."
This Calendar class should possess 12 arrays, each representing a month of the year, along
with a variable storing information about the current year.
Users can allocate tasks for each day, with one entry allowed per day.
Incorporate the following methods within this class:
• Addition of a task: This function accepts task details, date, and month as parameters
and adds the task to the specified day.
• Removal of a task: Accepts the date and month as parameters to eliminate the task.
• Display tasks: This method traverses through all months and prints the allocated
tasks.

Instantiate a calendar object, input 5-6 tasks manually, demonstrate task removal, and display
the updated task list.

#include<iostream>
#include<string>
using namespace std;
class calendar{
	string months[12][31]={{""}};
	int year;
	public:
		void addtask(string str,int i,int j) {
			months[i-1][j-1]=str;
		}
		void removetask(int i,int j) {
				months[i-1][j-1]="";
		}
		void display() {
			int i=0,j;
			cout<<"***Your "<<year<<" to-do lists is***\n";
			while (i<12) {
				j=0;
				while (j<31) {
					if(months[i][j]!="") {
						cout<<j<<"-"<<i<<"-"<<year<<endl;
						cout<<months[i][j]<<endl;
						cout<<"--------\n";		
					}
					++j;
				}
				++i;
			}
		}
		void setyear(int n) {
			year=n;
		}
		int getyear() {
			return year;
		}
};
int main () {
	calendar year_24;
	string str;
	int i,j,choice;
	cout<<"enter the year\n";
	cin>>i;
	year_24.setyear(i);
	while (1) {
		cout<<"enter 1 to add tasks to your to-do lists\n";
		cout<<"enter 2 to remove a tasks from your to-do lists\n";
		cout<<"enter 3 display all to-do lists\n";
		cout<<"enter 4 to exit\n";
		cin>>choice;
		if (choice==1) {
			cout<<"enter the month and date\n";
			cin>>i>>j;
			cin.ignore();
			cout<<"set your tasks for that specific  day\n";
			getline(cin,str);
			year_24.addtask(str,i,j);
		}
		else if(choice==2) {
			cout<<"enter the  month and date\n";
			cin>>i>>j;
			year_24.removetask(i,j);
		}
		else if (choice==3) {
			year_24.display();
		}
		else return 0;
	}
}  
