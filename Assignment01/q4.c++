Scenario 4:
You’re being hired to write an application for different rides in a Theme Park. You’re working on the Roller
Coaster(woohoo!!). The Theme Park has provided you with the relevant attributes for your Roller Coaster
class, and they are as follows:
● Name (of the attraction- some creative name)
● Height (maximum height that the roller coaster can reach)
● Length (total length of the roller coaster track)
● Speed (of the roller coaster)
● Capacity (amount of people that can be seated at once)
● CurrentNumRiders (number of passengers/riders currently seated in the roller coaster)
● RideInProgress (a Boolean flag, depicting whether the ride is currently in progress or not)
For the functionality, they have provided the following information:
● Constructors:
● Default – Should set the name to “roller coaster”, height to 500 meters, length to 2000 meters, and
capacity to 20 people. The ride should not be in progress by default.

● Parameterized – Should set the values as provided by the user. However, it should not accept a
Boolean to change the ride in progress flag. It should also verify if the capacity of people is in
multiples of two or three, if it is not a multiple of two or three, it should roundit to the closest
multiple of two. In addition to that, the capacity should always be greater than 3.
● Appropriate Getter and Setter functions for the available variables. The same checks should be
applied for the capacity variable, as applied in the parameterized constructor.
● A function to load/seat the riders into the roller coaster – Passengers/Riders can only be seated into
the roller coaster if the ride is not in progress, and if there is sufficient space for all the riders.In
case there is an excess number of riders compared to the available spaces, it should return the
number of riders that were not seated successfully, otherwise it should return 0.
● A function to start the ride – This function can only be called if a ride is not in progress, if a ride is
in progress, it should return -1. If a ride is not in progress, it needs to verify that all the seats have
been occupied by the riders. In case all the seats are not occupied, it should return the number of
empty seats.
● A function to stop the ride – This function can only be called if a ride is in progress. This will stop
the ride.
● A function to unload the riders from the roller coaster – Passengers/Riders can only be unloaded
from the roller coaster if they ride is not in progress.
● A function to accelerate the roller coaster – Every time this function is called, it should increase the
speed of the roller coaster by the last non-zero digit of your roll number (If your roll number is
2034 or 2040, it should increase the speed by 4)
● A function to apply brakes to slow down the roller coaster – Every time this function is called, it
should decrease the speed of the roller coaster by the first non-zero digit of your roll number. (If
your roll number is 2034 or 0203, it should decrease the speed by 2)
In your main function, create two roller coaster objects by using both the constructors. Use the second
object to demonstrate that your roller coaster adheres to all the conditions specified in this question.

#include<iostream>
#include<string>
using namespace std;
class rollercoaster {
	string name;
	float height,length,speed;
	int capacity,CurrentNumRiders;
	bool flag;
	public:
		rollercoaster() {
			name="roller coaster";
			height=500;
			length=2000;
			capacity=20;
			speed=0;
			CurrentNumRiders=0;
			flag=false;
		}
		rollercoaster(string str,float h,float l,int c) {
			name=str;
			height=h;
			length=l;
			if ((c%2==0)||(c%3==0)) 
			capacity=c;
			else capacity=c+1;
		}
		string getname() {
			return name;
		}
		float getheight() {
			return height;
		}
		float getlength() {
			return length;
		}
		int getcapacity() {
			return capacity;
		}
		float getspeed() {
			return speed;
		}
		int getriders() {
			return 	CurrentNumRiders;
		}
		bool getflag() {
			return flag;
		}
		void setname(string str) {
			name=str;
		}
		void setheight(float h) {
			height=h;
		}
		void setlength(float l) {
			length=l;
		}
		void accelerate (int s) {
			speed+=s;
		}
		void declerate(int s) {
			if (speed-s<=0) {
				speed=0;
				return ;
			}
			speed-=s;
		}
		void setcapacity(int c)  {
		if ((c%2==0)||(c%3==0)) 
			capacity=c;
			else capacity=c+1;
		}
		void  setriders(int n) {
			CurrentNumRiders=n;
		}
		void setflag(bool f) {
			flag=f;
		}
};
int loadriders(rollercoaster& ob2,int riders) {
	if (riders<=ob2.getcapacity()) {
		ob2.setriders(riders);
		return 0;
	}
	else {
	ob2.setriders(ob2.getcapacity());
	return (riders-ob2.getcapacity());
}	
}
int startride(rollercoaster& ob2,int riders) {
	ob2.setflag(true);
		if (riders<ob2.getcapacity()) {
		return (ob2.getcapacity()-riders);
	}
	else return -1;
}
void stopride(rollercoaster& ob2) {
	ob2.setflag(false);
}
void unload(rollercoaster& ob2) {
	ob2.setriders(0);
}
int main () {
	rollercoaster ob1,ob2;
	string str;
	float h,l;
	int c,riders,i=0;
	bool flag;
		cout<<"enter the details for the "<<2<<" coaster"<<endl;
		cout<<"enter the name:"<<endl;
		getline(cin,str);
		cout<<"enter the height and length:\n";
		cin>>h>>l;
		cout<<"enter the capacity:\n";
		while (1) {
			cout<<"The capacity should be greater than 3\n";
			cin>>c;
			if (c>3) break; 
		}
		ob2=rollercoaster(str,h,l,c);
		//Assuming that a rollercoaster can have 5 turns in a day in the total duration of the amusement park
		while (i<5) {	
			cout<<"proceeding for  the "<<i+1<<" turn"<<endl;
			cout<<"welcome on the "<<ob2.getname()<<" coaster\n";
			cout<<"please enter the number of riders:\n";
			cin>>riders;
			if (loadriders(ob2,riders)==0) {
				cout<<"All the riders have been seated successfully\n";
			}
			else {
				cout<<loadriders(ob2,riders)<<" riders couldnot find a seat\n";
			}
			cout<<"The ride is about to start have fun\n";
			if (startride(ob2,riders)!=-1) {
				cout<<startride(ob2,riders)<<" seats are left unoccupied\n";
			}
			cout<<"Accelerating the ride:"<<endl;
			ob2.accelerate(2);
			cout<<"speed:"<<ob2.getspeed()<<endl;
			cout<<"Now decelerating\n";
			ob2.declerate(2);
			cout<<"speed:"<<ob2.getspeed()<<endl;
			stopride(ob2);
			cout<<"the ride is stoped"<<endl;
			unload(ob2);
					++i;
					}
	return 0;
}
