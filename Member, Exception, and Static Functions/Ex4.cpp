/*
C++ course
exercise 4.1
name:linoy boni
id:211820824
the program is running a bank ATM
*/
#include "Clock.h"
#include "Account.h"

istream& operator>>(istream& s, account &a)
{
	int aa,c;
	s>>aa;
	s>>c;
    account temp(aa,c);
	a = temp;
	return s;
}
ostream& operator<<(ostream& s, Clock c)
{
	int x=c.hour;
	if( x<10)
		cout<<"0";
	s<<c.hour<<":";
	x=c.minute;
	if(x<10)
		cout<<"0";
	s<<c.minute<<":";
	x=c.second;
	if(x<10)
		cout<<"0";
	s<<c.second;
	return s;
	
/*	int x=c.second;
	if( x<10)
		cout<<"0";
	s<<c.second<<":";
	x=c.minute;
	if(x<10)
		cout<<"0";
	s<<c.minute<<":";
	x=c.hour;
	if(x<10)
		cout<<"0";
	s<<c.hour<<endl;
	return s;*/
}
istream& operator>>(istream& s, Clock &r)
{
	s>>r.hour;
	s>>r.minute;
	s>>r.second;
	return s;
}
enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};

action menu()
{
	cout<<"enter 1 to get account balance"<<endl;
	cout<<"enter 2 to deposit money"<<endl;
	cout<<"enter 3 to withdraw money"<<endl;
	cout<<"enter 4 to see the sum of all withdraws"<<endl;
	cout<<"enter 5 to see the sum of all Deposits"<<endl;
	cout<<"enter 0 to stop"<<endl;
	int x;
	cin>>x;
	return (action)x;
}

int findAccount(account* bank,int size, Clock&c)
{
	int number,code;
	cout<<endl<<"please enter account number: ";
	cin>>number;
	int i=0;
		while (i<size && bank[i].getAccount()!=number)
		i++;
		if(i>=size)
			{cout<<c<<"\t ERROR: no such account number!";return -1;}
		else{
	cout<<endl<<"please enter the code: "<<endl;
	cin>>code;
	if (bank[i].getCode()==code)
		return i;
	cout <<c<< "\t ERROR: wrong code!"; return 0;}
}

void printTransaction(account a, action ac,Clock& c)
{
	cout<<c<<"\t";
	;
	switch (ac)
	{
	case balance: cout<<"account #: "<<a.getAccount()<<"\t";
				  cout<<"balance: "<<a.getBalance()<<endl;
		break;
	case deposit: 
	case withdraw: cout<<"account #: "<<a.getAccount()<<"\t";
				   cout<<"new balance: "<<a.getBalance()<<endl;
		break;
	case sumDeposit:
			cout<<"sum of all deposits: "<<account::getSumDeposit()<<endl;
			break;
	case sumWithdraw:
			cout<<"sum of all withdraws: "<<account::getSumWithdraw()<<endl;
			break;	
	}
}

void getBalance(account* bank,int size,Clock& c)
{
	int i=findAccount(bank,size,c);
	c+=20;
	printTransaction(bank[i],balance,c);
}

void cashDeposit(account* bank,int size,Clock& c)
{
	int i=findAccount(bank,size,c);
	if (i != 0)
	{
		float amount;
		cout << "enter the amount of the check: "<<endl;
		cin >> amount;
		if(!bank[i].deposit(amount,c))
		{
			c += 30;
			bank[i].setBalance(amount);///////////////
			printTransaction(bank[i], deposit, c);
		}
		//else{cout<<"\t"<<c;}
	}
}

void cashWithdraw(account* bank,int size,Clock& c)
{
	int i=findAccount(bank,size,c);
	float amount;
	if(i!=-1)
	{
		cout<<"enter the amount of money to withdraw: "<<endl;
		cin>>amount;
		if(!bank[i].withdraw(amount,c))
		{
			c+=50;
			bank[i].setBalance((-1)*amount);
			printTransaction(bank[i],withdraw,c);
		}
	//	else{cout<<c<<endl;}

	}
//	else{cout<<c<<endl;}
}


int main()
{
	Clock c(0,0,8);
	account bank[10];
	cout<<"enter account number and code for 10 accounts:\n"<<endl;
	for(int i=0;i<10;i++)
	{
	    try{
	        cin>>bank[i];
	        for (int j=0;j<i;j++)
	            if (bank[i].getAccount()==bank[j].getAccount())
	                throw "ERROR: account number must be unique!\n";
	    }
	    catch (const char* msg)
	    {
	       cout<<c<<'\t'<<msg;
	       i--;
	    }
	}
	action ac=menu();
	while(ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank,10,c);
			break;
		case withdraw:cashWithdraw(bank,10,c);
			break;
		case deposit:cashDeposit(bank,10,c); 
			break;		
		case sumDeposit:c+=60;
			printTransaction(bank[0],sumDeposit,c);
			break;
		case sumWithdraw:c+=60;
			printTransaction(bank[0],sumWithdraw,c);			
	
		}
		ac=menu();
	}
	return 0;
}
/*
enter account number and code for 10 accounts:
1111
1111
2222
2222
3333
3333
4444
4444
5555
5555
6666
6666
7777
7777
8888
8888
9999
1010
1010
9999
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
1
please enter account number: 1111
please enter the code: 1111
20:0:8  account #: 1111 balance: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
2
please enter account number: 1111
please enter the code: 1111
enter the amount of the check: 2000
50:0:8  account #: 1111 new balance: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
3
please enter account number: 1111
please enter the code: 1111
enter the amount of money to withdraw: 1000
100:0:8 account #: 1111 new balance: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
1
please enter account number: 1111
please enter the code: 1111
0:2:8   account #: 1111 balance: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
5
0:3:8   sum of all withdraws: 1
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
4
0:4:8   sum of all deposits: 1
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
*/






