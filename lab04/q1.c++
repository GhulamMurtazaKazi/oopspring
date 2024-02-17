Construct a class representing a Book, encompassing attributes like name, author, ISBN number,
and total page count, along with a variable tracking the number of pages read. Tasks include
defining constructors for the Book class - one default constructor and another parameterized
constructor initializing all attributes. Values can be hardcoded within the main function.
Additionally, implement a method to update the pages read, triggering a display of "You have
finished the book" when all pages are read. This method should be called from the main
function to monitor reading progress.

#include<iostream>
#include<string>
using namespace std;
class book{
	string name,author;
	long long int ISBN;
	int total_pages,pages_read;
	public:
		book() {
			name="";
			author="";
			ISBN=0;
			total_pages=0;
			pages_read=0;
		}
		book(string n,string a,long long int code,int p,int p_read) {
			name=n;
			author=a;
			ISBN=code;
			total_pages=p;
			pages_read=p_read;
			if (pages_read==total_pages) cout<<"You have finished the book\n";
		}
		void updatepages(int p) {
			pages_read=p;
			if (p==total_pages) cout<<"You have finished the book\n";
		}
};
int main () {
	int n;
	cout<<"enter the number  of books\n";
	cin>>n;
	cin.ignore();
	book*collection=new book[n];
	string name,a;
	long long int code;
	int p,p_read,i=0;
	while (i<n) {
		cout<<"enter the name of the book\n";
		getline(cin,name);
		cout<<"enter the name of the author\n";
		getline(cin,a);
		cout<<"enter the ISBN number of your book\n";
		cin>>code;
		cout<<"enter total number of pages and pages read\n";
		cin>>p>>p_read;
		collection[i]=book(name,a,code,p,p_read);
		cout<<"do you want to update the no of pages read\n";
		cin>>p;
		cin.ignore();
		if (p==1) {
			cout<<"enter the pages read\n";
			cin>>p_read;
				cin.ignore();
		collection[i].updatepages(p_read);
	}
	++i;
	}
	return 0;
}
