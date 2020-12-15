#pragma once
//#include <vector>
#include "Client.h"
#include "Date.h"
#include "Product.h"
#ifndef BUYOP_H_
#define BUYOP_H_
class BuyOp : public Client
{
protected:
	Date date; //Дата покупки
	Product* prLst;
	double sumOfProds; // Сумма товаров
	double sumWithSale; // Сумма со скидкой
	int n = 0;

public:
	BuyOp();
	BuyOp(int day, int month, int year, Product* prLst, int n, int salePerc);
	BuyOp(int day, int month, int year, Product prod, int salePerc);
	BuyOp(const BuyOp& cpy);
	~BuyOp();

	void setPrList(Product* prLst, int n);

	void setDate(int day, int month, int year);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);



	void addProduct(string prodName, double prodPrice, bool saleAvib);
	void addProduct(Product prod);

	double getSumOfProds();
	double getSumWithSale();
	int getDay();
	int getMonth();
	int getYear();

	void Show();

	void show();

	Product& operator[](int index);
	BuyOp& operator=(const BuyOp& obj);
};
#endif
