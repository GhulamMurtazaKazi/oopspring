#include <iostream>
using namespace std;

class position
{
public:
    float x, y, z;

    position(float a, float b, float c) : x(a), y(b), z(c) {}
};

class Health
{
public:
    int health;

    Health(int hp) : health(hp) {}
};

class Player : public position, public Health
{
public:
    Player() : Health(100), position(0.0, 0.0, 0.0) {}

    void move(int dx, int dy, int dz)
    {
        x = x + dx;
        y = y + dy;
        z = z + dz;
    }

    void heal(int hp)
    {
        if (health + hp >= 100)
        {
            health = 100;
        }
        else
        {
            health = health + hp;
        }
    }

    void display()
    {
        cout << "Health: " << health << "\n";
        cout << "Position:\nx: " << x << "\ny: " << y << "\nz: " << z << "\n";
    }
};

int main()
{
    Player player;
    player.health = 90;
    player.display();

    player.heal(10);
    player.move(10, 12, 15);
    player.display();

    return 0;
}
