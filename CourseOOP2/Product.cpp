#include "Product.h"

Product::Product()
{
	this->prodName = "No Name";
	this->prodPrice = 0.0;
	this->saleAviab = false;
}

Product::Product(string prodName, double prodPrice, bool saleAviab)
{
	this->prodName = prodName;
	this->prodPrice = prodPrice;
	this->saleAviab = saleAviab;
}

Product::Product(const Product& cpy)
{
	this->prodName = cpy.prodName;
	this->prodPrice = cpy.prodPrice;
	this->saleAviab = cpy.saleAviab;
}

Product::~Product()
{
}

void Product::setProdName(string prodName)
{
	if (prodName.length() > 0)
	{
		this->prodName = prodName;
	}
	else
	{
		this->prodName = "No Name";
	}
}

void Product::setProdPrice(double prodPrice)
{
	if (prodPrice >= 0)
	{
		this->prodPrice = prodPrice;
	}
	else
	{
		this->prodPrice = 0;
	}
}

void Product::setSaleAviab(bool saleAviab)
{
	if (saleAviab)
	{
		this->saleAviab = saleAviab;
	}
	else
	{
		this->saleAviab = false;
	}
}

string Product::getProdName()
{
	return this->prodName;
}

double Product::getProdPrice()
{
	return this->prodPrice;
}

bool Product::getSaleAviab()
{
	return this->saleAviab;
}

Product Product::operator=(Product ob)
{
	prodName = ob.prodName;
	prodPrice = ob.prodPrice;
	saleAviab = ob.saleAviab;
	return *this;
}
