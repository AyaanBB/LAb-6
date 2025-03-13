#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title, author, publisher;

public:
    Book(string t, string a, string p) : title(t), author(a), publisher(p) {}

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

class FictionBook : public Book {
private:
    string genre, protagonist;

public:
    FictionBook(string t, string a, string p, string g, string pro)
        : Book(t, a, p), genre(g), protagonist(pro) {}

    void display() {
        Book::display();
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};

int main() {
    FictionBook myBook("The Enchanted Code", "Alice Coder", "TechReads", "Fantasy", "Eleanor the Debugger");
    cout << "Book Details:\n";
    myBook.display();
    return 0;
}
