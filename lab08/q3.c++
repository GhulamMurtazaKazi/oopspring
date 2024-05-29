Suppose you are developing a game engine that involves a variety of game objects, such as
characters, enemies, and items. You want to implement a system to keep track of the position
of these objects in 3D space, as well as their health status.
To accomplish this, you decide to create two base classes: Position and Health. The
Position class will have three member variables to store the x, y, and z coordinates of an
object, and the Health class will have a single member variable to store the health of an object.
You also want to create a Character class that inherits from both Position and Health. This
class will represent characters in the game, and will have additional member variables and
member functions to handle character-specific actions.
Write the code to define the Position, Health, and Character classes, and demonstrate how
to create and use an object of the Character class.

    #include<iostream>
#include<string>
using namespace std;
class position{
protected:
    double x,y,z;
public:
    position(double x,double y,double z):x(x),y(y),z(z) { }
    void showposition() const {
        cout<<"player at ("<<x<<","<<y<<","<<z<<")\n";
    }
    void updateX(int x) {
        this->x=x;
    }
    void updateY(int y) {
        this->y=y;
    }
    void updateZ(int z) {
        this->z=z;
    }
};
class health{
protected:
    int life;
public:
    health(int life):life(life) {}
    void showlife() const {
        cout<<"character health status:"<<life<<endl;
    }
    void setlife(int life) {
        this->life=life;
    }
};
class character:public position,public health{
    string name;
    int damage;
    string superpower;
    string team;
public:
    character(string name,string superpower,string team,int damage,int life,double x,double y,double z):health(life),position(x,y,z) {
        this->name=name;
        this->team=team;
        this->superpower=superpower;
        this->damage=damage;
    }
    void display() const {
        cout<<"character details:\nname:"<<name<<"\nteam:"<<team<<"\nsuperpower:"<<superpower<<endl;
        showposition();
        showlife();
    }
    void setname(string name) { this->name=name; }
    void setdamage(int damage) { this->damage=damage; }
    void setpowers(string superpower) { this->superpower=superpower; }
    void setteam(string team) { this->team=team; }
};
int main() {
   character obj(" "," "," ",-1,-1,0,0,0);
   cout<<"enter the details for your character\n";
   obj.setdamage(0);
   obj.setlife(10);
   string name,superpower,team;
   int damage,life;
    double x,y,z;
    cout<<"enter the name for your character\n";
    getline(cin,name);
    cout<<"enter the team your character is in\n";
    getline(cin,team);
    cout<<"What is your superpower\n";
    getline(cin,superpower);
    obj.setname(name);
    obj.setpowers(superpower);
    obj.setteam(team);
    cout<<"enter the co-ordinates to move your character\n";
    cin>>x>>y>>z;
    obj.updateX(x);
    obj.updateY(y);
    obj.updateZ(z);
    obj.display();
    return 0;
}
