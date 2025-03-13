#include <iostream>
using namespace std;

class Position {
protected:
    int x, y, z;

public:
    Position(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    void setPosition(int newX, int newY, int newZ) {
        x = newX;
        y = newY;
        z = newZ;
    }

    void displayPosition() {
        cout << "Position: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Health {
protected:
    int health;

public:
    Health(int h = 100) : health(h) {}

    void setHealth(int h) {
        health = h;
    }

    void displayHealth() {
        cout << "Health: " << health << endl;
    }
};

class Character : public Position, public Health {
private:
    string name;

public:
    Character(string n, int x, int y, int z, int h) 
        : name(n), Position(x, y, z), Health(h) {}

    void displayCharacter() {
        cout << "Character: " << name << endl;
        displayPosition();
        displayHealth();
    }
};

int main() {
    Character hero("Warrior King", 15, 25, 5, 90);

    cout << "Character Details:\n";
    hero.displayCharacter();

    return 0;
}
