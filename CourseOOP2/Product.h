#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifndef PRODUCT_H_
#define PRODUCT_H_

class Product
{
	string prodName;
	double prodPrice;
	bool saleAviab; //aviability
public:
	Product();
	Product(string prodName, double prodPrice, bool saleAviab);
	Product(const Product& cpy);
	~Product();

	void setProdName(string prodName);
	void setProdPrice(double prodPrice);
	void setSaleAviab(bool saleAviab);

	string getProdName();
	double getProdPrice();
	bool getSaleAviab();

	Product operator=(Product ob);
};

#endif
