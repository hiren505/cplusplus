#include <iostream>
//#include "school.h"
#include "school_func.cpp"

int main()
{
	int choice;
	
	do
	{
		choice = display_options();
		switch(choice)
		{
			case 1: append_student_data();
					  break;
			case 2: cout<<"work in progress";
					  break;
			case 3: cout<<"work in progress";
					  break;
			case 4: display_all_student_data();
					  break;
			case 5: quit_software;
					  break;
			default : cout<<"\nPlease enter a Valid Option\n" ;
					  break;
		}
	}while(choice != 5);
}
