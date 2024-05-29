Suppose you are developing a game that has different types of characters. You have a base
class called "Character" which has attributes like health and damage. Now, you want to
create two derived classes - "Enemy" and "Player" - which inherit from the "Character"
class. Further, you want to create another class called "Wizard" which inherits from the
"Player" class and has additional attributes like magic power and spells.
a) Define the "Character" class with the following attributes:
 health (integer)
 damage (integer)
 Define the constructor for the "Character" class which initializes the attributes.
 Define a function called "display" inside the "Character" class which displays
the details of the character.

b) Create a derived class called "Enemy" which inherits from the "Character" class.
 Define the constructor for the "Enemy" class which initializes the attributes of the
base class.
 Define a function called "display" inside the "Enemy" class which displays the
details of the enemy.

c) Create a derived class called "Player" which inherits from the "Character" class.
 Define the constructor for the "Player" class which initializes the attributes of
the base class.
 Define a function called "display" inside the "Player" class which displays the
details of the player.

d) Create another derived class called "Wizard" which inherits from the "Player" class
and has the following additional attributes:
 magic power (integer)
 spells (string)
 Define the constructor for the "Wizard" class which initializes the attributes of
the base classes as well as the derived class.
 Define a function called "display" inside the "Wizard" class which displays the
details of the wizard, including the additional attributes.

In the main function, create an object of the "Wizard" class and display its details.

#include<iostream>
using namespace std;
class character{
    protected:
    int health,damage;
    public:
    character(int health,int damage):health(health),damage(damage) {}
    void display() const {
        cout<<"health:"<<health<<"\ndamage:"<<damage<<endl;
    }
};
class player:public character{
public:
player(int health,int damage):character(health,damage) {}
void display() const {
  cout<<"health:"<<health<<"\ndamage:"<<damage<<endl;  
}
};
class enemy:public character{
    public:
    enemy(int health,int damage):character(health,damage) {}
    void display() const {
  cout<<"health:"<<health<<"\ndamage:"<<damage<<endl;  
}
};
class wizard:public player{
int magic_powers;
string spells;
public:
wizard(int magic_powers,string spells,int health,int damage):player(health,damage),magic_powers(magic_powers),spells(spells) {}
void display() const {
  cout<<"health:"<<health<<"\ndamage:"<<damage<<"\nmagic power:"<<magic_powers<<"\nspells:"<<spells<<endl;  
}
};
int main() {
    //health and damage will be on the scale of 1-10
    wizard dr_strange(4,"leviosa",2,5);
    dr_strange.display();
    return 0;
}
