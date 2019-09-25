#ifndef COURSELIST_HPP
#define COURSELIST_HPP
#include <fstream>
#include <vector> //grt rid of
#include <new> //possibly get rid of
#include "course.hpp"
class CourseList
{
	private:
		std::string fn;
		std::ostringstream printedCourse;
		std::ifstream courselist;
		Course *courseArray;
		int numClasses;
		bool *enrolledClasses;
	public:
		CourseList(std::string filename);
		bool Enroll(int choice);
		~CourseList();
		std::string InstructorSearch(std::string searchParam);
		std::string PrefixSearch(std::string searchParam);
		std::string GetMyCourses();
		std::string GetAllCourses();
};
#endif
