You are tasked with creating a payroll management system for a small company. The system
needs to handle two types of employees: full-time employees and part-time employees. Each
type of employee has different attributes and methods associated with them. Full-time
employees receive a fixed salary per month, while part-time employees are paid based on the
number of hours they work.
Define a base class named Employee with the following attributes and methods:
Attributes:
employee ID, employee name.
Methods:
virtual double calculatePay() const: This method calculates and returns the pay for the
employee. Since this method's implementation depends on the type of employee, it should be
declared as virtual and have a default implementation (e.g., returning 0.0).
virtual void displayDetails() const: This method displays the details of the employee
(ID and name).
Implement two derived classes: FullTimeEmployee and PartTimeEmployee.
FullTimeEmployee should inherit from the Employee class and have an additional attribute
for the monthly salary.
PartTimeEmployee should also inherit from the Employee class and have attributes for the
hourly wage and the number of hours worked.
Override the calculatePay() method in both derived classes:
In FullTimeEmployee, calculate the pay by simply returning the monthly salary.
In PartTimeEmployee, calculate the pay by multiplying the hourly wage with the number of
hours worked.
Override the displayDetails() method in both derived classes to display the additional
attributes along with the base class attributes.

In the main function:
 Create instances of FullTimeEmployee and PartTimeEmployee.
 Call the displayDetails() method for each instance to display their details.
 Call the calculatePay() method for each instance to calculate and display their pay.

 Demonstrate early or static binding by calling the calculatePay() method using a base
class pointer.
Approach:
1. Define the Employee base class with the required attributes and virtual methods.
2. Implement derived classes (FullTimeEmployee and PartTimeEmployee) inheriting
from the Employee class and override their virtual methods.
3. Use dynamic polymorphism to handle different types of employees by using base class
pointers.
4. In the main function, create instances of both derived classes and call their methods to
demonstrate polymorphic behavior.
5. Use a base class pointer to call the calculatePay() method and observe early or static
binding in action.

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class employee{
    protected:
    string name,id;
    public:
    string getid() const { return id; }
    employee(string name,string id):name(name),id(id) {}
    virtual double calculatepay() const {
        return 0.0;
    }
    virtual void display() const {
        cout<<"Name "<<name<<"\nID"<<id<<endl;
    }
};
class parttimeemployee:public employee{
    double wage;
    int hours;
    public:
    parttimeemployee(string name,string id,double wage,int hours):employee(name,id),wage(wage),hours(hours) {}
    double calculatepay() const override {
        return wage*hours;
    }
    void display() const override {
        cout<<"Type Part time employee\nName "<<name<<"\nID "<<id<<"\nwage "<<wage<<"\nhours worked "<<hours<<endl;
    }
};
class fulltimeemployee:public employee{
double salary;
public:
fulltimeemployee(string name,string id,double salary):employee(name,id),salary(salary) {}
double calculatepay() const override {
    return salary;
}
void display() const override{
    cout<<"Type Full time employee\nName "<<name<<"\nID "<<id<<"\nFixed monthly pay of "<<salary<<" Rs"<<endl;
}
};
int main() {
    int n;
    cout<<"enter the number of employees\n";
    cin>>n;
    vector<employee*>database(n);
    for (int i=0;i<database.size();++i) {
        string name,id;
        cout<<"enter the type of employee\n1. part time\n2. full time\n";
        cin>>n;
        cin.ignore();
         cout<<"enter the details for the employee\n";
            cout<<"enter the name and id respectively\n";
            getline(cin,name);
            getline(cin,id);
        if (n==1) {
            double  wage;
            int hours;
            cout<<"enter the number of hourly wage and number of hours worked\n";
            cin>>wage>>hours;
            employee * ptr=new parttimeemployee(name,id,wage,hours);
            database[i]=ptr;
        }
        else if (n==2) {
            double pay;
            cout<<"enter the monthly pay\n";
            cin>>pay;
            employee * ptr=new fulltimeemployee(name,id,pay);
            database[i]=ptr;
        }
    }
    while (1) {
        cout<<"enter 1 to see employee details\nenter 2 to see employee's salary\nenter 3 to exit\n";
        cin>>n;
        cin.ignore();
        if (n==3) break;
        string str;
        cout<<"enter  the employee id\n";
        getline(cin,str);
        for (int i=0;i<database.size();++i) {
            if (database[i]->getid()==str) {
                if (n==1) database[i]->display();
                else if (n==2) cout<<"The salary of the employee is "<<database[i]->calculatepay()<<endl;
                break;
            }
        }
    }
    return 0;
}
