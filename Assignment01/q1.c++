Scenario 1:
You are tasked with designing a platform named Virtual Pet Adoption System where users can adopt and
care for virtual pets with advanced capabilities. The system comprises two essential classes: "Pet" and
"Adopter." Your goal is to implement the system with extended features to enhance user experience and
satisfaction.
Pet Class:
The Pet class represents virtual pets available for adoption. It has following features:
● healthStatus: A string indicating the health status of the pet (e.g., "Healthy," "Sick").
● hungerLevel: An integer representing the pet's hunger level.
● happinessLevel: An integer representing the pet's happiness level.
● specialSkills: A list containing special skills possessed by the pet.
Implement the following member functions within the Pet class:
● displayPetDetails(): Displays detailed information about the pet, including happiness level, health
status, hunger level, and special skills.
● updateHappiness(): Updates the pet's happiness level based on user interactions.
● updateHealth(): Updates the health status of the pet, considering any changes in health.
● updateHunger(): Updates the hunger level of the pet, accounting for feeding or other relevant
actions.
Moreover, if a pet is hungry their happiness also decreases by 1 and vice versa. And if you feed it the
happiness increases by 1 upto max 10 happiness.
Adopter Class:
The Adopter class serves as a representation of users who are enthusiastic about adopting virtual pets. In
order to enrich the functionality of this class, you are tasked with incorporating the following features:
adopterName and adopterMobileNum, these attributes should be initialized during the creation of an
Adopter object. A list named adoptedPetRecords within the Adopter class. This list should be responsible
for maintaining detailed records of the adopted pets by the respective adopter.
Implement the following member functions within the Adopter class:
● adoptPet(): Allows the adopter to adopt a virtual pet and records its details.
● returnPet(): Enables the adopter to return a pet, updating records accordingly.
● displayAdoptedPets(): Displays detailed information about all adopted pets, including their species,
happiness, health, hunger, and skills.
Create instances of the extended Pet class, showcasing diverse characteristics and skills for virtual pets.
Instantiate objects of the enhanced Adopter class to represent users interested in adopting virtual pets.
Demonstrate the functionalities of both classes by simulating the adoption, care, and interaction with virtual
pets.


#include <iostream>
#include <string>
using namespace std;

int NoOfPets;

class pet {
    string healthstatus;
    int hungerlevel;
    int happinesslevel;
    string *specialskills;
public:
    string species;
    int adoptcount;
	int totalskills;

    // Constructor
    pet() {
    	species="0";
        specialskills = 0;
        totalskills = 0;
        adoptcount = 0;
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
        cout << "Enter the happiness level: ";
        cin >> happinesslevel;
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
    
    // Destructor to deallocate memory
    ~pet() {
        delete[] specialskills;
    }

    void displayPetDetails() {
        cout << "Species: " << species << endl;
        cout << "Health status: " << healthstatus << endl;
        cout << "Hunger level: " << hungerlevel << endl;
        cout << "Happiness level: " << happinesslevel << endl;
        if (adoptcount>0) 
        cout<< "you have adopted "<<adoptcount<<" "<<species<<endl;
        cout << "Special skills: ";
        for (int i = 0; i < totalskills; ++i) {
            cout << specialskills[i] <<" , ";
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
public:
    adopter() {
        cout << "Hello, welcome to the Kazi Pet Adoption and Care Centre" << endl;
        cout << "Please proceed with filling your personal info" << endl;
        cout << "Enter your name: ";
        getline(cin, adopterName);
        cout << "Enter your mobile number: ";
        getline(cin, adopterMobileNum);
          adoptedPetRecords = new pet[NoOfPets];
    }
	~adopter() {
        delete[] adoptedPetRecords;
    }
    void addpet() {
        string species;
        cout << "Enter the species of pet you want to adopt: ";
        cin.ignore();
        getline(cin, species);
        int i;
        for (i = 0; i < NoOfPets; ++i) {
        	if (adoptedPetRecords[i].species=="0") break;
            if (adoptedPetRecords[i].species == species) {
                adoptedPetRecords[i].adoptcount++;
                 int j=0;
        while (j<NoOfPets) {
        	if (species==myanimals[j].species) {
                	myanimals[j].updateHappiness();
                	return;
                }
                ++j;
            } 
        } 
    }
        int j=0;
        while (j<NoOfPets) {
        	if (species==myanimals[j].species) {
        		adoptedPetRecords[i]=myanimals[j];
        		adoptedPetRecords[i].adoptcount++;
        		myanimals[j].updateHappiness();
        		break;
			}
			++j;
		}
	}

    void returnPet() {
        string species;
        cout << "Enter the species of pet you want to return: ";
          cin.ignore();
        getline(cin, species);
        for (int i = 0; i < NoOfPets; ++i) {
            if (adoptedPetRecords[i].species == species) {
                adoptedPetRecords[i].adoptcount--;
                myanimals[i].decrHappiness();
                return;
            }
        }
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
