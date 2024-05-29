You are tasked with developing a software module for a geometry library that calculates the
areas and perimeters of various shapes. Your module needs to efficiently handle circles,
rectangles, and triangles. You've decided to implement this module in C++, utilizing function
overloading and a global constant for the value of pi.
Your Shape class should have the following functionalities:
Overloaded methods to calculate the area of a circle given its radius, the area of a rectangle
given its length and width, and the area of a triangle given its base and height.
Overloaded methods to calculate the perimeter of a circle given its radius, the perimeter of
a rectangle given its length and width, and the perimeter of a triangle given its three sides.
Additionally, ensure that your code is well-commented and demonstrates good coding
practices such as encapsulation, abstraction, and meaningful variable naming. Provide a main
function to demonstrate the usage of your Shape class by calculating and displaying the areas
and perimeters of various shapes, utilizing the global constant for the value of pi.

#include<iostream>
#include<cmath>
using namespace std;
double pi=3.16;
class shape {
    public:
    double area(double radius) {
        return pi*radius*radius;
    }
    double area(double length,double width) {
        return length*width;
    }
    double area(double a,double b,double c) {
        double s=double(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double perimeter(double radius) {
        return 2*pi*radius;
    }
    double perimeter(double length,double width) {
        return 2*(length+width);
    }
    double perimeter(double a,double b,double c) {
        return a+b+c;
    }
};
int main() {
     cout<<"Welcome to the geometric library\n";
     shape s;
    while (1) {
        cout<<"select a shape\n1. circle\n2. rectangle\n3. triangle\n4. exit\n";
        double n;
        cin>>n;
        if (n==1) {
            cout<<"enter the radius for the circle\n";
            cin>>n;
            cout<<"the area and perimeter of circle are "<<s.area(n)<<" and "<<s.perimeter(n)<<" respectively\n";
        }
        else if (n==2) {
            double m;
            cout<<"enter the length and width for the rectangle\n";
            cin>>m>>n;
            cout<<"the area and perimeter of rectangle are "<<s.area(m,n)<<" and "<<s.perimeter(m,n)<<" respectively\n";
        }
        else if (n==3) {
            double m,o;
            cout<<"enter the 3 sides of the triangle\n";
            cin>>m>>n>>o;
            cout<<"the area and perimeter of triangle are "<<s.area(m,n,o)<<" and "<<s.perimeter(m,n,o)<<" respectively\n";
        }
        else if (n==4) {
            cout<<"Thank you  for using the geometric library\n";
            break;
        }
    }
    return 0;
}
