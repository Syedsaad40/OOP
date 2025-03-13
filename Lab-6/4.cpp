#include <iostream>
#include <string>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string a) : genre(a) {}
};

class Mystery : virtual public Books {
    string title;
    string author;
public:
    Mystery(string a, string b, string c) : Books(a), title(b), author(c) {}

    void displaydetails() {
        cout << "Book Details:" << endl;
        cout << "Genre is: " << genre << endl;
        cout << "Author is: " << author << endl;
        cout << "Title is: " << title << endl;
    }
};

class Fiction : virtual public Books {
    string title;
    string author;
public:
    Fiction(string a, string b, string c) : Books(a), title(b), author(c) {}

    void displaydetails() {
        cout << "Book Details:" << endl;
        cout << "Genre is: " << genre << endl;
        cout << "Author is: " << author << endl;
        cout << "Title is: " << title << endl;
    }
};

int main() {
    Mystery m("Mystery", "The Girl with the Dragon Tattoo", "Stieg Larsson");
    Fiction f("Fiction", "The Night Circus", "Erin Morgenstern");
    m.displaydetails();
    f.displaydetails();
    return 0;
}