#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    vector<string> bookedPassengers;

public:
    Flight(string num, string dep, string arr, int cap) : 
        flightNumber(num), departure(dep), arrival(arr), capacity(cap) {}

    bool bookSeat(string passengerId) {
        if (bookedPassengers.size() >= capacity) return false;
        bookedPassengers.push_back(passengerId);
        return true;
    }

    bool cancelSeat(string passengerId) {
        for (auto it = bookedPassengers.begin(); it != bookedPassengers.end(); ++it) {
            if (*it == passengerId) {
                bookedPassengers.erase(it);
                return true;
            }
        }
        return false;
    }

    bool upgradeSeat(string passengerId) {
        for (auto& p : bookedPassengers) {
            if (p == passengerId) {
                return true;
            }
        }
        return false;
    }

    int availableSeats() const {
        return capacity - bookedPassengers.size();
    }
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(string i, string n) : id(i), name(n) {}

    bool requestBooking(Flight& flight) {
        return flight.bookSeat(id);
    }

    bool requestCancellation(Flight& flight) {
        return flight.cancelSeat(id);
    }

    bool requestUpgrade(Flight& flight) {
        return flight.upgradeSeat(id);
    }
};

int main() {
    Flight nycToLax("AA123", "NYC", "LAX", 150);
    Passenger john("P100", "John Doe");
    Passenger jane("P101", "Jane Smith");

    john.requestBooking(nycToLax);
    jane.requestBooking(nycToLax);

    cout << "Available seats: " << nycToLax.availableSeats() << endl;

    john.requestCancellation(nycToLax);
    jane.requestUpgrade(nycToLax);

    cout << "Available seats after cancellation: " << nycToLax.availableSeats() << endl;

    return 0;
}