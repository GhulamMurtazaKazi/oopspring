Imagine you're developing a program for a scientific research lab. Your task is to create a C++
program that facilitates unit conversions commonly used in the lab. The program should be
able to convert between different units such as liters to gallons and Fahrenheit to Celsius.
Additionally, the program should be flexible enough to accommodate future unit conversions
that might be needed in the lab.
Design a C++ program that fulfills these requirements. Your program should include:
A base class named convert with protected data members val1 and val2, representing the
initial value and the converted value respectively. This class should have a virtual function
named compute().
Two derived classes: l_to_g for converting liters to gallons and f_to_c for converting
Fahrenheit to Celsius. These classes should implement the compute() function to perform the
respective conversions.
In the main() function, demonstrate the use of these classes by creating objects to convert:
4 liters to gallons.
70 Fahrenheit to Celsius.
Ensure that your program utilizes polymorphism to handle the different conversions through
a pointer to the base class.

#include<iostream>
using namespace std;
class base{
	protected:
		double val1,val2;
		public:
			virtual void compute(double val1){
				cout<<"the converted value will be printed here\n";
			}
};
class l_to_g:public base{
	public:
		void compute(double val1){
			this->val1=val1;
			val2=0.264172 * val1;
			cout<<"The liquid in gallons is "<<val2<<endl;
		}
};
class f_to_c:public base{
	public:
		void compute(double val1) {
			this->val1=val1;
			val2=(val1-32)*(double)(5.0/9.0);
			cout<<"the temperature in celsius is "<<val2<<endl;
		}
};
int main () {
	l_to_g a;
	f_to_c b;
	base * ptr;
	ptr=&a;
	ptr->compute(4);
	ptr=&b;
	ptr->compute(100);
	return 0;
}
