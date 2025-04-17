#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int creditHours) = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
    string researchTopic;
public:
    void setResearchTopic(string topic) { researchTopic = topic; }
    string getResearchTopic() { return researchTopic; }
    double getTuition(string status, int creditHours) override {
        if (status == "undergraduate") return creditHours * 200;
        else if (status == "graduate") return creditHours * 300;
        else if (status == "doctoral") return creditHours * 400;
        return 0;
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("Machine Learning");
    
    cout << "Research Topic: " << gs.getResearchTopic() << endl;
    cout << "Graduate Tuition (6 credits): $" 
         << gs.getTuition("graduate", 6) << endl;
    
    return 0;
}