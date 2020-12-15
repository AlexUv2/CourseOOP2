#pragma once
using namespace std;
#ifndef CLIENT_H_
#define CLIENT_H_

class Client
{
protected:
	int ID;
	static int ID_counter;
	double sumOfPurch;
	int salePerc;
public:
	Client();
	Client(int selePerc); //Мы не передаем ID так ак он устанавливается по умолчанию
	Client(const Client& Cpy);
	~Client();

	void setSumOfPurch(double sumOfPurch);
	void setSelePerc(int salePecr);

	double getSumOfPurch();
	int getSalePerc();
	int getID();

	virtual void show();

	Client operator=(Client obj);
};

#endif