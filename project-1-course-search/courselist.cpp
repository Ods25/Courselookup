#include "courselist.hpp"
CourseList::CourseList(std::string filename)
{
	this->courselist.open(filename); //open fstream object at filename path
	std::string line; //declare a temp string as 'line', for storing string of each line for input into class object
	for (int i=0; getline (this->courselist,line);++i )
	{
		this->numClasses = i; //obtain number of lines to get number of classes, and thus number of class boolean and class objects
	}
	this->courseArray= new Course[numClasses+1];	 //courseArray object pointer is declared as the pointer to the first of a number (numClasses) objects + 1 as a buffer.
	this->enrolledClasses = new bool[numClasses+1] {false}; //same with enrolledCLasses, all classes are by default not enrolled, thus all values are false.
	//close and open to reset file cursor position
	this->courselist.close();
	this->courselist.open(filename);
	for (int i=0; getline (this->courselist,line);++i ) 
	{	
		this->courseArray[i]=Course(line); //each course object is assigned input from line, and constructed using the constructor.
		this->printedCourse <<"ID "<<i<<": "<< courseArray[i] <<"\n"; //printedCourse output string stream object is populated with default values for each class in the list.
	}
}

bool CourseList::Enroll(int choice)
{
	bool test = false;//test is set to false by default
	if(this->enrolledClasses[choice]==false) //if the student is not currently enrolled in a class
		test = this->courseArray[choice].Enroll(); //Enroll checks if a seat is available. if it is, it minuses one from that seat.
	if(test == true) //if that check went through, we can go and enroll the student.
	{

	        this->enrolledClasses[choice]= true; //student is now enrolled, that class's corresponding boolean value for the ID = true
		return test;
	}
	else
		return test;
}

std::string CourseList::GetMyCourses()
{
	std::ostringstream myCourse;
	bool classFound; 
	for(int i =0; i<=this->numClasses;++i) //for i until the number of scanned classes
	{
		if(this->enrolledClasses[i] == true) //if an enrolled class is found at element i
		{
			classFound = true; //class is found, set bool to true
			myCourse<<"ID "<<i<<": "<<courseArray[i]<<"\n"; //feeding course string into stringstream object
		}
		if(i==this->numClasses && classFound==true) //if we are at the last scanned class and we have found at least one class	
			return myCourse.str(); //then return a string 
	}
	return "You are not enrolled in any courses\n";
}


std::string CourseList::GetAllCourses()
{
	this->printedCourse.str(""); //printedCourse object is cleared
	this->printedCourse.clear(); //printedCourse object is DOUBLY cleared to reset flags.
	for (int i=0; i<=this->numClasses;++i ) //for i until numClasses
	{
		this->printedCourse <<"ID "<<i<<": "<< courseArray[i] <<"\n"; //using the insertion operator, apply ID + num + course text from the course insertion stream operator.
	}
	return this->printedCourse.str(); // return the string form of the ostringstream after population has happened.
}
std::string CourseList::InstructorSearch(std::string searchParam)
{	
	std::ostringstream printedCourse;
	for(int i=0; i<=this->numClasses;++i)//for i until num of scanned classes
	{

		Instructor instruc = this->courseArray[i].getInstructor(); 	
		if((instruc.MatchesInstructorSearch(searchParam)==true)) //if instructor search, in instructor object, at specific course ID == true
		{
			printedCourse<<"ID "<<i<<": "<<courseArray[i]<<"\n"; // push to stringstream object
		}
		
	}
	return printedCourse.str();
}


std::string CourseList::PrefixSearch(std::string searchParam)
{
	std::ostringstream printedCourse;
	for(int i=0; i<=this->numClasses;++i)
	{
		if(this->courseArray[i].MatchesPrefixSearch(searchParam) == true)
		{
			printedCourse<<"ID "<<i<<": "<<courseArray[i]<<"\n";
		}
	}
	return printedCourse.str();	
}

// The following is previous code that worked when Course was made a friend of CourseList
/*
std::string CourseList::InstructorSearch(std::string searchParam)
{		
	std::ostringstream printedCourse;
	for(int i=0; i<=this->numClasses;++i)//for i until num of scanned classes
	{

		if((this->courseArray[i].instructor.MatchesInstructorSearch(searchParam)==true)) //if instructor search, in instructor object, at specific course ID == true
		{
			printedCourse<<"ID "<<i<<": "<<courseArray[i]<<"\n"; // push to stringstream object
		}
		
	}
	return printedCourse.str();
}


std::string CourseList::PrefixSearch(std::string searchParam)
{
	std::ostringstream printedCourse;
	for(int i=0; i<=this->numClasses;++i)
	{
		if(this->courseArray[i].MatchesPrefixSearch(searchParam) == true)
		{
			printedCourse<<"ID "<<i<<": "<<courseArray[i]<<"\n";
		}
	}
	return printedCourse.str();	
}

*/
CourseList::~CourseList()
{
	delete[] courseArray;
	delete[] enrolledClasses;
}
