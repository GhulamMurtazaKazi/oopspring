Suppose you are tasked with developing a geometry application that helps users calculate
properties of various shapes. You are required to implement classes for different shapes such
as Circle, Rectangle, Square, Triangle, and EquilateralTriangle. Each shape class
should inherit from a base class called Shape. Additionally, the EquilateralTriangle class
should inherit from the Triangle class. Your implementation should utilize method overriding
and pointers to ensure polymorphic behavior.
Implement the base class Shape with the following virtual functions:
virtual double area() const: This function should calculate and return the area of the
shape. Override this function in each derived class to provide the specific implementation for
that shape.
virtual double perimeter() const: This function should calculate and return the perimeter
of the shape. Override this function in each derived class to provide the specific implementation
for that shape.
virtual void displayProperties() const: This function should display the properties of
the shape. Override this function in each derived class to provide the specific display for that
shape.
Implement the derived classes Circle, Rectangle, Square, and Triangle, each inheriting
from the base class Shape. For each derived class:
Override the virtual functions area(), perimeter(), and displayProperties() to provide
the specific implementations for that shape.

Ensure to use pointers to the base class Shape when implementing the functions.
Implement the EquilateralTriangle class, inheriting from the Triangle class. For this
class:
Override the virtual functions area(), perimeter(), and displayProperties() to provide
the specific implementations for an equilateral triangle.
Ensure to use pointers to the base class Triangle when implementing the functions.
In the main function:
Allow users to select a shape and provide input for the required parameters (e.g., radius for
Circle, length and width for Rectangle, etc.).
Dynamically allocate memory for the selected shape using pointers to the appropriate base
class (Shape or Triangle).
Call the appropriate functions using the base class pointers to display the properties of the
selected shape.
Ensure proper memory management by deallocating memory when it is no longer needed.
Approach:
1. Start by defining the Shape base class with the required virtual functions.
2. Implement derived classes (Circle, Rectangle, Square, Triangle) inheriting from the
Shape class and override their respective virtual functions.
3. Implement the EquilateralTriangle class, inheriting from the Triangle class, and
override its virtual functions.
4. Use pointers to the appropriate base class (Shape or Triangle) to achieve polymorphic
behavior.
5. In the main function, prompt the user to select a shape and provide necessary input.
6. Dynamically allocate memory for the selected shape using pointers.
7. Call functions using the appropriate base class pointers to display shape properties.
8. Ensure proper memory deallocation to prevent memory leaks.

#include<iostream>
#include<cmath>
using namespace std;
class shape{
    public:
    virtual double  area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
};
class square:public shape{
    double length;
    public:
    square(double length):length(length) {}
    double diagonal() const {
        return sqrt((length*length)*2);
    }
    double area() const override {
        return length*length;
    }
    double perimeter() const override {
        return 4*length;
    }
    void display() const override {
        cout<<"The area of square is "<<area()<<"\nthe perimeter of square is "<<perimeter()<<"\ndiagonal of square is "<<diagonal()<<endl;
    }
};
class circle:public shape{
double radius;
public:
circle(double radius):radius(radius) {}
double area() const override{
    return 3.16*radius*radius;
}
double perimeter() const override{
    return 2*3.16*radius;
}
void display() const override {
    cout<<"The area of  circle is "<<area()<<"\nthe perimeter of circle is "<<perimeter()<<"\ndiameter of s circle is "<<radius*2<<endl;
}
};
class rectangle:public shape{
    double length,width;
    public:
    rectangle(double length,double width):length(length),width(width) {}
    double area() const override {
        return length*width;
    }
    double perimeter() const override{
        return 2*(length+width);
    }
    double diagonal() const {
        return sqrt(length*length + width*width);
    }
    void display() const override {
         cout<<"The area of rectangle is "<<area()<<"\nthe perimeter of rectangle is "<<perimeter()<<"\ndiagonal of rectangle is "<<diagonal()<<endl;
    }
};
class triangle:public shape{
    protected:
    double a,b,c,base,height;
    public:
    triangle(double a,double b,double c,double base,double height):a(a),b(b),c(c),base(base),height(height) {}
    triangle() {}
    double perimeter() const override {
        return a+b+c;
    }
    double area() const override{
       return 0.5*base*height;
    }
    void display() const override {
         cout<<"The area of triangle is "<<area()<<"\nthe perimeter of triangle is "<<perimeter()<<endl;
    }
};
class equilateraltriangle:public triangle{
public:
equilateraltriangle(double a) { this->a=a; }
double area( ) const override {
    return (sqrt(3)*(a*a))/4;
}
double perimeter() const override {
    return 3*a;
}
void display() const override{
    cout<<"The area of equilateral triangle is "<<area()<<"\nthe perimeter of equilateral triangle is "<<perimeter()<<endl;
}
};
int main() {
    cout<<"Welcome to the geometric library\n";
    while (1) {
        cout<<"select a shape\n1. square\n2. circle\n3. rectangle\n4. triangle\n5. equilateral triangle\n6. exit\n";
        double n;
        cin>>n;
        shape * ptr;
        if (n==1) {
            cout<<"enter the length of square\n";
            cin>>n;
            ptr=new square(n);
            ptr->display();
        }
        else if (n==2) {
            cout<<"enter the radius of circle\n";
            cin>>n;
            ptr=new circle(n);
            ptr->display();
        }
        else if (n==3) {
            double m;
            cout<<"enter  the length and width for the rectangle respectively\n";
            cin>>m>>n;
            ptr=new rectangle(m,n);
            ptr->display();
        }
        else if (n==4) {
            double a,b,c,d;
            cout<<"enter the length of the 3 sides,base and height for the triangle respectively\n";
            cin>>a>>b>>c>>d>>n;
            ptr=new  triangle(a,b,c,d,n);
            ptr->display();
        }
        else if (n==5) {
            cout<<"enter the length\n";
            cin>>n;
            ptr=new equilateraltriangle(n);
            ptr->display();
        }
        else if (n==6) {
            cout<<"Thank you for using geometric library\n";
            delete ptr;
            break;
            }
       delete ptr;
    }
    return 0;
}
