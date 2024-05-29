Question 02
Design a C++ program for managing a collection of pets using specialized templates
and generic programming concepts. The program should include a base Pet class
and specialized pet classes (Cat, Dog, Bird) to demonstrate inheritance,
polymorphism, and template specialization.
Pet Class Template: Implement a template Pet class that serves as the base for all
pet types.
Use a template parameter T to make the Pet class generic.
Include the following features in the Pet class:
Constructor to initialize the pet's name and age.
A pure virtual function makeSound() to represent the pet's unique sound.
B. Specialized Pet Classes: Define specialized pet classes (Cat, Dog, Bird) that inherit
from the Pet<T> class.
Each specialized pet class should implement the makeSound() function to produce
a specific sound (Meow, Woof, Chirp).
C. Write a main() function to demonstrate the functionality of the pet system.
Create instances of different pet types (Cat, Dog, Bird) and interact with them using
polymorphism.
Display each pet's information (name, age) and make them produce their unique
sound using the makeSound() method.

#include<iostream>
using namespace std;
template<class T1,class  T2>
class pet{
	protected:
	T1 name;
	T2 age;
	public:
		pet(T1 name,T2 age):name(name),age(age) { }
		virtual void makesound() const = 0;
		void display() const {
		cout<<"pet name:"<<name<<"\npet age:"<<age<<endl;
		}
};
class dog:public pet<string,int> {
	public:
		dog(string name,int age):pet(name,age) { }
		void makesound() const override{
		cout<<"woof woof..."<<endl;
		}
};
class cat:public pet<string,int> {
	public:
		cat(string name,int age):pet(name,age) { }
		void makesound() const override{
		cout<<"meow meow..."<<endl;
		}
};
class bird:public pet<string,int> {
	public:
		bird(string name,int age):pet(name,age) { }
		void makesound() const override{
		cout<<"chirp chirp..."<<endl;
		}
};
int main() {
	dog d("spike",9);
	cat c("tom",5);
	bird b("silverster",10);
	pet<string,int>* ptr;
	ptr=&d;
	ptr->display();
	ptr->makesound();
	ptr=&c;
		ptr->display();
	ptr->makesound();
	ptr=&b;
		ptr->display();
	ptr->makesound();
	return 0;
}
