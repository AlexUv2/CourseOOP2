#pragma once
#include "Date.h"
#include "BuyOp.h"
#include <iostream>

//template <class Type, class T>
//Type averProdNum(DailyReport D)
//{
//	Type sum = 0;
//	Type numOfProds;
//	for (int i = 0; i < D.getN(); i++)
//	{
//		for (int j = 0; j < D.lst[i].getN(); j++)
//		{
//			sum += D.lst[i].prLst[j].getProdPrice();
//			numOfProds++;
//		}
//	}
//
//	return sum / numOfProds;
//}

using namespace std;
#ifndef DAILYREP_H_
#define DAILYREP_H_

class DailyReport :public Date
{

	BuyOp* lst;
	int n = 0;
public:

	DailyReport();
	DailyReport(int day, int month, int year, BuyOp* lst, int n);
	DailyReport(int day, int month, int year, BuyOp buyOper);
	DailyReport(const DailyReport& cpy);
	~DailyReport();




	void setBuyOpLst(BuyOp*lst, int n);
	void show();
	void addDailyReport(BuyOp Oper);
	void setReportDate(int day, int month, int year);
	int getN();


	void writeDayPer(ostream& write);
	void readDayRep(istream& write);


	BuyOp& operator[](int index);
	DailyReport& operator=(const DailyReport& obj);



	void Tab(/*double* arr, double dx, int numOfElem, double val*/);
	void line(char start, char middle, char cross, char end, int count, int len);
	void line1(char start, char middle, char cross, char end, int count, int len);
};

#endif

