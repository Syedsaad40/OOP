#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Employee {
    int id;
    string name;
    string designation;
    int years;
};
vector<Employee> employees;
void writeToFile() {
    ofstream file("file.txt");
    for (const auto& e : employees) {
        file << e.id << "," << e.name << "," << e.designation << "," << e.years << "\n";
    }
    file.close();
}
void readFromFile() {
    ifstream file("file.txt");
    employees.clear();
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);
        Employee e;
        e.id = stoi(line.substr(0, pos1));
        e.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        e.designation = line.substr(pos2 + 1, pos3 - pos2 - 1);
        e.years = stoi(line.substr(pos3 + 1));
        employees.push_back(e);
    }
    file.close();
}
vector<Employee> findManagersWith2Years() {
    vector<Employee> result;
    for (const auto& e : employees) {
        if (e.designation == "manager" && e.years >= 2) {
            result.push_back(e);
        }
    }
    return result;2
}
void deleteAllExcept(const vector<Employee>& toKeep) {
    employees = toKeep;
}
void duplicateWithIncrementedIdsAndYears(vector<Employee>& data) {
    for (auto& e : data) {
        e.id += 100;
        e.years += 1;
        employees.push_back(e);
    }
}
int main() {
    employees = {
        {1, "John", "manager", 3},
        {2, "Alice", "developer", 1},
        {3, "Bob", "manager", 2},
        {4, "Eve", "designer", 4}
    };
    writeToFile();
    readFromFile();
    auto queryResult = findManagersWith2Years();
    cout << "Managers with >=2 years:\n";
    for (const auto& e : queryResult) {
        cout << e.id << " " << e.name << " " << e.designation << " " << e.years << "\n";
    }
    deleteAllExcept(queryResult);
    writeToFile();

    readFromFile();
    duplicateWithIncrementedIdsAndYears(queryResult);
    writeToFile();

    readFromFile();
    cout << "Final data:\n";
    for (const auto& e : employees) {
        cout << e.id << " " << e.name << " " << e.designation << " " << e.years << "\n";
    }
    return 0;
}