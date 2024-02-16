Develop a class named "BoardMarker" possessing the subsequent characteristics:
• Brand (such as Dollar, etc.)
• Shade (black, red, etc.)
• Refillable (Boolean - indicating whether it can be refilled or not)
• Ink Status (Boolean - indicating if the ink is depleted or not)
Formulate appropriate getter and setter methods for the attributes of this class.
Additionally, implement the following methods:
• A writing method with a check to verify if the ink has run out. This method should
exhibit an appropriate message based on the ink status.
• A refill method for the board marker. This method should first confirm if the marker
is refillable or not and then display a relevant message.
Illustrate the class functionality by creating an object, setting the values, and then invoking the
methods.

#include<iostream>
using namespace std;
class boardmarker{
	string brand;
	string shade;
	bool refillable;
	bool ink_status;
	public:
		void setbrand(string b) {
			brand=b;
		}
		void setshade(string s) {
			shade=s;
		}
		void setrefill(bool flag) {
			refillable=flag;
		}
		void ink(bool flag) {
			ink_status=flag;
		}
		string getbrand() {
			return brand;
		}
		string getshade() {
			return shade;
		}
		bool getrefillable() {
			return refillable;
		}
		bool getink()  {
			return ink_status;
		}
		void writing() {
			if (ink_status==true) cout<<"The ink has run out\n";
			else cout<<"The ink hasnot run out\n";
		}
		void refill() {
			if (refillable==true) ink_status=true;
			else cout<<"The pen is non-refillable\n";
		}
};
int main ()  {
	boardmarker pen;
	string str;
	bool flag;
	cout<<"enter the brand of your pen\n";
	cin>>str;
	pen.setbrand(str);
	cout<<"enter the shade of your pen\n";
	cin>>str;
	pen.setshade(str);
	cout<<"is your pen refillable?\n";
	cin>>flag;
	pen.setrefill(flag);
		cout<<"is ink depleted?\n";
	cin>>flag;
	pen.ink(flag);
	cout<<"\nYour pen brand:"<<pen.getbrand()<<endl;
	cout<<"shade:"<<pen.getshade()<<endl;
	cout<<"Refillable:"<<pen.getrefillable()<<endl;
	cout<<"ink depleted:"<<pen.getink()<<endl;
	pen.writing();
	pen.refill();
	return 0;
}
