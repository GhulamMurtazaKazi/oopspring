Consider a School Management System. You are required to create two classes,
Student and Course. Each student can enroll in multiple courses. The Course class
should have the following properties: course code (string), course name (string), and
course credit hours (integer). The Student class should have the following properties:
student ID (string), student name (string), and a list of enrolled courses (an array of
Course objects).

The Student class should have the following member functions:
A constructor that initializes the student ID and name.

A function named "enroll" that takes a Course object as input and adds it to the list
of enrolled courses for the student.
A function named "drop" that takes a Course object as input and removes it from the
list of enrolled courses for the student.
A function named "getTotalCreditHours" that returns the total number of credit hours
for all courses the student is currently enrolled in.
A function named "printEnrolledCourses" that prints out the course code, name, and
credit hours for all courses the student is currently enrolled in.

#include<iostream>
#include<vector>
using namespace std;

class course{
    string code;
    string name;
    int c_hr;
public:
    void setcode(string code) {
        this->code=code;
    }
    void setname(string name) {
        this->name=name;
    }
    void setcredits(int c_hr) {
        this->c_hr=c_hr;
    }
    string getcode() {
        return code;
    }
    string getname() {
        return name;
    }
    int getcredits() {
        return c_hr;
    }
};

class student{
    string ID;
    string name;
    vector<course>list;
public:
	student() {
	}
    student(string ID,string name):ID(ID),name(name) { }
    void enroll(string code,string name,int c_hr) {
        course newCourse;
        newCourse.setcode(code);
        newCourse.setname(name);
        newCourse.setcredits(c_hr);
        list.push_back(newCourse);
    }
    void drop(string name) {
    	int i=0;
    	while (i<list.size()){
    		if (list[i].getname()==name) list.erase(list.begin()+i);
    		++i;
		}
	}
	int totalcredits() {
		int i=0,count=0;
		while (i<list.size()) {
			count+=list[i].getcredits();
			++i;
					}
					return count;
	}
	void print(){
		int i=0;
		while (i<list.size()){
			cout<<"course  code="<<list[i].getcode()<<"\nname="<<list[i].getname()<<"\ncredit hours="<<list[i].getcredits()<<endl;
			++i;
		}
	}
};

int main() {
	int n,i=0,j;
	cout<<"enter number of students\n";
	cin>>n;
	student array[n];
	while (i<n) {
		cout<<"enter 1 to add student details\nenter 2 to add course\nenter 3 to drop a course\nenter 4 to display enrolled courses\nenter 5 to move to the next student\n";
		cin>>j;
		if(j==1) {
			string ID,name;
			cout<<"enter the id and name of the student respectively\n";
			cin>>ID>>name;
			array[i]=student(ID,name);
		}
		if (j==2) {
			string code,name;
			int credits;
			cout<<"enter the code,name and credit hours for the course\n";
			cin>>code>>name>>credits;
			array[i].enroll(code,name,credits);
		}
		if(j==3) {
			string name;
			cout<<"enter the name of the course\n";
			cin>>name;
			array[i].drop(name);
		}
		if(j==4) {
			array[i].print();
		}
		if (j==5) {
			++i;
			continue;
		}
	}
    return 0;
}
