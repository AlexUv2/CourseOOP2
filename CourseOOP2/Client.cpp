#include "Client.h"
#include <iostream>
using namespace std;

int Client::ID_counter = 0;

Client::Client()
{
	ID = ID_counter++;
	sumOfPurch = 0.0;
	salePerc = 0;
}

Client::Client(int salePerc) //ID ��������������� �� ���������
{
	ID = ID_counter++;
	this->salePerc = salePerc;
}

Client::Client(const Client& Cpy)
{
	this->ID = Cpy.ID;
	this->sumOfPurch = Cpy.sumOfPurch;
	this->salePerc = Cpy.salePerc;
}


int Client::getID()
{
	return ID;
}

void Client::show()
{
	cout << "Client ID: " << this->getID() << endl;
	cout << "Client SumOfPurch: " << this->getSumOfPurch() << endl;
	cout << "Client Sale Percent: " << this->getSalePerc() << endl;
}

Client Client::operator=(Client obj)
{
	ID = obj.ID;
	sumOfPurch = obj.sumOfPurch;
	salePerc = obj.salePerc;

	return *this;
}


void Client::setSumOfPurch(double sumOfPurch)
{
	this->sumOfPurch = sumOfPurch;
}


void Client::setSelePerc(int salePecr)
{
	this->salePerc = salePecr;
}

Client::~Client()
{
}

double Client::getSumOfPurch()
{
	return this->sumOfPurch;
}

int Client::getSalePerc()
{
	return this->salePerc;
}
