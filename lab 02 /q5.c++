Your assignment is to construct a basic product management system for an online store.
1. Develop a function that enables the addition of a new product to the system. The
function should accept parameters such as product name, price, quantity, and
any other relevant details.
2. Implement a function that takes a product ID as input and displays detailed
information about the product, including its name, price, quantity in stock,
and any other relevant details.
3. Design a function that allows the update of product information. It should accept
a product ID and the new details (e.g., updated price, quantity, etc.) and modify
the existing product’s information accordingly.


#include<iostream>
using namespace std;
struct product{
	string id;
	string name;
	float price;
	int quantity;
};
void add(product* p,int n) {
	cout<<"enter all the details for the product that you want to add\n";
		cout<<"enter product id\n";
		getline(cin,p[n-1].id);
		cout<<"enter product name\n";
		getline(cin,p[n-1].name);
		cout<<"enter price\n";
		cin>>p[n-1].price;
			cout<<"enter quantity\n";
		cin>>p[n-1].quantity;
		return ;
}
void display(product* p,int n) {
	string id;
	cout<<"enter the id for the product to want to see\n";
	getline(cin,id);
	int i=0;
	while (i<n-1) {
		if (id==p[i].id) {
			cout<<"product id:"<<p[i].id<<endl;
			cout<<"product name:"<<p[i].name<<endl;
			cout<<"product price:"<<p[i].price<<endl;
			cout<<"product quantity:"<<p[i].quantity<<endl;
			return ;
		}
		++i;
	}
}
void update(product* p,int n) {
	string id;
	cout<<"enter the id for the product you want to update\n";
	getline(cin,id);
		int i=0;
	while (i<n-1) {
		if (id==p[i].id) {
				cout<<"enter new product id\n";
		getline(cin,p[i].id);
		cout<<"enter new product name\n";
		getline(cin,p[i].name);
		cout<<"enter new price\n";
		cin>>p[i].price;
			cout<<"enter new quantity\n";
		cin>>p[i].quantity;
			return ;
		}
		++i;
	}
}
int main () {
	int n,i=0;
	cout<<"enter the number of products\n";
	cin>>n;
	cin.ignore();
	product*p=new product[++n]; 
	// reason  for taking size n+1 is so we can later add 1 more product to the array when we will implement the add() function (1 part of question )
	while (i<n-1) {
		cout<<"enter product id\n";
		getline(cin,p[i].id);
		cout<<"enter product name\n";
		getline(cin,p[i].name);
		cout<<"enter price\n";
		cin>>p[i].price;
			cout<<"enter quantity\n";
		cin>>p[i].quantity;
		cin.ignore();
		++i;
	}
	cout<<"enter 1 to add a new product\nenter 2 to display details of a product\nenter 3 to update a product information\n";
	cin>>i;
	cin.ignore();
	if (i==1) add(p,n);
	else if (i==2) display(p,n);
	else update(p,n);
	return 0;
}
