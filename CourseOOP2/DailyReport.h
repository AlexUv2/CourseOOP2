#pragma once
#include "Date.h"
#include "BuyOp.h"
#include <iostream>

using namespace std;
#ifndef DAILYREP_H_
#define DAILYREP_H_

class DailyReport :public Date
{

	BuyOp* lst;
	int n;
public:

	DailyReport();
	DailyReport(int day, int month, int year, BuyOp* lst, int n);
	DailyReport(int day, int month, int year, BuyOp lst);
	DailyReport(const DailyReport& cpy);
	~DailyReport();


	void setBuyOpLst(BuyOp*lst, int n);

	void show();

	void addDailyReport(BuyOp Oper);

	void setReportDate(int day, int month, int year);

	

	BuyOp& operator[](int index);
	DailyReport& operator=(const DailyReport& obj);
};

#endif

