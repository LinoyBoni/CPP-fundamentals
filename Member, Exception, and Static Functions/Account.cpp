/*
implementaion class account
C++ course
exercise 4.1
name:linoy boni
*/
#include"Account.h"
#include"Clock.h"
#include<string>
#include<iostream>
using namespace std;

int account::sumWithdraw=0;
int account::sumDeposit=0;

account::account()
{
	accountNumber = 0;
	code = 0;
	balance = 0;
}
account::account(const account & a)
{
	accountNumber = a.accountNumber;
	code = a.code;
	balance = a.balance;
}
account::account(int MYaccountNumber, int MYcode)
{
	bool flag = true;
	while(flag)
	{
		try
		{
			if(MYcode>9999 || MYcode<1000)
				throw "ERROR: code must be of 4 digits!";	
			if(MYcode<999 || MYcode>9999 )
				throw "ERROR: wrong code!";
			flag = false;
		}
		catch(char* str)
		{
			cout<<str<<endl;
			cin>>MYaccountNumber;
			cin>>MYcode;
		}
	}

	accountNumber = MYaccountNumber;
	code = MYcode;
	balance = 0;
}
int account::getAccount()
{return accountNumber;}
int account::getCode()
{return code;}
int account::getBalance()
{return balance;}

void account::setBalance(int newBalance)
{balance += newBalance;}
bool account::withdraw(int nis, Clock&c)
{
	try
	{
		if(nis>2500 && nis<6000)
		{
			string st = "ERROR: cannot withdraw more than 2500 NIS! \t";
			throw st;
		}
		if(nis>6000)
		{
			string st = "ERROR: cannot have less than - 6000 NIS! \t";
			throw st;
		}
	}
	catch(string str)
	{cout<<c<<"\t"<<str;return true;}
	sumWithdraw+=nis;
	return false;
}
bool account::deposit(int nis,Clock & c)
{
	try
	{
		if(nis>10000)
		{
		    string st = "ERROR: cannot deposit more than 10000 NIS!";
		    throw st;
		}
	}
	catch(string str)
	{cout<<c<<"\t"<<str;return true;}
	sumDeposit+=nis;
	return false;
}

