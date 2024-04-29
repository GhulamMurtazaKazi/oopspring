#include <iostream>
using namespace std;
double pi = 3.14;

class Shap
{
public:
    // Area of the shapes
    float Area(double radious)
    {
        return pi * radious * radious;
    }
    int Area(int length, int width)
    {
        return length * width;
    }
    float Area(float base, float height)
    {
        return 0.5 * base * height;
    }
    // Perimeters of the shapes
    float perimeter(double radious)
    {
        return 2 * pi * radious;
    }
    int perimeter(int length, int width)
    {
        return 2 * (length + width);
    }
    float perimeter(float base, float height)
    {
        return 2 * (base + height);
    }
};

int main(int argc, char const *argv[])
{

    while (1)
    {
        Shap shap;
        int choice;
        cout << endl
             << endl
             << "Menu" << endl
             << "1. Circle" << endl
             << "2. Rectangle" << endl
             << "3. Triangle" << endl
             << "4. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            double radious;
            cout << "Enter the radious of the circle: ";
            cin >> radious;
            cout << "Area of the circle is: " << shap.Area(radious) << endl;
            cout << "Perimeter of the circle is: " << shap.perimeter(radious) << endl;
            break;
        case 2:
            int length, width;
            cout << "Enter the length of the rectangle: ";
            cin >> length;
            cout << "Enter the Width of the rectangle: ";
            cin >> width;

            cout << "Area of the Rectangle: " << shap.Area(length, width) << endl;
            cout << "Perimetere of the Rectangle: " << shap.perimeter(length, width) << endl;
            break;
        case 3:
            float base, height;
            cout << "Enter the base of the triangle: ";
            cin >> base;
            cout << "Enter the height of the triangle: ";
            cin >> height;
            cout << "Area of the Triangle: " << shap.Area(base, height) << endl;
            cout << "Perimetere of the Triangle: " << shap.perimeter(base, height) << endl;
            break;
        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}
