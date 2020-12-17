#include "DailyReport.h"
#include <iomanip>

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

void DailyReport::Tab(/*double* arr, double dx, int numOfElem, double val*/)
{
	int tableLen = 5;
	line1(201, 205, 203, 187, 7, 13);
	cout << char(186) <<"  Client ID  " << char(186) << "\t   Date\t    " << char(186) << " Product name" << char(186)
		<< "Product Price" << char(186) << " Sale Percent" << char(186) << "   All Sum   " << char(186) << "Sum with sale" << char(186) << endl;

	line(204, 205, 206, 185, 7, 13);
	for (int i = 0; i < getN(); i++)
	{
		cout << char(186) << setw(7) << lst[i].getID() << setw(7) << char(186) << " " << lst[i].getDay() << "." << lst[i].getDay() << "." << lst[i].getYear() << setw(3) << char(186)
			<< setw(14) << char(186) << setw(14) << char(186) << setw(14) << char(186) << setw(8)  << lst[i].getSumOfProds() << setw(6) << char(186) <<setw(3)<< " " <<  lst[i].getSumWithSale() << "\t  " << char(186) << endl;
		line(204, 205, 202, 185, 7, 13);
		for (int j = 0; j < lst[i].getN(); j++)
		{
			cout << char(186)<< setw(28)<< char(186) << setw(3) << " " << lst[i][j].getProdName() << "\t" << setw(3) <<
				char(186) << setw(5) << " " << lst[i][j].getProdPrice() << "\t" << char(186) << setw(6) << " " << lst[i].getSalePerc() << setw(6) << " " << char(186) 
				<< setw(28) << char(186) << endl;
		}

		if (i != getN() - 1)
		{
			line(204, 205, 203, 185, 7, 13);
		}
	}
	line1(200, 205, 202, 188, 1, 97);
}

void DailyReport::line(char start, char middle, char cross, char end, int count, int len)
{
	cout << start;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << middle;
		}

		if (i > 0 && i < count - 2)
		{
			cout << char(206);
		}
		else
		{
			
			cout << cross;
		}
	}
	for (int j = 0; j < len; j++)
	{
		cout << middle;
	}
	cout << end << endl;
}


void DailyReport::line1(char start, char middle, char cross, char end, int count, int len)
{
	cout << start;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << middle;
		}
		cout << cross;

	}
	for (int j = 0; j < len; j++)
	{
		cout << middle;
	}
	cout << end << endl;
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



