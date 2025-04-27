#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Logger {
    string baseName;
    int maxSize;
    int currentFileNum;
    
public:
    Logger(string name, int size) : baseName(name), maxSize(size), currentFileNum(1) {}
    
    void log(string message) {
        string fileName = baseName + to_string(currentFileNum) + ".txt";
        ofstream file(fileName, ios::app);
        
        if(file.tellp() > maxSize) {
            file.close();
            currentFileNum++;
            fileName = baseName + to_string(currentFileNum) + ".txt";
            file.open(fileName);
        }
        
        file << message << endl;
        file.close();
    }
};

int main() {
    Logger logger("log", 100);
    
    for(int i = 0; i < 50; i++) {
        logger.log("This is log message number " + to_string(i));
    }
    
    return 0;
}