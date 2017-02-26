#include <iostream>
#include <fstream>
#include <iomanip>
#include "school.h"

using namespace std;



/* 
 	This is a member function of school class. This function basically 
	takes the parameters from the keyboard and stores in the school object
*/ 
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

/*
	This is a member function of class school. This function displays
	the privet members of the class school
*/
void school::display_student_data(school s1)
{
	
	cout<<endl<<"**"<<setw(15)<<s1.student_id<<setw(22)<<s1.first_name<<setw(18)<<s1.last_name<<setw(25)<<s1.guardian_cell_no<<"                   **";
}

/*
	This is a member function of school. This function returns the student id
	of the class object that it receives.
*/
int school::return_student_id(school s1)
{
	int id_to_return = s1.student_id;
	return id_to_return;
}

/*
	This function calls the input_data member function of school and
	append the data int the file.
*/
void append_student_data()
{


	ofstream file1;
	file1.open("Record.txt",ios::app);
	school student;
	student.input_student_data();
	file1.write((char *)(&student), sizeof(student));
	cout<<"\nData Apended Successfully\n";
	file1.close();
}

/*
	This function displays the list of Students stored
	in the File in a proper format.
*/
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

			file1.read( (char *) (&s1), sizeof(s1));
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

/*
	This function displays the wecome screen of the software
	This functon contains the options that can be performed when
	selected. 
*/
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

/*
	This function asks the user to enter a ID that he want
	to delete. And then delets the particular ID.
*/
void delete_student()
{

	int id_to_delete;
	int present_status = 0;

	cout<<"\n*******************************************************************************************************";
	cout<<"\n**                                                                                                   **";
	cout<<"\n**                                Enter the ID You want to delete : ";
	cin>>id_to_delete;
	cout<<"*******************************************************************************************************\n\n";

	school s1;

	ifstream filetoread;
	ofstream filetowrite;

	filetoread.open("Record.txt");
	filetowrite.open("temp.txt");

	while(1)
	{
		filetoread.read((char *)(&s1), sizeof(s1));
		if(filetoread.eof())
		{
			break;
		}
		if(s1.return_student_id(s1) != id_to_delete)
		{
			filetowrite.write((char *)(&s1), sizeof(s1));
		}
		else
		{
			present_status = 1;
		}
	}

	filetoread.close();
	filetowrite.close();


	remove("Record.txt");
	rename("temp.txt","Record.txt");

	if(present_status == 1)
	{
		cout<<"\n\n";
		cout<<"\n*******************************************************************************************************";
		cout<<"\n**                                                                                                   **";
		cout<<"\n**                    Student ID No : "<<id_to_delete<<" deleted Successfully                                         **";
		cout<<"\n**                                                                                                   **";
		cout<<"\n*******************************************************************************************************";
	}
	else
	{
		cout<<"\n\n";
		cout<<"\n*******************************************************************************************************";
		cout<<"\n**                                                                                                   **";
		cout<<"\n**              Sorry the Student Id you mentioned was not found in the file !!!!!                   **";
		cout<<"\n**                                                                                                   **";
		cout<<"\n*******************************************************************************************************";
	}
}

/*
	This function displays the Good day message
*/
void quit_software()
{
	cout<<"\n*******************************************************************************************************";
	cout<<"\n**                                Have A Good Day !                                                  **";
	cout<<"\n*******************************************************************************************************\n\n\n\n";
}
