#include <iostream>
using namespace std;

class Book {
    string title;
    string author;
    string publisher;
public:
    Book(string title, string author, string publisher) {
        this->title = title;
        this->author = author;
        this->publisher = publisher;
    }

    void display() {
        cout << "Title of Book: " << title << endl;
        cout << "Author of Book: " << author << endl;
        cout << "Publisher of Book: " << publisher << endl;
    }
};

class FictionBook : public Book {
    string genre;
    string protagonist;
public:
    FictionBook(string title, string author, string publisher, string genre, string protagonist) : Book(title, author, publisher) {
        this->genre = genre;
        this->protagonist = protagonist;
    }

    void display() {
        Book::display(); // Call base class display function
        cout << "Genretion of Book: " << genre << endl;
        cout << "Protagonist of Book: " << protagonist << endl;
    }
};

int main(int argc, char const *argv[]) {
    FictionBook book("OOPs", "kazi", "Anonimus", "12th", "Jay");
    book.display();
    return 0;
}
