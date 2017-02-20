#include <iostream>
#include "school.h"

using namespace std;


school::school()
{
	cout<<"\nDefault constructor called\n";
}

school::school(int student_id_passed)
{
	student_id = student_id_passed;
	cout<<"\nStudent ID: "<<student_id<<endl;
	cout<<"\nEnter your First name : ";
	cin.getline(first_name,15);
	cout<<"\nEnter your last name  : ";
	cin.getline(last_name,15);
}

void school::display()
{
	cout<<"\n\nStudent ID: "<<student_id;
	cout<<"\nStudent First Name : "<<first_name;
	cout<<"\nStudent Last Name  : "<<last_name<<endl;
}


