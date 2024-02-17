Revise the previous Book class by eliminating the parameterized constructor and enhancing the
default constructor. The revised default constructor should initialize the page count to 1000
and the pages read to 0 using a member initialization list. Generate setter methods for the
remaining attributes and utilize them within the main function to update attribute values. Introduce
a method called "showBookInfo" to exhibit all book details. Invoke this method from the main
function for displaying book information.

  #include<iostream> 
#include<string>
using namespace std;
class book {
	string name,author;
	long long int ISBN;
	int pages_total,pages_read;
	public:
		book():pages_total(1000),pages_read(0) { }
		void setname(string str) {
			name=str;
		}
		void setauthor(string str) {
			author=str;
		}
		void setcode(long long int code) {
			ISBN=code;
		}
		void updatepages(int p){
			pages_read=p; 
			if (pages_read==1000) cout<<"You  have finished the book\n";
		}
		void showbookinfo() {
			cout<<"name of the book is:"<<name<<endl;
			cout<<"author  of the book is:"<<author<<endl;
			cout<<"ISBN number:"<<ISBN<<endl;
			cout<<"Total pages are 1000\n";
			cout<<"pages read are "<<pages_read<<endl;
		}
};
int main() {
	int n,i=0,var;
	cout<<"enter the number of books\n";
	cin>>n;
	cin.ignore();
	book* collection=new book[n];
	string str;
	long long int code;
	while (i<n) {
		cout<<"enter the name  of the book\n";
		getline(cin,str);
		collection[i].setname(str);
		cout<<"enter the author of the book\n";
			getline(cin,str);
		collection[i].setauthor(str);
		cout<<"enter the ISBN number of your book\n";
		cin>>code;
		collection[i].setcode(code);
		cout<<"do you want to update the page count\n";
		cin>>var;
		if (var==1) {
			cout<<"enter the number of pages read\n";
			cin>>var;
		collection[i].updatepages(var);
	}
	cout<<"do you want to see your book details\n";
	cin>>var;
	cin.ignore();
	if (var==1) collection[i].showbookinfo();
	++i;
	}
	
	return 0;
}
