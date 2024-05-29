Question 01:
Times Medico is committed to providing customers with prescribed medicines
efficiently. With various categories of medicines and specialized staff roles, Times
Medico ensures smooth operations while maintaining revenue. Being a
programmer, You have to design classes with following details
1) Medicine Class: Attributes: name, formula, retail price, manufacture
date, expiration date.
• Functions:
• Constructor(s) to initialize attributes.

• Getters and setters for attributes.
• Virtual function for printing medicine details.

2) Tablet Class (Derived from Medicine): Additional Attribute: sucrose level
(0 to 1).
a. Functions:
i. Constructor(s) to initialize Tablet-specific attributes.
ii. Overridden function for printing tablet details.

3) Capsule Class (Derived from Medicine):
a. Additional Attribute: absorption percentage (1 to 100).
b. Functions:
i. Constructor(s) to initialize Capsule-specific attributes.
ii. Overridden function for printing capsule details.

4) Syrup Class (Derived from Medicine):
• Functions:
• Constructor(s) to initialize Syrup-specific attributes.
• Overridden function for printing syrup details.

5) Pharmacist Class
• Functions:
• Search_Medicine() to search and print medicine details based
on formula.
6) Counter Class
• Functions:
• Search_Medicine() to search and print medicine details based
on name.
• Update_Revenue() to update overall revenue.

• Flow of operation:
The customer enters the medico and presents a prescription to the counter
staff. The counter staff forwards this prescription to the pharmacist who
checks and recommends the appropriate medicine type. The counter staff
then collects the payment, hands over the medicines and updates the overall
revenue.
• Tasks to be performed:
• Identify all the classes, attributes and functions in the above scenario.
Only make a skeleton of classes and give prototypes of functions.
• Overload the "= =" operator to compare two medicines and find if
both are going to expire in the same year.

  #include<iostream>
#include<vector>
#include<string>
using namespace std;
class medicine{
	protected:
		string name,formula,manufacture_date,expiry_date;
		double price;
		public:
		bool operator==(medicine* ptr){
			return expiry_date==ptr->expiry_date;
		}
			medicine(string name,string formula,string manufacture_date,string expiry_date,double price):name(name),formula(formula),manufacture_date(manufacture_date),expiry_date(expiry_date),price(price) { }
			string getname() const { return name; }
			string getformula() const { return formula; }
			string getmanu_date() const { return manufacture_date; }
			string getexp_date() const { return expiry_date; }
			double getprice() const { return price; }
			void setname(string name) { this->name=name; }
			void setformula(string formula) { this->formula=formula; }
			void setmanu_date(string manufacture_date) { this->manufacture_date=manufacture_date; }		
			void setexp_date(string expiry_date) { this->expiry_date=expiry_date; }
			void setprice(double price) { this->price=price; }
			virtual void display() {
				cout<<"name="<<name<<"\nformula="<<formula<<"\nmanufacturing date="<<manufacture_date<<"\nexpiry date="<<expiry_date<<"\nprice="<<price<<endl;
			}
};
class tablet:public medicine{
	double sucrose_level;
	public:
		tablet(string name,string formula,string manufacture_date,string expiry_date,double price,double sucrose_level):medicine(name,formula,manufacture_date,expiry_date,price), sucrose_level(sucrose_level) { }
		void display() override {
		cout<<"name="<<name<<"\nformula="<<formula<<"\nmanufacturing date="<<manufacture_date<<"\nexpiry date="<<expiry_date<<"\nprice="<<price<<"\nsucrose level="<<sucrose_level<<endl;
		}
};
class capsule:public medicine{
	int absorp;
	public:
		capsule(string name,string formula,string manufacture_date,string expiry_date,double price,int absorp):medicine(name,formula,manufacture_date,expiry_date,price), absorp(absorp) { }
		void display() override {
		cout<<"name="<<name<<"\nformula="<<formula<<"\nmanufacturing date="<<manufacture_date<<"\nexpiry date="<<expiry_date<<"\nprice="<<price<<"\nabsorption percentage="<<absorp<<"%"<<endl;
		}
};
class syrup:public medicine{
	double quantity;
	public:
		syrup(string name,string formula,string manufacture_date,string expiry_date,double price,double quantity):medicine(name,formula,manufacture_date,expiry_date,price), quantity(quantity) { }
			void display() override {
		cout<<"name="<<name<<"\nformula="<<formula<<"\nmanufacturing date="<<manufacture_date<<"\nexpiry date="<<expiry_date<<"\nprice="<<price<<"\nquantity="<<quantity<<"mL"<<endl;
		}
};
class pharmicist{
	vector<medicine*>medico;
	public:
		void addmedicine(medicine* ptr) {
			medico.push_back(ptr);
		}
		double search(string str) {
			for (int i=0;i<medico.size();++i) {
				if (medico[i]->getname()==str) {
					medico[i]->display();
					return medico[i]->getprice();
				}
			}
			cout<<"medicine not found in the stock\n";
			return 0;
		}
};
class counter{
	double revenue=0;
public:
	void take_order(pharmicist& p) {
		string str;
		int n;
		cout<<"can you please share your prescription?\n";
		cin>>str;
		cout<<"enter the number\n";
		cin>>n;
		revenue+=(n*p.search(str));
	}
};
int main () {
	int t,c,s;
	counter reception;
	pharmicist p;
	cout<<"enter no of tablets, capsules and syrups\n";
	cin>>t>>c>>s;
	cin.ignore();
	for (int i=0;i<t;++i) {
	string name,formula,manufacture_date,expiry_date;
	double price,sucrose_level;
	cout<<"enter the details for the  "<<i+1<<" tablet"<<endl;
	getline(cin,name);
	getline(cin,formula);
	getline(cin,manufacture_date);
	getline(cin,expiry_date);
	cin>>price;
	cin>>sucrose_level;
	cin.ignore();
	tablet* obj = new tablet(name,formula,manufacture_date,expiry_date,price,sucrose_level);
	p.addmedicine(obj);
	}
	for (int i=0;i<c;++i) {
	string name,formula,manufacture_date,expiry_date;
	double price;
	int absorp;
	cout<<"enter the details for the  "<<i+1<<" capsule"<<endl;
	getline(cin,name);
	getline(cin,formula);
	getline(cin,manufacture_date);
	getline(cin,expiry_date);
	cin>>price;
	cin>>absorp;
	cin.ignore();
	capsule* obj = new capsule(name,formula,manufacture_date,expiry_date,price,absorp);
	p.addmedicine(obj);
	}
	for (int i=0;i<s;++i) {
	string name,formula,manufacture_date,expiry_date;
	double price,quantity;
	cout<<"enter the details for the  "<<i+1<<" syrup"<<endl;
	getline(cin,name);
	getline(cin,formula);
	getline(cin,manufacture_date);
	getline(cin,expiry_date);
	cin>>price;
	cin>>quantity;
	cin.ignore();
	syrup* obj = new syrup(name,formula,manufacture_date,expiry_date,price,quantity);
	p.addmedicine(obj);
	}
	// assuming number of customers in a day to be 5
	cout<<"--------------------welcome to medico pharmacy--------------------\n";
	for (int i=0;i<5;++i) {
		reception.take_order(p);
		cout<<"--------------------welcome to medico pharmacy--------------------\n";
	}
	return 0;
}
