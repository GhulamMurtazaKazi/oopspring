Suppose you are developing a program for a school that needs to keep track of its students
and teachers. Both students and teachers have a name and an age, but they have different
properties beyond that. Students have a student ID number and a grade level, while
teachers have a subject they teach and a room number.
You want to create a set of classes to represent these objects, using hybrid inheritance.
Specifically, you want to create a base class called Person that has member variables for the
name and age, a derived class called Student that inherits from Person and adds member
variables for the student ID and grade level, and a derived class called Teacher that
inherits from Person and adds member variables for the subject and room number.

You also want to create a derived class called GraduateStudent that inherits from both
Student and Teacher, representing a student who is also a teacher's assistant.
Write the code to define the Person, Student, Teacher, and GraduateStudent classes, and
demonstrate how to create and use an object of the GraduateStudent class.

    #include<iostream>
using namespace std;
class person{
protected:
string name;
int age;
public:
person(string name,int age):name(name),age(age) {}
void display() const {
    cout<<"name:"<<name<<"\nage:"<<age<<endl;
}
};
class student:virtual person{
    protected:
    int id;
    double grade;
    public:
    student(string name,int age,int id,double grade):person(name,age),id(id),grade(grade) {}
    void display() const {
        cout<<"student id:"<<id<<"\ngrade:"<<grade<<endl;
    }
};
class teacher:virtual public person{
    protected:
    string course;
    int room;
    public:
    teacher(string name,int age,string course,int room):person(name,age),course(course),room(room) {}
    void display() const {
    cout<<"course:"<<course<<"\nroom no:"<<room<<endl;
    }
};
class TA:public student,public teacher{
    string graduate_year;
    public:
    TA(string name,int age,int id,double grade,string course,int room,string graduate_year):person(name,age),student(name,age,id,grade),teacher(name,age,course,room),graduate_year(graduate_year) { } 
    void display() const {
        cout<<"Graduated:"<<graduate_year<<endl;
    }
};
int main() {
    TA obj("chahet fateh ali khan",72,1002,4.0,"badho badhi",42,"9-11-2001");
    obj.person::display();
    obj.student::display();
    obj.teacher::display();
    obj.display();
    return 0;
}
