Construct a class for a stationary shop.
This class maintains lists for all items it sells (hint: an array of strings) and their corresponding
prices (hint: an array of prices).
Design a menu-driven program to:
• Enable the shop owner to add items and their prices.
• Retrieve the list of items.
• Modify the prices of items.
• Display all items along with their prices.
Generate a receipt that the shopkeeper can share with customers. This receipt can only be
generated after the shopkeeper inputs the items and their quantities bought by the customer.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Shop {
    int total_price = 0;
    string* items_1 = 0;
    float* prices_1 = 0;
    string* items_2 = new string[1];
    float* prices_2 = new float[1];
    int* quantity_1 = 0;
    int* quantity_2 = new int[1];
    int flag = 1;
    int size = 0;

public:
    ~Shop() {
        delete[] items_1;
        delete[] prices_1;
        delete[] quantity_1;
        delete[] items_2;
        delete[] prices_2;
        delete[] quantity_2;
    }

    void addItem(int i, string& str, float p) {
        if (flag == 1) {
            for (int j = 0; j < i; ++j) {
                if (str == items_2[j]) {
                    quantity_2[j]++;
                    prices_2[j] += p;
                    total_price += p;
                    return;
                }
            }
            items_1 = new string[i + 1];
            copy(items_2, items_2 + i, items_1);
            delete[] items_2;
            prices_1 = new float[i + 1];
            copy(prices_2, prices_2 + i, prices_1);
            delete[] prices_2;
            quantity_1 = new int[i + 1];
            copy(quantity_2, quantity_2 + i, quantity_1);
            delete[] quantity_2;
            items_1[i] = str;
            prices_1[i] = p;
            quantity_1[i] = 1;
            total_price += p;
            flag = 0;
        } else {
            for (int j = 0; j < i; ++j) {
                if (str == items_1[j]) {
                    quantity_1[j]++;
                    prices_1[j] += p;
                    total_price += p;
                    return;
                }
            }
            items_2 = new string[i + 1];
            copy(items_1, items_1 + i, items_2);
            delete[] items_1;
            prices_2 = new float[i + 1];
            copy(prices_1, prices_1 + i, prices_2);
            delete[] prices_1;
            quantity_2 = new int[i + 1];
            copy(quantity_1, quantity_1 + i, quantity_2);
            delete[] quantity_1;
            items_2[i] = str;
            prices_2[i] = p;
            quantity_2[i] = 1;
            total_price += p;
            flag = 1;
        }
        size++;
    }

    void modify(int i, string& str, float p) {
        if (flag == 1) {
            items_2[i] = str;
            total_price-=prices_2[i];
            prices_2[i] = p;
             total_price+=p;
            quantity_2[i]=1;
        } else {
            items_1[i] = str;
            total_price-=prices_1[i];
            prices_1[i] = p;
             total_price+=p;
             quantity_1[i]=1;
        }
    }

    void display() {
        if (flag == 1) {
            for (int i = 0; i < size; ++i) {
                cout << "Item no " << i + 1 << ": " << items_2[i] << " with a price of " << prices_2[i] << endl;
            }
        } else {
            for (int i = 0; i < size; ++i) {
                cout << "Item no " << i + 1 << ": " << items_1[i] << " with a price of " << prices_1[i] << endl;
            }
        }
    }

    void receipt() {
        cout << "\tYOUR RECEIPT\n";
        if (flag == 1) {
            for (int i = 0; i < size; ++i) {
                cout << "Item no " << i + 1 << ": " << items_2[i] << " with a price of " << prices_2[i] << "\nQuantity=" << quantity_2[i] << endl;
            }
        } else {
            for (int i = 0; i < size; ++i) {
                cout << "Item no " << i + 1 << ": " << items_1[i] << " with a price of " << prices_1[i] << "\nQuantity=" << quantity_1[i] << endl;
            }
        }
        cout << "Your total price=" << total_price << endl;
    }
};

int main() {
    Shop stationary;
    int i = 0, j;
    string str;
    float p;
    cout << "Welcome to our personal virtual shop repository\n";
    while (true) {
        cout << "Enter 1 to add items\n";
        cout << "Enter 2 to modify item\n";
        cout << "Enter 3 to display the items\n";
        cout << "Enter 4 to generate receipt\n";
        cout << "Enter 5 to exit\n";
        cin >> j;
        cin.ignore();
        if (j == 1) {
            cout << "Enter the new item you want to add:\n";
            getline(cin, str);
            cout << "Enter the price\n";
            cin >> p;
            stationary.addItem(i, str, p);
            ++i;
        } else if (j == 2) {
            cout << "Enter the number of item you want to change\n";
            cin >> j;
            cin.ignore();
            cout << "Enter the new item and its price respectively\n";
            getline(cin, str);
            cin >> p;
            stationary.modify(j - 1, str, p);
        } else if (j == 3) {
            stationary.display();
        } else if (j == 4) {
            stationary.receipt();
        } else if (j == 5) {
            break;
        }
    }
    return 0;
}
