#include <iostream>
#include <string>
using namespace std;

int NoOfPets;

class pet {
    string healthstatus;
    int hungerlevel;
    int happinesslevel;
    string *specialskills;
    int totalskills;

public:
    string species;
    int adoptcount;

    // Constructor
    pet() {
        specialskills = 0;
        totalskills = 0;
        adoptcount = 0;
    }

    // Destructor to deallocate memory
    ~pet() {
        delete[] specialskills;
    }

    void setter(int i) {
        int j = 0;
        cout << "Enter the details for pet " << i + 1 << endl;
        cout << "Enter the species: ";
        getline(cin, species);
        cout << "Enter the health status: ";
        getline(cin, healthstatus);
        cout << "Enter the hunger level: ";
        cin >> hungerlevel;
        cin.ignore(); // Ignore the newline character
        cout << "Enter the happiness level: ";
        cin >> happinesslevel;
        cin.ignore(); // Ignore the newline character
        cout << "Enter the total number of special skills for this pet: ";
        cin >> totalskills;
        cin.ignore(); // Ignore the newline character
        cout << "Enter the special skills one by one: " << endl;
        specialskills = new string[totalskills];
        while (j < totalskills) {
            getline(cin, specialskills[j]);
            ++j;
        }
    }

    void displayPetDetails() {
        cout << "Species: " << species << endl;
        cout << "Health status: " << healthstatus << endl;
        cout << "Hunger level: " << hungerlevel << endl;
        cout << "Happiness level: " << happinesslevel << endl;
        cout << "Special skills: ";
        for (int i = 0; i < totalskills; ++i) {
            cout << specialskills[i] << " ";
        }
        cout << endl;
    }

    void decrHappiness() {
        if (happinesslevel > 0)
            --happinesslevel;
    }

    void updateHealth() {
        if (healthstatus == "Bad") {
            healthstatus = "Good";
            updateHappiness();
        }
    }

    void updateHunger() {
        if (hungerlevel > 0) {
            --hungerlevel;
            updateHappiness();
        }
    }

private:
    void updateHappiness() {
        if (happinesslevel < 10)
            ++happinesslevel;
    }
};

pet *myanimals;

class adopter {
    string adopterName;
    string adopterMobileNum;
    pet *adoptedPetRecords;
    int NoOfPets;

public:
    adopter() {
        cout << "Hello, welcome to the Kazi Pet Adoption and Care Centre" << endl;
        cout << "Please proceed with filling your personal info" << endl;
        cout << "Enter your name: ";
        getline(cin, adopterName);
        cout << "Enter your mobile number: ";
        getline(cin, adopterMobileNum);
    }

    void setrecords(int n) {
        NoOfPets = n;
        adoptedPetRecords = new pet[NoOfPets];
    }

    void addpet() {
        string species;
        cout << "Enter the species of pet you want to adopt: ";
        getline(cin, species);
        cin.ignore(); // Ignore the newline character
        for (int i = 0; i < NoOfPets; ++i) {
            if (adoptedPetRecords[i].species == species) {
                adoptedPetRecords[i].adoptcount++;
                return;
            }
        }
        cout << "Pet not found!" << endl;
    }

    void returnPet() {
        string species;
        cout << "Enter the species of pet you want to return: ";
        getline(cin, species);
        cin.ignore(); // Ignore the newline character
        for (int i = 0; i < NoOfPets; ++i) {
            if (adoptedPetRecords[i].species == species) {
                adoptedPetRecords[i].adoptcount--;
                return;
            }
        }
        cout << "Pet not found!" << endl;
    }

    void displayAdoptedPets() {
        for (int i = 0; i < NoOfPets; ++i) {
            if (adoptedPetRecords[i].adoptcount != 0)
                adoptedPetRecords[i].displayPetDetails();
        }
    }
    string getname() {
    	return adopterName;
	}
};

int main() {
    int TotalAdop;
    cout << "Enter the total number of pets: ";
    cin >> NoOfPets;
    cin.ignore(); // Ignore the newline character
    myanimals = new pet[NoOfPets];
    for (int i = 0; i < NoOfPets; ++i) {
        myanimals[i].setter(i);
    }
    cout << "Enter the total number of adopters registered for today: ";
    cin >> TotalAdop;
    cin.ignore(); // Ignore the newline character
    adopter *clients = new adopter[TotalAdop];
    for (int i = 0; i < TotalAdop; ++i) {
        clients[i].setrecords(NoOfPets);
    }
    int i = 0;
    while (i < TotalAdop) {
    	cout<<"welcome mr."<<clients[i].getname()<<endl;
        while (1) {
            int j;
            cout << "Enter 1 to view the details of a specific animal" << endl;
            cout << "Enter 2 to update the health status" << endl;
            cout << "Enter 3 to update the hunger" << endl;
            cout << "Enter 4 to adopt an animal" << endl;
            cout << "Enter 5 to return an adopted animal" << endl;
            cout << "Enter 6 to display the adopted animal list" << endl;
            cout << "Enter 7 to exit" << endl;
            cin >> j;
            if (j == 7)
                break;
            switch (j) {
                case 1: {
                    string species;
                    cout << "Enter the species: ";
                    cin.ignore(); // Ignore the newline character
                    getline(cin, species);
                    int k = 0;
                    while (k < NoOfPets) {
                        if (species == myanimals[k].species) {
                            myanimals[k].displayPetDetails();
                            break;
                        }
                        ++k;
                    }
                    break;
                }
                case 2: {
                    string species;
                    cout << "Enter the species: ";
                    cin.ignore(); // Ignore the newline character
                    getline(cin, species);
                    int k = 0;
                    while (k < NoOfPets) {
                        if (species == myanimals[k].species) {
                            myanimals[k].updateHealth();
                            break;
                        }
                        ++k;
                    }
                    break;
                }
                case 3: {
                    string species;
                    cout << "Enter the species: ";
                    cin.ignore(); // Ignore the newline character
                    getline(cin, species);
                    int k = 0;
                    while (k < NoOfPets) {
                        if (species == myanimals[k].species) {
                            myanimals[k].updateHunger();
                            break;
                        }
                        ++k;
                    }
                    break;
                }
                case 4: {
                    clients[i].addpet();
                    break;
                }
                case 5: {
                    clients[i].returnPet();
                    break;
                }
                case 6: {
                    clients[i].displayAdoptedPets();
                    break;
                }
                default: {
                    cout << "Invalid option" << endl;
                }
            }
        }
        ++i;
    }
    delete[] myanimals;
    delete[] clients;
    return 0;
}
