#include<iostream>

using namespace std;


class school
{

	private:
		int student_id;
		char first_name[15];
		char last_name[15];
	
	public:
		// Default Constructor
		school();

		// constructor when student id is provided
		school(int student_id);					
			
		void display();

}; 

