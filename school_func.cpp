#include <iostream>
#include <fstream>
#include <iomanip>
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
	
	cout<<endl<<"**"<<setw(15)<<s1.student_id<<setw(22)<<s1.first_name<<setw(18)<<s1.last_name<<setw(25)<<s1.guardian_cell_no<<"                   **";
}

void append_student_data()
{


	ofstream file1;
	file1.open("Record.txt",ios::app);
	school student;
	student.input_student_data();
	file1.write((char *)(&student), sizeof(student));
	cout<<"\nD1ata Apended Successfully\n";
	file1.close();
}

void display_all_student_data()
{
	cout<<endl<<endl;

	cout<<"\n\n*******************************************************************************************************";
	cout<<"\n**        Student ID"<<"          First Name"<<"          Last Name"<<"          Guardian cell No.               **"<<endl;
	cout<<"*******************************************************************************************************";
	ifstream file1;
	school s1;
	file1.open("Record.txt",ios::in);
	if(file1.is_open())
	{
		while(1)
		{

			file1.read( (char *) (&s1), sizeof(school));
			if(file1.eof())
			{
				break;
			}
			cout<<"\n**                                                                                                   **";
			s1.display_student_data(s1);
			cout<<"\n**                                                                                                   **";
		}

		file1.close();		
	}
	else
	{
		cout<<"\nFile does not exist\n";
	}
	cout<<"\n*******************************************************************************************************";
}

int display_options()
{
	int choice;
	cout<<"\n\n*******************************************************************************************************";
	cout<<"\n*********************************   Welcome  To Student Registration System   *************************";
	cout<<"\n*******************************************************************************************************";
	cout<<"\n**                                                                                                   **";
	cout<<"\n**                                                                                                   **";
	cout<<"\n**	                        1. Add a Student to Database                                         **";
	cout<<"\n**                                                                                                   **";
	cout<<"\n**	                        2. Delete a student from Database                                    **";
	cout<<"\n**                                                                                                   **";
	cout<<"\n**	                        3. Modify student Information                                        **";
	cout<<"\n**                                                                                                   **";
	cout<<"\n**	                        4. Display All students Information                                  **";
	cout<<"\n**                                                                                                   **";
	cout<<"\n**	                        5. Exit From this Software                                           **";
	cout<<"\n**                                                                                                   **";
	cout<<"\n*******************************************************************************************************";
	cout<<"\n**                                                                                                   **";
	cout<<"\n**     Enter Your Choice  : ";cin>>choice;
	cout<<"**                                                                                                   **";
	cout<<"\n**                                                                                                   **";
	cout<<"\n*******************************************************************************************************\n\n";
	return choice;
}	


void quit_software()
{
	cout<<"\n***\n****************************************************************************************************";
	cout<<"\n**                                Have A Good Day !                                                  **";
	cout<<"\n*******************************************************************************************************";
}
