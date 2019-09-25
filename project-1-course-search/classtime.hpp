#ifndef CLASSTIME_HPP
#define CLASSTIME_HPP

#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>

class ClassTime
{
	private:
		int daysOfTheWeek[7];
		int times[4];
		void SetDaysOfTheWeek (std::string days);
		void SetTime (std::string times);
		enum timeParts { START_HOUR, START_MINUTE, END_HOUR, END_MINUTE };

	public:
		ClassTime (std::string days = "", std::string times = "");

		friend std::ostream& operator<<(std::ostream& os, const ClassTime& ct);
};

#endif
