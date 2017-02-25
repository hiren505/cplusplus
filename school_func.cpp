#include <iostream>
#include <fstream>
#include "school.h"

using namespace std;




void school::input_student_data()
{
	cout<<"\nEnter Student ID: ";
	cin>>student_id;
	cin.get();
	cout<<"\nEnter your First name : ";
	cin.getline(first_name,15);
	cout<<"\nEnter your last name  : ";
	cin.getline(last_name,15);
	cout<<"\nEnter Guardian Cell no. : ";
	cin>>guardian_cell_no;
}



void school::display_student_data(school s1)
{
	
	cout<<"		"<<s1.student_id<<"		"<<s1.first_name<<"		"<<s1.last_name<<"		"<<s1.guardian_cell_no<<endl;
}

void append_student_data()
{


	ofstream file1;
	file1.open("Record.txt",ios::app);
	school student;
	student.input_student_data();
	file1.write((char *)(&student), sizeof(student));
	cout<<"\nD1ata Apended Successfully/n";
	file1.close();
}

void display_all_student_data()
{
	cout<<endl<<endl;
	
	cout<<"		Student ID"<<"	First Name"<<"	Last Name"<<"	Guardian cell No."<<endl<<endl;


	ifstream file1;
	school s1;
	file1.open("Record.txt",ios::in);
	while(1)
	{

		file1.read( (char *) (&s1), sizeof(school));
		if(file1.eof())
		{
			break;
		}
		s1.display_student_data(s1);
	}

	file1.close();
}
