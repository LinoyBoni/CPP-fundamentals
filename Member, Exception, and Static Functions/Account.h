/*
class account
C++ course
exercise 4.1
name:linoy boni
*/
#pragma once
#include<iostream>
#include"Clock.h"
using namespace std;
class account
{
private:
	int accountNumber;
	int code; 
	int balance;

	static int sumWithdraw;
	static int sumDeposit; 

public:
	account();//default ctor
	account(int, int); //ctor
	account(const account&);//cpy ctor
	//set N get 
	int getAccount();
	int getCode();
	int getBalance();
	void setBalance(int);
	friend istream& operator>>(istream& s, account &a);
	bool withdraw(int nis,Clock& c);
	bool deposit(int, Clock& c);

	static int getSumWithdraw(){return sumWithdraw;}
	static int getSumDeposit(){return sumDeposit;}
};
