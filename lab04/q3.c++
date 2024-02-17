Develop a class called WeekDays containing private data members - a string array named Days
for the days of the week and an integer variable named CurrentDay for the current day. Create
the following constructors and member functions for the class: a Default Constructor initializing
the Days array from Sunday to Saturday, a Parameterized Constructor accepting an integer value
for CurrentDay, performing a modulus operation to adjust if the value exceeds 6, and initializing
the Days array accordingly. Additional member functions include getCurrentDay, getNextDay,
getPreviousDay, and getNthDayFromToday.

  #include<iostream>
using namespace std;
class weekdays{
	string days[7];
	int currentday;
	public:
		weekdays() {
			days[0]="sunday";
			days[1]="monday";
				days[2]="tuesday";
					days[3]="wednesday";
						days[4]="thursday";
							days[5]="friday";
								days[6]="saturday";
		}
		weekdays(int d) {
			currentday=d;
		}
		int getcurrentday() {
			return currentday;
		}
		int getnextday() {
			if (currentday+1<=6) return currentday+1;
			else return 0;
		}
		int getpreviousday() {
			if (currentday-1>=0) return currentday-1;
			else return 6;
		}
		int getNthDayFromToday(int n)  {
			if (currentday+n<=6) return currentday+n;
			else return (currentday+n)-7;
		}
};
int  main() {
	weekdays obj;
	int n;
	cout<<"enter the current day\n";
	while (1) {
	cin>>n;
	n--;
	if (n==0||6%n!=6) break; 
	cout<<"enter a valid input\n";
}
	obj=weekdays(n);
	cout<<"the current day is "<<obj.getcurrentday()+1<<" day of the week"<<endl;
	cout<<"the next day is the "<<obj.getnextday()+1<<" day of the week\n";
	cout<<"the previous day is the "<<obj.getpreviousday()+1<<" day of the week\n";
	cout<<"enter n\n";
	cin>>n;
	cout<<"the "<<n<<" days from the current day is "<<obj.getNthDayFromToday(n)+1<<" day of the week"<<endl;
	return 0;
}
