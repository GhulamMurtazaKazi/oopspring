
#include<iostream>
#include<string>
using namespace std;
int NoOfPets;
class pet{ 
	string healthstatus;
	int hungerlevel;
	int happinesslevel;
	string*specialskills;
	public:
		int totalskills;
		int adoptcount=0;
		string species;
		void setter(int i) {
			int j=0;
			cout << "enter the details for the pet "<<i+1<<endl;
			cout<<"enter the species"<<endl;
			cin>>species;
			cout<<"enter the health  status"<<endl;
			cin>>healthstatus;
			cout<<"enter the hunger level"<<endl;
			cin>>hungerlevel;
			cout<<"enter the happiness level"<<endl;
			cin>>happinesslevel;
			cout<<"enter the total number of special skills this pet have:"<<endl;
			cin>>totalskills;
			cout<<"enter the special skills one by one\n";
			specialskills=new string[totalskills];
			while (j<totalskills) {
				cin>>specialskills[j];
				++j;
			}
		}
	void displayPetDetails() {
		cout<<"This is the "<<species<<":"<<endl;
		cout<<"health status:"<<healthstatus<<endl<<"hunger level:"<<hungerlevel<<endl<<"happiness level:"<<happinesslevel<<endl<<"special skills:";
		int i=0;
		while (i<totalskills) {
			cout<<specialskills[i]<<endl;
			++i;
		}
	}
	void updateHappiness(){
		if (happinesslevel<10) ++happinesslevel;
	}
	void updateHealth(){
		if (healthstatus=="Bad")  
		{
			healthstatus="Good";
			updateHappiness();
		}	 
	}
	void updateHunger(){
		if (hungerlevel>0) {
			--hungerlevel;
			updateHappiness();
		}
	}
};
pet*myanimals;
class adopter{
	string adopterName;
	string adopterMobileNum;
	pet* adoptedPetRecords;
	public:
		adopter() {
			cout<<"Hello dear,welcome to the kazi pet adoption and care centre"<<endl<<"Please proceed with filling your personal info"<<endl;
			cout<<"enter your name"<<endl;
			cin>>adopterName;
			cout<<"enter your mobile number"<<endl;
			cin>>adopterMobileNum;
		}
		void setrecords(int n=NoOfPets) {
		adoptedPetRecords=new pet[n];
		}
		void addpet() {
			string species;
			cout<<"enter the species of pet you want to adopt"<<endl;
			cin>>species;
			int i=0;
			while (i<NoOfPets) {
				if (adoptedPetRecords[i].species==species) 
				{
					adoptedPetRecords[i].adoptcount++;
					return;
				}
				++i;
			}
			int j=0,flag=0;
			while (j<NoOfPets) {
				if (species==myanimals[j].species) {
				adoptedPetRecords[i]=myanimals[j];
				flag=1;	
				}
				++j;
				if (flag==1) {
					adoptedPetRecords[j].adoptcount=0;
				}
			}
			}
			void returnPet(){
				if (happinesslevel>0) --happinesslevel;
					string species;
			cout<<"enter the species of pet you want to return"<<endl;
			cin>>species;
			int i=0;
			while (i<NoOfPets) {
				if (adoptedPetRecords[i].species==species) 
				{
					adoptedPetRecords[i].adoptcount--;
					return;
				}
				++i;
			}
			}
			void displayAdoptedPets() {
				int i=0;
				while (i<NoOfPets) {
				if (adoptedPets[i].adoptcount!=0)	adoptedPetRecords[i].displayPetDetails();
					++i;
				}
			}
};
int main() {
	int TotalAdop;
	string species;
	cout<<"enter the total number of pets"<<endl;
	cin>>NoOfPets;
	myanimals=new pet[NoOfPets];
	int i=0,j,k;
	while (i<NoOfPets) {
		myanimals[i].setter(i);
		++i;
	}
	cout<<"enter the total number of adopters registered for today\n";
	cin>>TotalAdop;
	adopter* clients=new adopter[TotalAdop];
	i=0;
	while (i<TotalAdop) {
		while (1) { 
		cout<<"enter 1 to view the details of a specific animal\nenter 2 to update the health status\nenter 3 to update the hunger\nenter 4 to adopt a animal\nenter 5 to return a adopted animal\nenter 6 display the adopted animal list\nenter 7 to exit\n";
		cin>>j;
		if (j==7) break;
		if (j==1) {
			cout<<"enter the species\n";
		cin>>species;
		k=0;
		while (k<NoOfPets) {
			if (species==myanimals[k].species) {
				myanimals[k].displayPetDetails();
				break;
			}
			++k;
		}
	}
		if (j==2) {
			cout<<"enter the species\n";
		cin>>species;
			k=0;
		while (k<NoOfPets) {
			if (species==myanimals[k].species) {
				myanimals[k].updateHealth();
				break;
			}
			++k;
		}
		}
		if (j==3) {
			cout<<"enter the species\n";
		cin>>species;
			k=0;
		while (k<NoOfPets) {
			if (species==myanimals[k].species) {
				myanimals[k].updateHunger();
				break;
			}
			++k;
		}
		}
		if (j==4) {
			clients[i].addpet();
		}
		if (j==5) {
			clients[i].returnPet();
		}
		if (j==6) {
				clients[i].displayAdoptedPets();
						}
		}
		++i;
	}
	return 0;
}
