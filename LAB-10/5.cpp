#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> tasks;

void loadTasks() {
    ifstream file("todo.txt");
    string task;
    while(getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();
}

void saveTasks() {
    ofstream file("todo.txt");
    for(auto& task : tasks) {
        file << task << endl;
    }
    file.close();
}

void addTask(string task) {
    tasks.push_back("[ ] " + task);
    saveTasks();
}

void viewTasks() {
    for(int i = 0; i < tasks.size(); i++) {
        cout << i+1 << ". " << tasks[i] << endl;
    }
}

void markDone(int index) {
    if(index >= 0 && index < tasks.size()) {
        tasks[index].replace(1, 1, "X");
        saveTasks();
    }
}

int main() {
    loadTasks();
    
    while(true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task Done\n4. Exit\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        
        if(choice == 1) {
            cout << "Enter task: ";
            string task;
            getline(cin, task);
            addTask(task);
        }
        else if(choice == 2) {
            viewTasks();
        }
        else if(choice == 3) {
            viewTasks();
            cout << "Enter task number to mark done: ";
            int num;
            cin >> num;
            markDone(num-1);
        }
        else if(choice == 4) {
            break;
        }
    }
    
    return 0;
}