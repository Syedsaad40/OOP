#include<iostream>
#include<string>
using namespace std;

class Car {
    string engine;
    int horsepower;
    int seating_capacity;
    int num_speakers;
public:
    Car(string n, int a, int b, int c) : engine(n), horsepower(a), seating_capacity(b), num_speakers(c) {}
    void change_seating_capacity(int c) const {
        const_cast<Car*>(this)->seating_capacity = c;
        cout << "The new seating capacity is: " << seating_capacity << endl;
    }
};

int main() {
    Car c1("bugatti", 700, 2, 4);
    c1.change_seating_capacity(10);
    return 0;
}