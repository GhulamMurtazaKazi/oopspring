Suppose you are creating a program to represent different types of vehicles. You want to create
a base class called Vehicle that has member variables for the make, model, and year, as well
as a constructor to initialize these variables. You then want to create a derived class called Car
that inherits from Vehicle and adds member variables for the number of doors and the fuel
efficiency. Finally, you want to create a derived class called ElectricCar that inherits from
Car and adds a member variable for the battery life.
Write the code to define the Vehicle, Car, and ElectricCar classes, including constructors
to initialize the member variables. In each derived class constructor, make sure to call the
appropriate base class constructor using an initialization list. Also, demonstrate how to create
and use an object of the ElectricCar class.

#include<iostream>
using namespace std;
class vehicle{
protected:
string model,make;
int year;
public:
vehicle(string model,string make,int year):model(model),make(make),year(year) {}
void display() const {
    cout<<"The vehicle is made of:"<<make<<"\nmodel:"<<model<<"\nyear:"<<year<<endl;
}
};
class car:public vehicle{
    protected:
    int doors,fuelefficiency;
    public:
    car(string model,string make,int year,int doors,int fuelefficiency):vehicle(model,make,year),doors(doors),fuelefficiency(fuelefficiency) {}
    void display() const {
        vehicle::display();
        cout<<"number of doors:"<<doors<<"\nfuel efficiency:"<<fuelefficiency<<" kmpl\n";
    }
};
class electricvehicle:public car{
    int batterylife;
    public:
    electricvehicle(string model,string make,int year,int doors,int fuelefficiency,int batterylife):car(model,make,year,doors,fuelefficiency),batterylife(batterylife) {}
    void display() const {
        car::display();
        cout<<"the battery life is "<<batterylife<<" km in a single charge"<<endl;
    }
};
int main() {
    electricvehicle tesla("cybertruck","vibranium",2024,2,100,150);
    tesla.display();
    return 0;
}
