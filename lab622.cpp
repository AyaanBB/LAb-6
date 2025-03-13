#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int health, damage;

public:
    Character(string n, int h, int d) {
        name = n;
        health = h;
        damage = d;
    }

    void display() {
        cout << "Name: " << name << "\nHealth: " << health << "\nDamage: " << damage << endl;
    }
};

class Enemy : public Character {
public:
    Enemy(string n, int h, int d) : Character(n, h, d) {}

    void display() {
        cout << "Enemy Details:\n";
        Character::display();
    }
};

class Player : public Character {
public:
    Player(string n, int h, int d) : Character(n, h, d) {}

    void display() {
        cout << "Player Details:\n";
        Character::display();
    }
};

class Wizard : public Player {
protected:
    string magicType;

public:
    Wizard(string n, int h, int d, string magic) : Player(n, h, d) {
        magicType = magic;
    }

    void display() {
        cout << "Wizard Details:\n";
        Player::display();
        cout << "Magic Type: " << magicType << endl;
    }
};

int main() {
    Wizard mage("Gandalf", 100, 50, "Elemental Magic");

    cout << "Summoning Wizard...\n";
    mage.display();

    return 0;
}
