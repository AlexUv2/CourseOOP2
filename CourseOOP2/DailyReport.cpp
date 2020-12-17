#include "DailyReport.h"

DailyReport::DailyReport()
{
	this->n = 0;
	this->lst = NULL;
}


DailyReport::DailyReport(int day, int month, int year,  BuyOp* lst, int n): Date(day, month, year)
{
	this->lst = NULL;
	setBuyOpLst(lst, n);
}

DailyReport::DailyReport(int day, int month, int year, BuyOp buyOper): Date(day, month, year)
{
	this->lst = NULL;
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

	day = obj.day;
	month = obj.month;
	year = obj.year;

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
	BuyOp* cpy = new BuyOp[this->n + 1];

	for (int i = 0; i < n; i++)
	{
		*(cpy + i) = *(lst + i);
	}
	*(cpy + n) = oper;
	this->n++;
	if (lst)
	{
		delete[] lst;
	}
	this->lst = cpy;
}

void DailyReport::setReportDate(int day, int month, int year)
{
	setDate(day, month, year);
}

int DailyReport::getN()
{
	return this->n;
}

void DailyReport::writeDayPer(ostream& write)
{
	write.write(reinterpret_cast<char*>(&this->n), sizeof(int));
	write.write(reinterpret_cast<char*>(&this->day), sizeof(int));
	write.write(reinterpret_cast<char*>(&this->month), sizeof(int));
	write.write(reinterpret_cast<char*>(&this->year), sizeof(int));

	for (int  i = 0; i < this->n; i++)
	{
		lst[i].writeBuyOp(write);
	}
}

void DailyReport::readDayRep(istream& read)
{
	read.read(reinterpret_cast<char*>(&this->n), sizeof(int));
	read.read(reinterpret_cast<char*>(&this->day), sizeof(int));
	read.read(reinterpret_cast<char*>(&this->month), sizeof(int));
	read.read(reinterpret_cast<char*>(&this->year), sizeof(int));

	if (this->lst)
	{
		delete[]lst;
	}
	lst = new BuyOp[this->n];

	for (int i = 0; i < this->n; i++)
	{
		lst[i].readBuyOp(read);
	}

}



