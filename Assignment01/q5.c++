Your task is to create a platform dedicated to connecting users with exciting BOGO (Buy One Get One)
deals offered by restaurants. This platform will make it effortless for people to discover and enjoy special
offers from various restaurants, allowing them to savor delicious meals with the added bonus of getting
another one for free.
Restaurant Class encapsulates key details and functionalities related to each restaurant. Features include:
restaurant_name, location, menu_list, price_list, valid_coupon_codes_list, and coupons_redeemed_count
(static variable),a static variable tracking the total number of coupons redeemed across all instances of the
Restaurant class.
Restaurant class must have following member functions:
● display_menu()
● generate_bill()
● apply_discount()

BOGOCoupon Class includes features related to coupons such as:
● coupon_code: Alphanumeric code representing the unique identity of each coupon.
● valid_from: The start date when the coupon becomes active.
● valid_until: The expiration date marking the end of the coupon's validity.
● restaurant_code: The prefix indicating the associated restaurant.
It must have the is_valid Method which validates whether the coupon is within its validity period. Also
checks if the coupon is associated with the selected restaurant.
User Class must have the following attributes name, age, mobile_number, coupons_list: A list containing
the BOGO coupons accumulated by the user, and redeemed_coupons_list.
It must have the following member functions:
● Accumulate_coupon(): Adds a new coupon to the user's list, acquired through various activities or
promotions.
● Has_valid_coupon(): Checks if the user has a valid unredeemed coupon for a specific restaurant
and item.
● redeem_coupon(): Validates the coupon code and ensures it hasn't been previously redeemed.
Main Details:
Two restaurants, namely Food Haven and Pixel Bites, are established with distinctive characteristics. Food
Haven, located in the City Center, offers a fusion of delightful dishes such as Sushi, Pad Thai, and Mango
Tango. On the other hand, Pixel Bites, situated in Cyber Street, entices users with its Digital Delicacies like
Binary Burger, Quantum Quinoa, and Data Donuts.
Users are invited to explore the diverse menu offerings of Food Haven and Pixel Bites through the
display_menu method. BOGO coupons are introduced with restaurant-specific codes. For instance, a

coupon with the code "FH-BOGO-12345" is associated with Food Haven, and another with "PB-BOGO-
67890" is linked to Pixel Bites. When placing an order, users employ the redeem_coupon process. The

system validates the coupon code, ensuring it corresponds to the selected restaurant and has not been
previously redeemed. Successful redemption allows users to enjoy a delightful BOGO offer on their orders,
contributing to a rich and immersive dining experience.

#include<iostream>
#include<string>
using namespace std;
int count;
class Restaurant;
class user;
class BOGOcoupon{
	string coupon_code,restaurant_code;
	int valid_from,valid_until;
	public:
		bool is_valid(int date) {
			if (date>=valid_from&&date<=valid_until) {
			return true;	
			}
			return false;
		}
		friend class Restaurant;
		friend class user;
};

