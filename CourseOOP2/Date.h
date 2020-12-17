#pragma once
#include <iostream>
#ifndef DATE_H_
#define DATE_H_
#include <fstream>
#include <ios>
using namespace std;

class Date
{
protected:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& cpy);
	~Date();


	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	virtual void show();

	void setDate(int day, int month, int year);
	void showDate();
	int getDay();
	int getMonth();
	int getYear();

	
	void writeDate(ostream& write);
	void readDate(istream& read);


	Date& operator=(const Date& obj);
};
#endif