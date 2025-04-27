#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string user_id;
    string first_name;
    string last_name;
    string address;
    string email;
};

struct Product {
    string product_id;
    string product_name;
    string description;
    int price;
};

struct Order {
    string order_id;
    string user;
    string product_ordered;
    int total_paid;
};

vector<User> users;
vector<Product> products;
vector<Order> orders;

void createDummyData() {
    users.push_back({"1", "Linus", "Torvalds", "Linux Street", "linus@linux.com"});
    users.push_back({"2", "Bill", "Gates", "Microsoft Ave", "bill@microsoft.com"});
    
    products.push_back({"101", "Linux OS", "Open source OS", 0});
    products.push_back({"102", "Windows", "Proprietary OS", 199});
    products.push_back({"103", "MacOS", "Apple OS", 299});
    
    orders.push_back({"1001", "1", "101", 0});
    orders.push_back({"1002", "1", "103", 299});
    orders.push_back({"1003", "2", "102", 199});
}

void saveToFile() {
    ofstream file("database.txt");
    for(auto& u : users)
        file << "USER|" << u.user_id << "|" << u.first_name << "|" << u.last_name << "|" << u.address << "|" << u.email << "\n";
    for(auto& p : products)
        file << "PRODUCT|" << p.product_id << "|" << p.product_name << "|" << p.description << "|" << p.price << "\n";
    for(auto& o : orders)
        file << "ORDER|" << o.order_id << "|" << o.user << "|" << o.product_ordered << "|" << o.total_paid << "\n";
    file.close();
}

void loadFromFile() {
    ifstream file("database.txt");
    string line;
    while(getline(file, line)) {
        size_t pos = 0;
        string token;
        vector<string> tokens;
        while((pos = line.find('|')) != string::npos) {
            token = line.substr(0, pos);
            tokens.push_back(token);
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);
        
        if(tokens[0] == "USER")
            users.push_back({tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]});
        else if(tokens[0] == "PRODUCT")
            products.push_back({tokens[1], tokens[2], tokens[3], stoi(tokens[4])});
        else if(tokens[0] == "ORDER")
            orders.push_back({tokens[1], tokens[2], tokens[3], stoi(tokens[4])});
    }
    file.close();
}

vector<string> getProductsForUser(string firstName) {
    vector<string> result;
    for(auto& u : users) {
        if(u.first_name == firstName) {
            for(auto& o : orders) {
                if(o.user == u.user_id) {
                    for(auto& p : products) {
                        if(p.product_id == o.product_ordered) {
                            result.push_back(p.product_name);
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    createDummyData();
    saveToFile();
    loadFromFile();
    
    vector<string> products = getProductsForUser("Linus");
    for(auto& p : products)
        cout << p << endl;
    
    return 0;
}