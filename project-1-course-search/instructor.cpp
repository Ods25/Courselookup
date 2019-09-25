#include "instructor.hpp"

Instructor::Instructor(std::string nameData)
{
	std::string token;
	std::istringstream inputString(nameData);
	for(int i = 0; getline(inputString,token,',');++i)
	{
		switch(i)
		{
			case 0:
				this->lastName=token;
				break;
			case 1:
				this->firstName=token;
				break;
			default:
				std::cout << "Eh?";
		}	
	}
}

bool Instructor::MatchesInstructorSearch(std::string searchParameter)
{
	if(searchParameter == this->lastName || searchParameter== this->firstName)
	{
		return true;
	}
	else
		return false;
}


std::ostream& operator << (std::ostream& ost, const Instructor& ir)
{

	ost << ir.firstName << " " << ir.lastName;
	return ost;

}


