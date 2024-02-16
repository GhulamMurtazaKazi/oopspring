#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
class shop{
    int total_price=0;
    string* items_1;
    float* prices_1;
    string* items_2=new string[1];
    float* prices_2=new float[1];
    public:
    int flag=1;
    void additems(int i) {
        if (flag==1) {
            items_1=new string[i+1];
            copy(items_2,items_2+i,items_1);
            delete[] items_2;
            prices_1=new float[i+1];
            copy(prices_2,prices_2+i,prices_1);
            delete[] prices_2;
            cout<<"enter the new item you want to add:\n";
            getline(cin,items_1[i]);
            cout<<"enter the price\n";
            cin>>prices_1[i];
            total_price+=prices_1[i];
            flag=0;
        }
        else  {
            items_2=new string[i+1];
            copy(items_1,items_1+i,items_2);
            delete[] items_1;
            prices_2=new float[i+1];
            copy(prices_1,prices_1+i,prices_2);
            delete[] prices_1;
            cout<<"enter the new item you want to add:\n";
            getline(cin,items_2[i]);
            cout<<"enter the price\n";
            cin>>prices_2[i];
            total_price+=prices_2[i];
            flag=1;
        }
    }
    void modify(int i, string str, float p) {
        if (flag==1) {
            items_2[i]=str;
            prices_2[i]=p;
        }
        else {
            items_1[i]=str;
            prices_1[i]=p;
        }
    }
    void display(int i) {
        int j=0;
        if (flag==1) {
            while (j<=i) {
                cout<<"item no "<<j+1<< items_2[j]<<"with a price of  "<<prices_2[j]<<endl;
                ++j;
            }
        }
        else {
            while (j<=i) {
                cout<<"item no "<<j+1<< items_1[j]<<"with a price of  "<<prices_1[j]<<endl;
                ++j;
            }
        }
    }
    void reciept(int i) {
        int j=0;
        cout<<"\t\t\t\tYOUR RECIEPT\n";
        if (flag==1) {
            while (j<=i) {
                cout<<"item no "<<j+1<< items_2[j]<<"with a price of  "<<prices_2[j]<<endl;
                ++j;
            }
        }
        else {
            while (j<=i) {
                cout<<"item no "<<j+1<< items_1[j]<<"with a price of  "<<prices_1[j]<<endl;
                ++j;
            }
        }
        cout<<"Your total price="<<total_price<<endl;
    }
};
int main() {
    shop stationary;
    int i=0,j;
    cout<<"welcome to our personal virtual shop repo\n";
    while (1) {
        cout<<"enter 1 to add items\n";
        cout<<"enter 2 to modify item\n";
        cout<<"enter 3 to display the items\n";
        cout<<"enter 4 to generate reciept\n";
        cout<<"enter 5 to exit\n";
        cin>>j;
        cin.ignore();
        if (j==1) stationary.additems(i);
        else if (j==2) stationary.modify(i, "item", 0.0); // You need to pass the item and price here
        else if (j==3) stationary.display(i);
        else if (j==4) stationary.reciept(i);
        else return 0;
        ++i;
    }

    return 0;
}
