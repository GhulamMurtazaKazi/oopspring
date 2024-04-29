#include<iostream>
using namespace std;

class Vehicle{
	protected:
		string make;
		string model;
		int year;
		
	public:
		Vehicle(string make, string model, int year)
		{
			this->make=make;
			this->model=model;
			this->year = year;
		}
};

class Car:protected Vehicle{
	protected:
		int doors;
		double fuelEfficiency;
		
	public:
		Car(int doors, double fuelEfficiency, string make, string model, int year):Vehicle(make, model,year)
		{
			this->doors=doors;
			this->fuelEfficiency=fuelEfficiency;
		}
};

class ElectricCar:protected Car{
	protected:
		int batteryLife;
		
	public:
		ElectricCar(int doors, double fuelEfficiency, string make, string model, int year,int batteryLife):batteryLife(batteryLife),Car(doors,fuelEfficiency,make,model,year)
		{
		}
		
		void display()
		{
			cout<<"-------------Displaying information for the Electric car--------------"<<endl;
			cout<<"Number of doors: "<<doors<<endl;
			cout<<"Fuel status: "<<fuelEfficiency<<endl;
			cout<<"Company: "<<make<<endl;
			cout<<"Model: "<<model<<endl;
			cout<<"Year of manufacturing: "<<year<<endl;
			cout<<"Battery life: "<<batteryLife<<endl;
		}
};

int main()
{
	ElectricCar car1(4, 56.88, "Toyota", "Corolla", 2018,90);
	car1.display();
}
