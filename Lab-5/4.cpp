#include <iostream>
#include <string>
using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice...\n";
        for (int i = 0; i < 400000000; i++);
        cout << "Juice blended!\n";
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice...\n";
        for (int i = 0; i < 500000000; i++);
        cout << "Juice ground!\n";
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void blendJuice() {
        blender.blendJuice();
    }

    void grindJuice() {
        grinder.grindJuice();
    }
};

int main() {
    JuiceMaker maker;
    maker.blendJuice();
    maker.grindJuice();
    return 0;
}