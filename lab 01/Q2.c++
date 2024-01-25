Q2: Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F

#include<iostream>
using namespace std;
int main () {
	int students,i=0,j,total;
	cout<<"enter no of students:";
	cin>>students;
	int**sheet=new int*[students];
	for(int i = 0; i < students; i++)
		sheet[i] = new int[3];
		i=0;
	while (i<students) {
		j=0;
		total=0;
		cout<<"enter the marks for student "<<i+1<<endl;
		while (j<3) {
			cin>>sheet[i][j];
			total+=sheet[i][j];
			++j;
		}
		cout<<"total marks for student "<<i+1<<" are:"<<total<<endl;
		cout<<"average for student "<<i+1<<" is "<<total/3<<endl;
		if (total>=90) cout<<"your grade:A\n";
		else if (total>=80) cout<<"your grade:B\n";
			else if (total>=70) cout<<"your grade:C\n";
				else if (total>=60) cout<<"your grade:D\n";
				else cout<<"your grade is f\n";
		++i;
	}
	return 0;
}