class Restaurant{
	string name,location,menu[3];
	float price[3];
	BOGOcoupon * valid_codes_list;
	static int coupons_redeemed_count;
	public:
		int noOfCodes;
			friend class user;
		Restaurant() {
			
		}
		void setlist() {
				cout<<"enter the valid BOGOcoupon lists for "<<name<<endl;
				int i=0;
				cout<<"enter the number of codes\n";
				cin>>noOfCodes;
				cin.ignore();
				valid_codes_list=new BOGOcoupon[noOfCodes];
				while (i<noOfCodes) {
					cout<<"enter the coupon code for the "<<i+1<<" coupon\n";
					cin>>valid_codes_list[i].coupon_code;
					cout<<"this code must be from\n";
					cin>>valid_codes_list[i].valid_from;
					cout<<"this code is valid until\n";
					cin>>valid_codes_list[i].valid_until;
					valid_codes_list[i].restaurant_code=valid_codes_list[i].coupon_code.substr(0,2);
					++i;
				}
		}
		Restaurant(string str,string address,string * food,float cost[3]) {
			name=str;
			location=address;
			for (int i=0;i<3;++i)  
			menu[i]=food[i];
			for (int i=0;i<3;++i)  
			price[i]=cost[i];
		}
		void display_menu() {
			int i=0;
			cout<<"menu\n";
			while (i<3)  {
				cout<<menu[i]<<" with price="<<price[i]<<endl;
				++i;
			}
		}
		string* place_order(int n) {
			string*str;
			int i=0;
			str=new string[n];
			cout<<"please place your order\n";
			while (i<n) {
				getline(cin,str[i]);
				++i;
			}
			return str;
		}
		float generate_bill(string*str,int n) {
		int i=0,j,k,quantity=0;
		float total=0;
			cout<<"^^^^YOUR BILL^^^^"<<endl;
		while (i<n) { 
		if (str[i]=="--") {
			++i;
			continue;
		}
			j=0;
			while (j<3) {
				if (str[i]==menu[j]) {
				total+=price[j];
				quantity++;
				break;
			}
			++j;
			}
			k=i+1;
			while (k<n) {
				if (str[i]==str[k]) {
					quantity++;
					str[k]="--";
					total+=price[j];
				}
				++k;
			}
			cout<<str[i]<<" with a price of "<<price[j]<<" , quantity="<<quantity<<endl;
			quantity=0;
			++i;
		}
		return total;
		}
};
int Restaurant::coupons_redeemed_count=0;
class user{
	string name,number;
	int age;
	string * coupon_list;
	string * redeemed_coupons;
	public:
	user() { }
		user(string str,string num,int a,int n,int red) {
			name=str;
			number=num;
			age=a;
			coupon_list=new string[n];
			redeemed_coupons=new string[red];
		}
		void accumulate_coupon(int n,int red){
			int i=0;
			if (n>0) 
				cout<<"enter the BOGO codes you have collected to grab exciting offers hurry up!!\n";
			while (i<n) {
			getline(cin,coupon_list[i]);
				++i;
			}
			i=0;
			if (red>0) 
				cout<<"enter the BOGO codes you have redeemed already\n";
			while (i<red) {
			getline(cin,redeemed_coupons[i]);
				++i;
			}
		}
		void Has_valid(Restaurant test,int n,int red,int date) { 
		int i=0,j;
		while (i<n) {
			j=i+1;
			while  (j<n) {
				if (coupon_list[i]==coupon_list[j]) coupon_list[j]="--";
				++j;
			}
			++i;
		}
		i=0;
		while (i<n) { 
		j=0;
		while (j<red) {
			if (coupon_list[i]==redeemed_coupons[j]) coupon_list[i]="--";
			++j;
		}
		++i;
		}   
		i=0;
		while (i<n) {
			j=0;
			while (j<test.noOfCodes) {
				if (coupon_list[i]==test.valid_codes_list[j].coupon_code) {
					if (test.valid_codes_list[j].is_valid(date)==false)  coupon_list[i]="--";
				break;
				}
				++j;
				if (j==test.noOfCodes) coupon_list[i]="--";
			}
					++i;
			}
																																																												
		}
		string* redeem(int n,int red) {
			int i=0,k=0;
			cout<<"enter the number of coupons you want to redeem\n";
			cin>>count;
			cin.ignore();
			string* redeemed_food=new string[count];
			while (i<n) {
				if (coupon_list[i]!="--") {
					cout<<"enter the meal"<<endl;
					getline (cin,redeemed_food[k]);
					++k;
					redeemed_coupons[red]=coupon_list[i];
					Restaurant::coupons_redeemed_count++;
					red++;
					count--;
					if (count==0) break;
				}
				++i;
			}
			redeemed_food[k]="0";
			if (count>0) cout<<count<<" coupons that you entered were invalid\n";
			cout<<"the total coupons redeemed today were "<<Restaurant::coupons_redeemed_count<<endl;
			return redeemed_food;
		}
		
};

int main () {
	string* food=new string[3]{"sushi","pad thai","mango tango"};
	string * free_food=new string[3]{"Binary Burger"," Quantum Quinoa","Data Donuts"};
	float prices[3]={4000,1200,3500};
	Restaurant FH("Food haven","city center",food,prices);
	Restaurant PB("Pixel bites","cyber street",free_food,prices);
	delete[] food;
	delete[] free_food;
	Restaurant test;
 	int i=0,date;
 	PB.setlist();
 	FH.setlist();
	cout<<"enter today's date\n";
	cin>>date;
	cin.ignore();
	user customers[5];
	//Assuming that our this online platform is able  to entertain just 5 customers a day
	i=0;
	string str,num;
	int a,n,red,choice,j;
	bool flag;
	while (i<5) {
		cout<<"welcome to  food panda\n";
		cout<<"please proceed with entering your data"<<endl;
		cout<<"please enter you name\n";
		getline(cin,str);
		cout<<"please your mobile  number\n";
		getline(cin,num);
		cout<<"please enter your age\n";
		cin>>a;
		cout<<"please enter the number of BOGO coupon codes you have collected so far\n";
		cin>>n;
		cout<<"please enter number of previously redeemed coupons\n";
		cin>>red;
		cin.ignore();
		customers[i]=user(str,num,a,n,(red+n));
		customers[i].accumulate_coupon(n,red);
	    	cout<<"choose your food place\n";
	    	cout<<"1 for food haven\n2 for pixel bites\n";
	    	cin>>choice;
	    	if (choice==1) test=FH;
	    	else test=PB;
	    	test.display_menu();
			cout<<"enter the number of items you would like you to buy\n";
			cin>>choice;
			food=new string[choice];
			cin.ignore();
	    	food=test.place_order(choice);
	    	customers[i].Has_valid(test,n,red,date);
	    	cout<<"do you want redeem any coupon\n";
	    	cin>>flag;
	    	cin.ignore();
	    	if (flag == true) {
	    	free_food=new string[n+1];
			free_food=customers[i].redeem(n,red+1);
	    }
	    	choice=test.generate_bill(food,choice);
	    	j=0;
	    	if (flag==true) {
	    		cout<<"items you acquired through the coupons\nWOHOO!!\n";
	    	while (1) {
	    		if (free_food[j]=="0") break;
	    		cout<<free_food[j]<<endl;
	    		++j;
			}
		}
		cout<<"---------"<<endl;
		cout<<"Your total is "<<choice<<endl;
		++i;
	}
	return 0;
}
