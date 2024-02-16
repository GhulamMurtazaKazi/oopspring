Forge a class labelled "Smartphone" possessing the following attributes:
• Brand
• Model
• Display Resolution
• RAM
• ROM
• Storage
Develop getter and setter methods for these attributes. Additionally, define specific actions
smartphones can perform, such as:
• Making phone calls
• Sending messages
• Connecting to Wi-Fi
• Browsing the internet
Create distinct smartphone objects, set their attributes using setter functions, and exhibit
their attributes after retrieving them using getter functions.

  #include<iostream>
using namespace std;
int i=0;
class smartphone{
	string brand,model;
	int display,ram,rom,storage;
	public:
		void setbrand(string str) {
			brand=str;
		}
		void setmodel(string str) {
			model=str;
		}
		void setdisplay(int n) {
			display=n;
		}
		void setram(int n) {
			ram=n;
		}
		void setrom(int n) {
			rom=n;
		}
		void setstorage(int n) {
			storage=n;
		}
		string getbrand() {
			return brand;
		}
		string getmodel() {
			return model;
		}
		int getdisplay() {
			return display;
		}
		int getram() {
			return ram;
		}
		int getrom() {
			return rom;
		}
		int getstorage() {
			return storage;
		}
		void makecall(int n) {
			if (n==1) {
			if (i==1) 
			cout<<"phone dialed successfully\n";
			else 
			cout<<"please try again later\n";
		}
		}
		void sendsms(int n) {
			if (n==1) {
			if (i==1) cout<<"message sent\n";
			else cout<<"you are out of credit\n";
		}
		}
		void connectwifi(int n) {
			if (n==1) {
			if (i==1) cout<<"You are connected to GWN-Fast\n";
			else cout<<"No Internet \n";
		}
		}
		void browse(int n) {
			if (n==1) {
			if (i==1) 
			cout<<"Welcome to the internet explorer\n";
			else cout<<"error 404\n";
		}
		}
};
int main () {
	int num,j=0,n;
	string str;
	cout<<"enter total no of smartphones\n";
	cin>>num;
	cin.ignore();
	smartphone * arr= new smartphone[num];
	while (j<num) {
		cout<<"enter the details for smartphone "<<j+1<<endl;
		cout<<"enter the brand\n";
		getline(cin,str);
		arr[j].setbrand(str);
		cout<<"enter the model\n";
		getline(cin,str);
		arr[j].setmodel(str);
		cout<<"enter the display\n";
		cin>>n;
		arr[j].setdisplay(n);
		cout<<"enter the ram\n";
		cin>>n;
		arr[j].setram(n);
		cout<<"enter the rom\n";
		cin>>n;
		arr[j].setrom(n);
		cout<<"enter the storage\n";
		cin>>n;
		cin.ignore();
		arr[j].setstorage(n);
		++j;
	}
	j=0;
	while (j<num) {
		cout<<"mobile no "<<j+1<<endl;
		cout<<"brand="<<arr[j].getbrand()<<endl;
		cout<<"model="<<arr[j].getmodel()<<endl;
		cout<<"display resolution="<<arr[j].getdisplay()<<endl;
		cout<<"ram="<<arr[j].getram()<<endl;
		cout<<"rom="<<arr[j].getrom()<<endl;
		cout<<"storage="<<arr[j].getstorage()<<endl;
		cout<<"do you want to make a phone call"<<endl;
		cin>>n;
		arr[j].makecall(n);
		cout<<"do you want to send a sms"<<endl;
		cin>>n;
		arr[j].sendsms(n);
		cout<<"do you want to connect your phone to wifi"<<endl;
		cin>>n;
		arr[j].connectwifi(n);
		cout<<"do you want to browse"<<endl;
		cin>>n;
		arr[j].browse(n);
		++j;
	}
	return 0;
}
