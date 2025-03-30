#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
public:
    Media(string t, string pd, string id, string pub) : title(t), publicationDate(pd), uniqueID(id), publisher(pub) {}
    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }
    void checkOut() { cout << title << " checked out" << endl; }
    void returnItem() { cout << title << " returned" << endl; }
};

class Book : public Media {
    string author;
    string ISBN;
    int numberOfPages;
public:
    Book(string t, string pd, string id, string pub, string a, string isbn, int pages) 
        : Media(t, pd, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    string director;
    int duration;
    string rating;
public:
    DVD(string t, string pd, string id, string pub, string dir, int dur, string rat) 
        : Media(t, pd, id, pub), director(dir), duration(dur), rating(rat) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins" << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
    string artist;
    int numberOfTracks;
    string genre;
public:
    CD(string t, string pd, string id, string pub, string art, int tracks, string g) 
        : Media(t, pd, id, pub), artist(art), numberOfTracks(tracks), genre(g) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Book b("The C++ Programming", "2020-01-01", "B001", "TechPub", "Bjarne", "123-456", 500);
    DVD d("Inception", "2010-07-16", "D001", "Warner", "Nolan", 148, "PG-13");
    CD c("Thriller", "1982-11-30", "C001", "Epic", "Michael", 9, "Pop");

    b.displayInfo();
    d.displayInfo();
    c.displayInfo();

    b.checkOut();
    d.returnItem();

    return 0;
}