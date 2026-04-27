//linoy boni
//ID:211820824

#include <stack>
#include <string>
#include <iostream>
using namespace std;
string infixToPostfix(string s)
{
	string str;
	stack<char> stk, help;
	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];
		if (ch == '(')
		{
			stk.push(ch);
		}
		else if (ch == ')')
		{
			while (stk.top() != '(')
			{
				str += stk.top();
				str += " ";
				stk.pop();
			}
			stk.pop();
		}
		else 
			if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
		     {
			  stk.push(ch);
		     }
		     else
	  	    	if (isdigit(ch))
	           	{
		         	if (isdigit(s[i + 1]))
		        	{
						
			        	str += ch;
				        str += s[++i];
			           	str += " ";
		           	}
					else
					{
						str += ch;
						str += " ";
					}
				}
		
	}
	while (!stk.empty())
	{
		str += stk.top();
		str += " ";
		stk.pop();
	}
	return str;
}

int calcPostfix(string ss)
{
	stack<float> stok;
	for (int i = 0; i < ss.length(); i += 2)
	{
		char tav = ss[i];
		if (isdigit(tav))
		{
			float num = tav - '0';
			if (isdigit(ss[i + 1]))
			{
				num = (tav - '0') * 10 + (ss[++i] - '0');
			}
			stok.push(num);
		}
		else 
			if (tav == '/' || tav == '*' || tav == '+' || tav == '-')
		    {
				float a = stok.top();
				stok.pop();
				float b = stok.top();
				stok.pop();
				float result;
				switch (tav)
			
			{
			case '*': result = a * b; break;
			case '/': result = b / a; break;
			case '+': result = a + b; break;
			case '-': result = b - a; break;
			default: cout << "ERROR";
			}
			stok.push(result);
		}
	}
	return stok.top();
}
int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	getline(cin, exp);
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << calcPostfix(postfix) << endl;
	return 0;
}