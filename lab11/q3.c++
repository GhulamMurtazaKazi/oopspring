You are working on a project that involves managing different types of vehicles, such as cars,
trucks, and motorcycles. You need to create a base class called Vehicle that has common
attributes and methods, such as make, model, and speed. However, the specific features and
behaviors vary depending on the type of vehicle (e.g., fuel efficiency, cargo capacity). Create
an abstract class Vehicle with pure virtual functions for specific features and behaviors,
and then create concrete subclasses for each type of vehicle.
Write the C++ code for the Vehicle abstract class and two concrete subclasses, Car and
Truck.
 Abstract Class: Vehicle
o Data Members:
 make (string)
 model (string)
 speed (int)
o Member Functions:
 accelerate() (pure virtual)
 brake() (pure virtual)
 calculateFuelEfficiency() (pure virtual)
 getMake() (concrete)
 getModel() (concrete)
 getSpeed() (concrete)

 Concrete Subclass: Car
o Data Members:
 fuelCapacity (double)
o Member Functions:
 accelerate() (overrides Vehicle::accelerate)
 brake() (overrides Vehicle::brake)
 calculateFuelEfficiency() (overrides
Vehicle::calculateFuelEfficiency)

 Concrete Subclass: Truck
o Data Members:
 cargoCapacity (int)
o Member Functions:
 accelerate() (overrides Vehicle::accelerate)
 brake() (overrides Vehicle::brake)
 calculateFuelEfficiency() (overrides
Vehicle::calculateFuelEfficiency)

#include<iostream>
using  namespace std;
class vehicle{
	protected:
		string make,model;
		int speed;
		public:
			vehicle(string make,string model,int speed):make(make),model(model),speed(speed) { } 
			virtual void accelerate() = 0;
			virtual void brake() = 0;
			virtual void fuelefficiency(double,double) = 0;
			string getmake() { return make; }
			string getmodel() { return model; }
			int getspeed() { return speed; }
};
class car:public vehicle{
	double fuelcapacity;
	public:
		car(string make,string model,int speed,double fuelcapacity):vehicle(make,model,speed),fuelcapacity(fuelcapacity) { }
		void accelerate() override{
			cout<<"vroom vroom..... (shapater)\n";
		speed+=4;
		}
		void brake() override{
		speed=0;
		}
		void fuelefficiency(double distance,double consumed) override {
			cout<<"your efficiency is "<<distance/consumed<<" kmpl\n";
		}
		
};
class truck:public vehicle{
	int cargocapacity;
	public:
		truck(string make,string model,int speed,int cargocapacity):vehicle(make,model,speed),cargocapacity(cargocapacity) { }
		void accelerate() override{
		++speed;
		}	
		void brake() override{
		cout<<"slowing down......."<<endl;
		speed=0;
		}
		void fuelefficiency(double distance,double consumed) override {
			cout<<"your efficiency is "<<distance/consumed<<" kmpl\n";
		}
};
int main () {
	vehicle * ptr;
	car murtaza_car("vibranium","teslaX",700,500.50);
	truck fawad_truck("plastic","noob",12,5);
	ptr=&murtaza_car;
	ptr->accelerate();
	ptr->brake();
    ptr->fuelefficiency(500,200);
	ptr=&fawad_truck;
	ptr->accelerate();
	ptr->brake();
	ptr->fuelefficiency(500,400);
	return 0;
}
