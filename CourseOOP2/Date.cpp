#include "Date.h"
using namespace std;

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& cpy)
{
	day = cpy.day;
	month = cpy.month;
	year = cpy.year;
}

Date::~Date()
{
}

void Date::setDay(int day)
{
	if (day < 1 || day > 31)
	{
		cout << " Wrong date. Set default value 1 " << endl;
		this->day = 1;
	}
	else
	{
		this->day = day;
	}
}

void Date::setMonth(int month)
{
	if (month < 0 || month > 12)
	{
		this->month = 1;
	}
	else
	{
		this->month = month;
	}
}

void Date::setYear(int year)
{
	if (year < 1900 || year > 2020)
	{
		this->year = 1900;
	}
	else
	{
		this->year = year;
	}
}

void Date::show()
{
	std::cout << " Day: " << getDay() << std::endl;
	std::cout << " Month: " << getMonth() << std::endl;
	std::cout << " Year: " << getYear() << std::endl;
}

void Date::setDate(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

Date& Date::operator=(const Date& obj)
{
	day = obj.day;
	month = obj.month;
	year = obj.year;
	return*this;
}

void Date::showDate()
{
	std::cout << day << "." << month << "." << year;
}
