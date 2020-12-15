#include "DailyReport.h"


DailyReport::DailyReport()
{
	n = 0;
	lst = NULL;
}


DailyReport::DailyReport(int day, int month, int year,  BuyOp* lst, int n): Date(day, month, year)
{
	setBuyOpLst(lst, n);
}

DailyReport::DailyReport(int day, int month, int year, BuyOp buyOper): Date(day, month, year)
{
	addDailyReport(buyOper);
}


DailyReport::DailyReport(const DailyReport& cpy) :Date(cpy.day, cpy.month, cpy.year)
{
	this->n = cpy.n;
	this->lst = new BuyOp[n];
	for (int i = 0; i < n; i++)
	{
		this->lst[i] = cpy.lst[i];
	}

}


DailyReport::~DailyReport()
{
	delete[] this->lst;
}


void DailyReport::setBuyOpLst(BuyOp* lst, int n)
{
	if (this->lst)
	{
		delete[] this->lst;
	}

	this->n = n;
	this->lst = new BuyOp[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->lst[i] = lst[i];
	}
}


BuyOp& DailyReport::operator[](int index)
{
	return lst[index];
}

DailyReport& DailyReport::operator=(const DailyReport& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (this->lst)
	{
		delete[] this->lst;
	}

	n = obj.n;

	lst = new BuyOp[n];
	for (int i = 0; i < n; i++)
	{
		lst[i] = obj.lst[i];
	}
	return *this;
}


void DailyReport::show()
{
	cout << "Date of purchasing: "<< endl;
	showDate();
	for (int i = 0; i < n; i++)
	{
		lst[i].show();
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	}
}





void DailyReport::addDailyReport(BuyOp oper)
{
	BuyOp* cpy = new BuyOp[n + 1];

	for (int i = 0; i < n; i++)
	{
		*(cpy + i) = *(lst + i);
	}
	*(cpy + n) = oper;
	this->n++;
	delete[] lst;
	this->lst = cpy;
}

void DailyReport::setReportDate(int day, int month, int year)
{
	setDate(day, month, year);
}
