You are designing a library system using C++. You have a class called "Book" with attributes
like title, author, and publisher. Now, you want to create a derived class called
"FictionBook" which inherits from the "Book" class and has additional attributes like genre
and protagonist.
a) Define the "Book" class with the following attributes:
 title (string)
 author (string)
 publisher (string)
 Define the constructor for the "Book" class which initializes the attributes.
 Define a function called "display" inside the "Book" class which displays the
details of the book.

b) Create a derived class called "FictionBook" which inherits from the "Book" class and
has the following additional attributes:
 genre (string)
 protagonist (string)
 Define the constructor for the "FictionBook" class which initializes the
attributes of the base class as well as the derived class.
 Define a function called "display" inside the "FictionBook" class which
displays the details of the book, including the additional attributes.
 In the main function, create an object of the "FictionBook" class and display its
details.

#include<iostream>
#include<string>
using namespace std;
class book{
	protected:
	string title,author,publisher;
	public:
		book(const string& title,const string& author,const string& publisher):title(title),author(author),publisher(publisher) { }
		void display() {
			cout<<"title:"<<title<<"\nauthor:"<<author<<"\npublisher:"<<publisher<<endl;
		}
};
class fictionbook:public book{
	string genre,protagonist;
	public:
		fictionbook(const string& genre,const string& protagonist,const string& title,const string& author,const string& publisher):book(title,author,publisher),genre(genre),protagonist(protagonist) { }
		void display() {
			book::display();
			cout<<"genre:"<<genre<<"\nprotagonist:"<<protagonist<<endl;
		}
};
int main() {
	string a,b,c,d,e;
	cout<<"enter the title of the book\n";
	getline(cin,a);
	cout<<"enter the author of the book\n";
	getline(cin,b);
	cout<<"enter the publisher of the book\n";
	getline(cin,c);
	cout<<"enter the genre of the book\n";
	getline(cin,d);
	cout<<"enter the protagonist of the book\n";
	getline(cin,e);
	fictionbook fb(d,e,a,b,c); // Create an instance of fictionbook
	fb.display(); // Call the display method on the instance
	return 0;
}

