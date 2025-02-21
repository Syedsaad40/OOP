#include<iostream>
#include<string>
using namespace std;

class Engine {
bool isRunning;
public:
Engine() {
cout << "Engine Constructed" << endl;
}
~Engine() {
cout << "Engine Destroyed" << endl;
}
bool get_isRunning() {
return true;
}
void start() {
cout << "Engine Started..." << endl;
}
void stop() {
cout << "Engine stopped..." << endl;
}
};

class Car {
Engine engine;
public:
Car() {
cout << "Car Constructed" << endl;
}
~Car() {
cout << "Car Destroyed" << endl;
}
void startcar() {
engine.start();
}
void stopcar() {
engine.stop();
}
};

int main() {
Car c1;
c1.startcar();
c1.stopcar();
return 0;
}