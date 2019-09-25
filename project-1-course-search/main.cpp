#include "courselist.hpp"
std::string findValidFile();
void search(CourseList &courseList, std::string boxHoriz);
void enroll(CourseList &courseList);
int main()
{
	std::string boxHoriz="─────────────────────────────────────────────────────"; 
	CourseList courseList(findValidFile()); //create a courseList object with an argument of a function designed to get a valid file
	std::cout << "Hello! Welcome to fake Banner!" << std::endl;
        std::cout<< "Below is a list of all available courses" << std::endl;
	std::string inp;//input	
	std::cout << courseList.GetAllCourses();//list all courses first, though this could be gotten rid of in favor of having the user simply press R. Personal preferences
	do
	{
		std::cout<< boxHoriz << std::endl; //formatting
		std::cout<<"To search for a course, press 'S'." << std::endl;
		std::cout<<"To Enroll, press 'E'." <<std::endl; 
		std::cout<<"To view your current enrollments, press 'V'."<<std::endl; 
		std::cout<<"To view all available courses again, press 'R'."<<std::endl;
		std::cout<<"Any other key press will exit this application:";
		std::cin >> inp;
		if(inp == "S") //search
			search(courseList, boxHoriz); //run search, passing courseList object by reference
		if(inp == "E") //enroll
			enroll(courseList); //run enroll, passing courseList by reference
		if(inp == "V") //view enrolled courses
			std::cout << courseList.GetMyCourses();
		if(inp == "R") //view current enrollments
			std::cout << courseList.GetAllCourses();
	}
	while(inp == "S" || inp == "E" || inp == "V" || inp == "R");
}
void enroll(CourseList &courseList)
{

	int cpm; // cpm is short for 'choice parameter', and is an input variable.
	std::cout << "	Enter the ID of the course you want to enroll in:"; 
	std::cin >> cpm;
	bool enrollTest = courseList.Enroll(cpm); //the function returns a bool, if true, the individual was enrolled, if false, the individual was not due to no seats being available or an invalid ID being given.
	//If the test file didn't demand a bool, an integer could have been used instead, denoting perhaps error codes, 0 could have been for 'enrolled', 1 for 'no seats left', 2 for 'invalid id'
	if(enrollTest == true)
		std::cout << "Enrolled in course ID "<< cpm <<std::endl;
	else
		std::cout << "Not enrolled: No seats left, or Invalid ID"<< std::endl;
}

void search(CourseList &courseList, std::string boxHoriz)
{

	std::string spm; // search param
	std::cout << "	Enter 'P' to search by course prefix, or 'N' to search by instructor name" <<std::endl << "	'N' is the default: "; 
	std::cin >> spm;
	if(spm == "P")
	{	
		std::cout <<"        Enter the course prefix to search for:";
		std::cin >> spm;
		std::cout << courseList.PrefixSearch(spm);
		std::cout << boxHoriz<<std::endl;
	}
	else if(spm=="N")
	{
		std::cout<<"         Enter the Instructor name to search for:";
		std::cin >>spm;
		std::cout<< courseList.InstructorSearch(spm);
		std::cout << boxHoriz << std::endl;
	}
	else    
	{
		std::cout<<courseList.InstructorSearch(spm);
		std::cout << boxHoriz << std::endl;
	}
}
std::string findValidFile()
{
	std::string fn; //filename string
	std::ifstream ifs;
	while(ifs.is_open()==false)
	{
		std::cout << "Please Enter a valid file name: "<<std::endl;
		std::cin >> fn;
		ifs.open(fn);
	}
	std::cout << "File Accepted"<<std::endl;
	ifs.close();// after finding a valid file, we can get rid of the ifs object 	
	return fn;
}
