#include "course.hpp"
Course::Course(std::string courseDetails)
{
	std::string::size_type sz;
	std::string token;
	std::string days;
	std::istringstream inputString(courseDetails);
	for(int i=0; getline(inputString,token,' '); ++i)
	{
		switch (i)
		{
			case 0:
				this->coursePrefix=token;
				break;
			case 1:
				this->courseNumber=std::stoi(token,&sz);
				break;
			case 2:
				this->instructor=Instructor(token);
			        break;	
			case 3: 
				this->maxSeats=std::stoi(token,&sz);
				break;
			case 4:
				this->seatsAvailable=std::stoi(token,&sz);
				break;
			case 5:
				days = token;
				break;
			case 6:
				this->meetingTime=ClassTime(days,token);
			        break;	
		}
	}
}
bool Course::MatchesCourseNumberSearch(int courseNumber)
{
	return false;
}
bool Course::MatchesPrefixSearch(std::string searchParameter)
{
	if(searchParameter == this->coursePrefix)
		return true;
	else
		return false;
}
bool Course::Enroll()
{
	if(this->seatsAvailable > 0)
	{
		--this->seatsAvailable;
		return true;
	}
	else
		return false;
}
Instructor Course::getInstructor()
{
	return this->instructor;
}
std::ostream& operator << (std::ostream& ostr, const Course& c)
{
	std::string pluralityOfSeats;
	if(c.seatsAvailable == 1)
		pluralityOfSeats = " seat remaining of ";
	else
		pluralityOfSeats = " seats remaining of ";

	ostr<< c.coursePrefix <<" "<< c.courseNumber<< "\n\t" << c.seatsAvailable <<pluralityOfSeats << c.maxSeats << ".\n\t" <<"Instructor: "<< c.instructor <<".\n\t"<< c.meetingTime; 

	return ostr;
}
