Envision that you’re assigned to create a program to handle a library’s book inventory.
Each book has characteristics such as title, author, year of publication, and
genre. Construct a struct that accurately depicts a book as an entity in the real world.
Then, using a programming C++, write a basic program that uses this struct to
demonstrate the creation, modification, and display of book data.
1. Expand the program to manage an array of multiple books.
2. Develop a function to find a book by its title or author.
3. Enable the user to interactively input new books and update existing book data.

  #include<iostream>
#include<algorithm>
using namespace std;

struct book {
	string title;
	string author;
	int year;
	string genre;
};

void bookbytitle(book* array, int n) {
	int i=0;
	string title;
	cout << "Enter title: ";
	getline(cin, title);
	while (i<n) {
		if (array[i].title==title) {
			cout<<array[i].title<<endl<<array[i].author<<endl<<array[i].year<<endl<<array[i].genre<<endl;
			return;
		}
		++i;
	}
}

void bookbyauthor(book* array, int n) {
	int i=0;
	string author;
	cout << "Enter author: ";
	getline(cin, author);
	while (i<n) {
		if (array[i].author==author) {
			cout<<array[i].title<<endl<<array[i].author<<endl<<array[i].year<<endl<<array[i].genre<<endl;
			return;
		}
		++i;
	}
}

int main () {
	int n, i=0, flag=1, j;
	cout<<"enter the number of books\n";
	cin>>n;
	book* library1 = new book[n];
	book* library2 ;
	while (i<n) {
		cout<<"enter the details for book "<<i+1<<endl;
		cout<<"enter title\n";
		cin.ignore();
		getline(cin,library1[i].title);
		cout<<"enter author\n";
		getline(cin,library1[i].author);
		cout<<"enter the year of  publication\n";
		cin>>library1[i].year;
		cin.ignore();
		cout<<"enter genre\n";
		getline(cin,library1[i].genre);
		++i;
	}
	i=0;
	while  (1) {
		cout<<"enter 1 to insert new books\nenter 2 to update\nenter 3 to find book by title\nenter 4 to find book by author\nenter 0 to exit\n";
		cin>>i;
		cin.ignore();
		if (i==1) {
			if (flag==1) {
				flag=0;
				cout<<"how many new books do you want to add\n";
				cin>>i;
				library2=new book[n+i];
				copy(library1,library1+n,library2);
				delete[] library1;
				while (i>0) {
					cout<<"enter title\n";
					cin.ignore();
					getline(cin,library2[n].title);
					cout<<"enter author\n";
					getline(cin,library2[n].author);
					cout<<"enter the year of  publication\n";
					cin>>library2[n].year;
					cin.ignore();
					cout<<"enter genre\n";
					getline(cin,library2[n].genre);
					++n;
					--i;
				}
			}
		else {
			flag=1;
			cout<<"how many new books do you want to add\n";
			cin>>i;
			library1=new book[n+i];
			copy(library2,library2+n,library1);
			delete[] library2;
			while (i>0) {
				cout<<"enter title\n";
				cin.ignore();
				getline(cin,library1[n].title);
				cout<<"enter author\n";
				getline(cin,library1[n].author);
				cout<<"enter the year of  publication\n";
				cin>>library1[n].year;
				cin.ignore();
				cout<<"enter genre\n";
				getline(cin,library1[n].genre);
				++n;
				--i;
			}
		}
	}
		else if (i==2) {
			cout<<"enter the  book no  you want  to update\n";
			cin>>i;
			cout<<"press 1 to update title\npress 2 to update author\npress 3 to year\npress 4 to update genre\n";
			cin>>j;
			if (flag==1) {
				if (j==1) cin>>library1[i-1].title;
				else if (j==2) cin>>library1[i-1].author;
				else if (j==3) cin>>library1[i-1].year;
				else cin>>library1[i-1].genre;
			}
			else {
				if (j==1) cin>>library2[i-1].title;
				else if (j==2) cin>>library2[i-1].author;
				else if (j==3) cin>>library2[i-1].year;
				else cin>>library2[i-1].genre;
			}
		}
		else if (i==3) {
			if (flag==1) 
				bookbytitle(library1,n);
			else 
				bookbytitle(library2,n);
		}
		else if (i==4) {
			if (flag==1) 
				bookbyauthor(library1,n);
			else 
				bookbyauthor(library2,n);
		}
		else if (i==0) return 0;
	}
}
