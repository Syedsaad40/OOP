#include<iostream>
#include<string>
#include<vector>
using namespace std;

class CoffeeShop {
    string name;
    vector<string> menu;
    vector<string> orders;
    vector<string> itemType; 
    vector<double> itemPrice; 

public:
    CoffeeShop(string n) : name(n) {}

    void addMenuItem(string item, string type, double price) {
        menu.push_back(item);
        itemType.push_back(type);
        itemPrice.push_back(price);
    }

    void addOrder(string item) {
        bool found = false;
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i] == item) {
                orders.push_back(item);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "This item is currently unavailable" << endl;
        }
    }

    string fulfillOrder() {
        if (orders.empty()) {
            return "All orders have been fulfilled";
        }
        string item = orders.front();
        orders.erase(orders.begin());
        return "The " + item + " is ready";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (size_t i = 0; i < menu.size(); i++) {
                if (menu[i] == order) {
                    total += itemPrice[i];
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double minPrice = itemPrice[0];
        string cheapest = menu[0];
        for (size_t i = 1; i < itemPrice.size(); i++) {
            if (itemPrice[i] < minPrice) {
                minPrice = itemPrice[i];
                cheapest = menu[i];
            }
        }
        return cheapest;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (size_t i = 0; i < itemType.size(); i++) {
            if (itemType[i] == "drink") {
                drinks.push_back(menu[i]);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (size_t i = 0; i < itemType.size(); i++) {
            if (itemType[i] == "food") {
                food.push_back(menu[i]);
            }
        }
        return food;
    }
};

int main() {
    CoffeeShop shop("Cafe XYZ");

    shop.addMenuItem("Coffee", "drink", 5.5);
    shop.addMenuItem("Tea", "drink", 3.0);
    shop.addMenuItem("Sandwich", "food", 4.0);
    
    shop.addOrder("Coffee");
    shop.addOrder("Tea");

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    vector<string> orders = shop.listOrders();
    for (const string& order : orders) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total due: " << shop.dueAmount() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    for (const string& drink : drinks) {
        cout << drink << " ";
    }
    cout << endl;

    vector<string> food = shop.foodOnly();
    for (const string& f : food) {
        cout << f << " ";
    }
    cout << endl;

    return 0;
}
