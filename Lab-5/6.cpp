#include<iostream>
#include<string>
#include<vector>
using namespace std;

class CoffeeShop {
public:
    const string name;
    vector<string> menu;
    vector<string> orders;

    CoffeeShop(string n, vector<string> m) : name(n), menu(m) {}

    void addOrder(string item) {
        for (string i : menu) {
            if (i == item) {
                orders.push_back(item);
                return;
            }
        }
        cout << "This item is currently unavailable!" << endl;
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders[0];
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled!";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount(vector<double> prices) {
        double total = 0;
        for (string item : orders) {
            for (int i = 0; i < menu.size(); i++) {
                if (menu[i] == item) {
                    total += prices[i];
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem(vector<double> prices) {
        double minPrice = prices[0];
        string cheapItem = menu[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                cheapItem = menu[i];
            }
        }
        return cheapItem;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (string item : menu) {
            if (item == "Coffee" || item == "Tea" || item == "Juice") {
                drinks.push_back(item);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (string item : menu) {
            if (item == "Sandwich" || item == "Cake" || item == "Pizza") {
                food.push_back(item);
            }
        }
        return food;
    }
};

int main() {
    vector<string> menu = {"Coffee", "Tea", "Juice", "Sandwich", "Cake"};
    vector<double> prices = {2.5, 1.5, 3.0, 5.0, 4.0};

    CoffeeShop shop("My Coffee Shop", menu);
    shop.addOrder("Coffee");
    shop.addOrder("Cake");

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    for (string order : shop.listOrders()) {
        cout << order << endl;
    }

    cout << "Total due amount: " << shop.dueAmount(prices) << endl;
    cout << "Cheapest item: " << shop.cheapestItem(prices) << endl;

    for (string drink : shop.drinksOnly()) {
        cout << drink << endl;
    }

    for (string food : shop.foodOnly()) {
        cout << food << endl;
    }

    return 0;
}