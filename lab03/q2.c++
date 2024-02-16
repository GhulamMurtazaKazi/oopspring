Establish a class termed "WaterBottle."
This class encompasses attributes like company (manufacturer), color, and water
capacity. The water capacity is recorded in both litres (l) and millilitres (ml).
Define variables and methods for this class, incorporating getters and setters. Additionally,
introduce a method to update the water capacity (both in litters and millilitres) after
prompting the user regarding the amount of water consumed, presuming the input is
consistently in millilitres.
Exhibit the functionality of the water bottle within the main method.

#include<iostream>
using namespace std;
class waterbottle{
	string company,color;
	float capacity_l,capacity_ml;
	public:
		string getcompany() {
			return company;
		}
		string getcolor() {
			return color;
		}
		float getCapacityInL() {
			return capacity_l;
		}
		float getCapacityInMl() {
			return capacity_ml;
		}
		void setcompany(string c) {
			company=c;
		}
		void setcolor(string c) {
			color=c;
		}
		void setcapacity_ml(float cap) {
			capacity_ml=cap;
		}
		void setcapacity_l() {
			capacity_l=capacity_ml/1000;
		}
		void updatecapacity() {
			cout<<"enter the amount of water consumed:"<<endl;
			cin>>capacity_ml;
		}
};
int main () {
	waterbottle mybottle;
	string str;
	float cap;
	cout<<"enter the manufacturer(company) of your bottle\n";
	cin>>str;
	mybottle.setcompany(str);
	cout<<"enter the  color of your  bottle\n";
	cin>>str;
	mybottle.setcolor(str);
	cout<<"enter the current capacity for your bottle\n";
	cin>>cap;
	mybottle.setcapacity_ml(cap);
	mybottle.setcapacity_l();
	cout<<"your bottle brand:"<<mybottle.getcompany()<<endl;
	cout<<"your bottle color:"<<mybottle.getcolor()<<endl;
	cout<<"capacity in ml:"<<mybottle.getCapacityInMl()<<"\ncapacity in litres:"<<mybottle.getCapacityInL()<<endl;
	mybottle.updatecapacity();
	mybottle.setcapacity_l();
	cout<<"capacity in ml:"<<mybottle.getCapacityInMl()<<"\ncapacity in litres:"<<mybottle.getCapacityInL()<<endl;
	return 0;
}
