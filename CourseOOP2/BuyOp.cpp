#include "BuyOp.h"

BuyOp::BuyOp()
{
	this->n = 0;
	this->prLst = NULL;
	date.setDate(1, 1, 1900);
}



BuyOp::BuyOp(int day, int month, int year, Product* prLst, int n, int salePerc): 
	Client(salePerc)
{
	this->date.setDate(day, month, year);
	setPrList(prLst, n);
}

BuyOp::BuyOp(int day, int month, int year, Product prod, int salePerc):
	Client(salePerc)
{
	this->date.setDate(day, month, year);
	addProduct(prod);
}



BuyOp::BuyOp(const BuyOp& cpy):
	Client(cpy.salePerc)
{
	this->date = cpy.date;
	this->sumOfProds = cpy.sumOfProds;
	this->sumWithSale = cpy.sumWithSale;
	this->n = cpy.n;
	this->prLst = new Product[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->prLst[i] = cpy.prLst[i];
	}
}

BuyOp::~BuyOp()
{
	delete[] this->prLst;// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void BuyOp::setPrList(Product* prLst, int n)
{
	this->n = n;
	if(this->prLst)
	{
		delete[] this->prLst;
	}

	this->prLst = new Product[this->n];

	for (int i = 0; i < this->n; i++)
	{
		this->prLst[i] = prLst[i];
	}
}

void BuyOp::setDate(int day, int month, int year)
{
	date.setDate(day, month, year);
}

void BuyOp::setDay(int day)
{
	date.setDay(day);
}

void BuyOp::setMonth(int month)
{
	date.setMonth(month);
}

void BuyOp::setYear(int year)
{
	date.setYear(year);
}



void BuyOp::addProduct(string prodName, double prodPrice, bool saleAvib)
{
	Product* cpy = new Product[n + 1];
	Product prod(prodName, prodPrice, saleAvib);

	for (int i = 0; i < n; i++)
	{
		*(cpy + i) = *(prLst + i);
	}
	*(cpy + n) = prod;
	this->n++;
	delete[] prLst;
	this->prLst = cpy;
}

void BuyOp::addProduct(Product prod)
{
	Product* cpy = new Product[n + 1];

	for (int i = 0; i < n; i++)
	{
		*(cpy + i) = *(prLst + i);
	}
	*(cpy + n) = prod;
	this->n++;
	delete[] prLst;
	this->prLst = cpy;
}

double BuyOp::getSumOfProds()
{
	sumOfProds = 0;
	for (int i = 0; i < n; i++)
	{
		sumOfProds += prLst[i].getProdPrice();
	}
	

	return sumOfProds;
}


double BuyOp::getSumWithSale()
{
	sumWithSale = 0;
	for (int i = 0; i < n; i++)
	{
		if (prLst[i].getSaleAviab())
		{
			sumWithSale += prLst[i].getProdPrice() - (prLst[i].getProdPrice() * (double(salePerc) / 100));
		}
		else
		{
			sumWithSale += prLst[i].getProdPrice();
		}
	}
	setSumOfPurch(sumWithSale);
	return sumWithSale;
}

int BuyOp::getDay()
{
	return date.getDay();
}

int BuyOp::getMonth()
{
	return date.getMonth();
}

int BuyOp::getYear()
{
	return date.getYear();
}

void BuyOp::Show()
{
	for (int i = 0; i < n; i++)
	{
		cout << prLst[i].getProdName() << endl;
	}
}

void BuyOp::show()
{
	cout << "________________________________________" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Product Name: " << prLst[i].getProdName() << endl;
		cout << "Producr Price: " << prLst[i].getProdPrice() << endl;
		cout << "Sale Available: " << (prLst[i].getSaleAviab() ? "Sale Avaib" : "Sale Unavaib") << endl;
		cout << "-----------------------------------------" << endl;
	}
	cout << "Sum Of All Products: " << getSumOfProds() << endl;
	cout << "Sum with sale: " << getSumWithSale() << endl;

	Client::show();

	
}

Product& BuyOp::operator[](int index)
{
	return prLst[index];
}


BuyOp& BuyOp::operator=(const BuyOp& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	date = obj.date;
	ID = obj.ID;
	sumOfProds = obj.sumOfProds;
	salePerc = obj.salePerc;
	n = obj.n;
	sumWithSale = obj.sumWithSale;

	if (this->prLst)
	{
		delete[] this->prLst;
	}

	prLst = new Product[n];
	for (int i = 0; i < n; i++)
	{
		prLst[i] = obj.prLst[i];
	}

	return *this;
}

