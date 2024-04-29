#include<iostream>
using namespace std;
class Base{
int n;

public:
Base(int n): n(n) {}
Base operator--(){
    n = n*4;
    return *this;
}
Base operator--(int){
    n = n/4;
    return *this;
}
void display(){
    cout<<n<<endl;
}
};
int main(){
    Base b1(9);
    --b1;
    cout<<"Value using prefix operator: ";
    b1.display();
    b1--;
    cout<<"Value using postfix operator: ";
    b1.display();


    
}
