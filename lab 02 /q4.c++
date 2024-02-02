Your task is to implement a basic Student Registration System in C++. Define two
structures, Register and Student, where Register includes attributes courseId and
courseName, and Student inherits from Register while having additional attributes
such as studentId, firstName, lastName, cellNo, and email. Your objective is to
create an array of Student structures to store data for five students. Write a C++
program that accomplishes the following tasks:
1. Implement the Register and Student structures.
2. Inherit the Register structure in the Student structure.
3. Create an array of Student structures to store data for 5 students.
4. Take input for each student, including their courseId, courseName,
studentId, firstName, lastName, cellNo, and email.
5. Display the information for all 5 students.

#include<iostream>
using namespace std;
struct Register {
	string course_id;
	string course_name;
};
struct student {
	string studentId;
	string first_name;
	string last_name;
	long long int cellno;
	string email;
	Register course;
};
int main () {
	student details[5];
	int i=0;
	while (i<5) {
		cout<<"enter the details for student "<<i+1<<endl;
		cout<<"enter the student ID:";
		cin>>details[i].studentId;
		cout<<"enter the first name:";
		cin>>details[i].first_name;
		cout<<"enter the last name:";
		cin>>details[i].last_name;
		cout<<"enter the cell number:";
		cin>>details[i].cellno;
		cout<<"enter the email:";
		cin>>details[i].email;
		cout<<"enter the course id:";
		cin>>details[i].course.course_id;
		cout<<"enter the course name:";
		cin>>details[i].course.course_name;
		++i;
		cout<<endl;
	}
		i=0;
		while (i<5) {
			cout<<"details for student "<<i+1<<endl;
			cout<<"student id="<<details[i].studentId<<endl;
				cout<<"first name="<<details[i].first_name<<endl;
					cout<<"last name="<<details[i].last_name<<endl;
						cout<<"cell number="<<details[i].cellno<<endl;
					cout<<"email="<<details[i].email<<endl;
						cout<<"course id="<<details[i].course.course_id<<endl;
					cout<<"course name="<<details[i].course.course_name<<endl;
					++i;
					cout<<endl;
		}
	return 0;
}  
