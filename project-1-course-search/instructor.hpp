#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP
#include <string>
#include<sstream>
#include<iostream>
#include<iomanip>

class Instructor
{
	private:
		
		std::string firstName;
		std::string lastName;
	public:
		Instructor(std::string nameData = "George,Crazy");
		bool MatchesInstructorSearch(std::string);
		friend std::ostream& operator << (std::ostream& ost, const Instructor& ir);

};



#endif
