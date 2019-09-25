#ifndef COURSE_HPP
#define COURSE_HPP

#include "instructor.hpp"
#include "classtime.hpp"
class Course
{
	private:
		//friend class CourseList; 
		/*
		 * There must be a deviation from the UML in 
		 * regards to the implementation of the 
		 * 'InstructorSearch' Function. 
		 * The options were either
		 * 1. One line: 'friend class CourseList'
		 * 2. Write a Instructor object public function that runs 
		 * InstructorSearch within courselist, as well as a getter for
		 * instructor returning an instructor object within Course.
		 * 
		 */
		std::string coursePrefix;
		int courseNumber;
		Instructor instructor;
		int maxSeats;
		int seatsAvailable;
		ClassTime meetingTime;
	public:
		Course(std::string courseDetails= "CS 0 Bar,Foo 0 0 1,2,3 1:00-1:15");
		bool MatchesCourseNumberSearch(int courseNumber);
		bool MatchesPrefixSearch(std:: string);
		bool Enroll();
		Instructor getInstructor(); //This is the previously mentioned getInstructor() function, which is a deviation from the UML. This is the most data-safe option, is only a getter, and is only a return statement.
		friend std::ostream& operator << (std::ostream& ostr, const Course& c);
};
#endif
