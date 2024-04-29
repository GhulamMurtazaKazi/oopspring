#include <iostream>
#include <string>

using namespace std;

class Logo {
private:
    string logo;

public:
    Logo() {
        logo = "Blue Bird";
    }

    friend class Platform;
};

class Platform {
private:
    string name;
    Logo logo;

public:
    Platform(string n) : name(n) {}

    void changeLogo(string newLogo) {
        logo.logo = newLogo;
    }

    void display() {
        cout << "Platform: " << name << endl;
        cout << "Logo: " << logo.logo << endl;
    }
};

class Server {
private:
    string ipAddress;

public:
    Server(string ip) : ipAddress(ip) {}

    void display() {
        cout << "Server IP Address: " << ipAddress << endl;
    }
};

int main() {
    cout<<"kazi"<<endl<<"23k-0020"<<endl;
    Platform twitter("Twitter");
    Server server("192.168.1.1");

    cout << "Before changing the logo:" << endl;
    twitter.display();
    server.display();

    // Change the logo to Doge Coin
    twitter.changeLogo("Doge Coin");

    cout << "\nAfter changing the logo:" << endl;
    twitter.display();
    server.display();

    return 0;
}
