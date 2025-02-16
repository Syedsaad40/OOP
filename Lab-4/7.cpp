#include<iostream>
#include<string>
using namespace std;

class Book {
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
    Book(string a, string t, double p, string pub, int s) 
        : author(a), title(t), price(p), publisher(pub), stock(s) {}

    bool isAvailable(const string &t, const string &a) {
        return title == t && author == a;
    }

    void displayDetails() {
        cout << "Title: " << title << ", Author: " << author << ", Price: " << price 
             << ", Publisher: " << publisher << ", Stock: " << stock << endl;
    }

    bool checkStock(int requestedCopies) {
        if (stock >= requestedCopies) {
            double totalCost = price * requestedCopies;
            cout << "Total cost: " << totalCost << endl;
            stock -= requestedCopies;
            return true;
        }
        return false;
    }
};

int main() {
    Book book1("J.K. Rowling", "Harry Potter", 29.99, "Bloomsbury", 10);
    string title, author;
    int copies;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);

    if (book1.isAvailable(title, author)) {
        book1.displayDetails();
        cout << "Enter number of copies required: ";
        cin >> copies;
        if (!book1.checkStock(copies)) {
            cout << "Required copies not in stock" << endl;
        }
    } else {
        cout << "Book not available" << endl;
    }

    return 0;
}
