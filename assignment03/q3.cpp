You are tasked with implementing a generic matrix class in C++ that supports basic
matrix operations using operator overloading. The matrix class should be designed
using generic programming techniques to handle matrices of different numeric
types (int, double, etc.) and support operations such as addition, subtraction, and
multiplication.
A. Generic Matrix Class Template:
Implement a template Matrix class that can represent a 2D matrix of any numeric
type (T). The class should support the following functionalities:
Constructor to initialize the matrix dimensions (rows and cols).

Method to access and modify individual elements of the matrix (get and set).
Overloaded operators (+, -, *) to perform matrix addition, subtraction, and
multiplication.
Abstract Method to displaying the matrix.
Specialized Matrix Classes:
Implement specialized matrix classes (IntMatrix, DoubleMatrix) that inherit from
the Matrix<T> base class. Override the display() method to display matrices of
specific numeric types (int, double).
write a main() function to demonstrate the functionality of the matrix classes.
Create instances of IntMatrix and DoubleMatrix, perform matrix operations
(addition, subtraction, multiplication), and display the results using the display()
method.

#include<iostream>
#include<vector>
using namespace std;
class IntMatrix;
class doubleMatrix;
template<class T>
class matrix{
    protected:
    vector<vector<T>> array;
    public:
    friend class IntMatrix;
    friend class doubleMatrix;
    matrix(int m,int n) {
        array.resize(m);
        for (int i=0;i<m;++i) array[i].resize(n);
    }
    T getelement(int i,int j) { return array[i][j]; }
    void setelement(int i,int j,T value) { array[i][j]=value; }
    matrix<T> operator+(const matrix& obj) {
        if (array.size()==obj.array.size()&&array[0].size()==obj.array[0].size()) {
            matrix<T> temp(array.size(),array[0].size());
            for (int i=0;i<array.size();++i) {
                for (int j=0;j<array[0].size();++j) {
                    temp.array[i][j]=array[i][j]+obj.array[i][j];
                }
            }
            return temp;
        }
        cout<<"matrices not compatible for addition\n";
        exit(1); // Add this line
    }
    matrix<T> operator-(const matrix& obj) {
        if (array.size()==obj.array.size()&&array[0].size()==obj.array[0].size()) {
            matrix<T> temp(array.size(),array[0].size());
            for (int i=0;i<array.size();++i) {
                for (int j=0;j<array[0].size();++j) {
                    temp.array[i][j]=array[i][j]-obj.array[i][j];
                }
            }
            return temp;
        }
        cout<<"matrices not compatible for subtraction\n";
        exit(1); // Add this line
    }
    matrix<T> operator*(const matrix& obj) {
        if (array[0].size()==obj.array.size()) {
           matrix<T> temp(array.size(),obj.array[0].size());
           for (int i=0;i<array.size();++i) {
            for (int j=0;j<obj.array[0].size();++j) {
                T product=0;
                for (int k=0;k<array[0].size();++k) // Change i to k
                product+=array[i][k]*obj.array[k][j];
                temp.array[i][j]=product;
            }
           }
           return temp; // Add this line
        }
        cout<<"matrices not compatible for multiplication\n";
        exit(1); // Add this line
    }
    virtual void display() const { };
};

class IntMatrix:public matrix<int>{
public:
IntMatrix(int m,int n):matrix<int>(m,n) { } // Add <int>
    void display() const override {
        for (int i=0;i<array.size();++i) {
            for (int j=0;j<array[0].size();++j) 
            cout<<array[i][j]<<" ";
            cout<<endl;
        }
    }
    void operator=(const matrix<int>& obj) { // Add const
        for (int i=0;i<array.size();++i) {
            for (int j=0;j<array[0].size();++j) array[i][j]=obj.array[i][j];
        }
    }
};

class doubleMatrix:public matrix<double>{
public:
doubleMatrix(int m,int n):matrix<double>(m,n) { } // Add <double>
void operator=(const matrix<double>& obj) { // Add const
        for (int i=0;i<array.size();++i) {
            for (int j=0;j<array[0].size();++j) array[i][j]=obj.array[i][j];
        }
    }
    void display() const override {
        for (int i=0;i<array.size();++i) {
            for (int j=0;j<array[0].size();++j) 
            cout<<array[i][j]<<" ";
            cout<<endl;
        }
    }
};

int main() {
    IntMatrix A(2,2),B(2,2);
    doubleMatrix C(2,2),D(2,2);
    for (int i=0;i<2;++i) {
        for (int j=0;j<2;++j) {
            A.setelement(i,j,i+j);
            B.setelement(i,j,i+j);
            C.setelement(i,j,i+j);
            D.setelement(i,j,i+j);
        }
    }
    IntMatrix res_1(2,2);
    doubleMatrix res_2(2,2);
    res_1=A+B;
    cout<<"A+B=\n";
    res_1.display();
    cout<<endl<<endl<<"A-B=\n";
    res_1=A-B;
    res_1.display();
    cout<<endl<<endl<<"A*B=\n";
    res_1=A*B;
    res_1.display();
    cout<<endl<<endl<<"C+D=\n";
    res_2=C+D;
    res_2.display();
    res_2=C-D;
    cout<<endl<<endl<<"C-D=\n";
    res_2.display();
    res_2=C*D;
    cout<<endl<<endl<<"C*D=\n";
    res_2.display();
    return 0;
}
