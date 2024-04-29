#include <iostream>
#include <string>

using namespace std;

class Character {
public:
    int health;
    int damage;

    Character(int health, int damage) : health(health), damage(damage) {}

    void display() const {
        cout << "Health: " << health << "\n";
        cout << "Damage: " << damage << "\n";
    }
};

class Enemy : public Character {
public:
    Enemy(int health, int damage) : Character(health, damage) {}

    void display() const {
        cout << "Enemy" << "\n";
        Character::display();
    }
};

class Player : public Character {
public:
    Player(int health, int damage) : Character(health, damage) {}

    void display() const {
        cout << "Player" << "\n";
        Character::display();
    }
};

class Wizard : public Player {
public:
    int magic_power;
    string spells;

    Wizard(int health, int damage, int magic, const string& spells) : Player(health, damage), magic_power(magic), spells(spells) {}

    void display() const {
        cout << "Wizard" << "\n";
        Player::display();
        cout << "Magic Power: " << magic_power << "\n";
        cout << "Spells: " << spells << "\n";
    }
};

int main() {
    Wizard wizard(
        34,
        32,
        56,
        "Shazammm"
    );

    wizard.display();

    return 0;
}
