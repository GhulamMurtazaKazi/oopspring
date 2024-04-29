#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void displayProperties() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    double calculateArea() const override { return 3.14159 * radius * radius; }
    double calculatePerimeter() const override { return 2 * 3.14159 * radius; }
    void displayProperties() const override {
        std::cout << "Circle Properties:\n";
        std::cout << "- Area: " << calculateArea() << '\n';
        std::cout << "- Perimeter: " << calculatePerimeter() << '\n';
        std::cout << "- Diameter: " << 2 * radius << '\n';
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double calculateArea() const override { return length * width; }
    double calculatePerimeter() const override { return 2 * (length + width); }
    void displayProperties() const override {
        std::cout << "Rectangle Properties:\n";
        std::cout << "- Area: " << calculateArea() << '\n';
        std::cout << "- Perimeter: " << calculatePerimeter() << '\n';
        std::cout << "- Diagonal: " << std::sqrt(length * length + width * width) << '\n';
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double calculateArea() const override {
        double s = (side1 + side2 + side3) / 2;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    double calculatePerimeter() const override { return side1 + side2 + side3; }
    void displayProperties() const override {
        std::cout << "Triangle Properties:\n";
        std::cout << "- Area: " << calculateArea() << '\n';
        std::cout << "- Perimeter: " << calculatePerimeter() << '\n';
    }
};

class EquilateralTriangle : public Triangle {
private:
    double side;
public:
    EquilateralTriangle(double side) : Triangle(side, side, side), side(side) {}

    double calculateArea() const override {
        const double constant = 0.43301270189f;
        return constant * side * side;
    }
    double calculatePerimeter() const override { return 3 * side; }
    void displayProperties() const override {
        std::cout << "Equilateral Triangle Properties:\n";
        std::cout << "- Area: " << calculateArea() << '\n';
        std::cout << "- Perimeter: " << calculatePerimeter() << '\n';
    }
};

void displayMenu() {
    std::cout << "Select a shape:\n";
    std::cout << "1. Circle\n";
    std::cout << "2. Rectangle\n";
    std::cout << "3. Equilateral Triangle\n";
    std::cout << "4. Triangle\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Shape* shape = nullptr;
    bool continueCalculations = true;

    while (continueCalculations) {
        displayMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double radius;
                std::cout << "Enter the radius of the circle: ";
                std::cin >> radius;
                shape = new Circle(radius);
                break;
            }
            case 2: {
                double length, width;
                std::cout << "Enter the length of the rectangle: ";
                std::cin >> length;
                std::cout << "Enter the width of the rectangle: ";
                std::cin >> width;
                shape = new Rectangle(length, width);
                break;
            }
            case 3: {
                double side;
                std::cout << "Enter the side length of the equilateral triangle: ";
                std::cin >> side;
                shape = new EquilateralTriangle(side);
                break;
            }
            case 4: {
                double side1, side2, side3;
                std::cout << "Enter the lengths of the three sides of the triangle: ";
                std::cin >> side1 >> side2 >> side3;
                shape = new Triangle(side1, side2, side3);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
                continue;
        }

        shape->displayProperties();

        std::string choice;
        std::cout << "Do you want to calculate properties for another shape? (yes/no): ";
        std::cin >> choice;
        continueCalculations = (choice == "yes");

        delete shape;
    }

    return 0;
}
