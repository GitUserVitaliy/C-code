#pragma once

#include<iostream>
#include<sstream>
#include<Windows.h>
#include<string>
#include<vector>

using namespace std;

class SmartCheck
{
private:
	string data;
	bool check;
public:
	SmartCheck()
	{
		data = "";
		check = 0;
	}
	SmartCheck(string Input)
	{
		data = Input;
		for (int i = 0; i < data.length(); i++)
		{
			if (isdigit(data[i]) || data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/' || data[i] == ' ')
			{
				check = 1;
				continue;
			}
			else
			{
				check = 0;
				break;
			}
		}
	}
	bool GetCheck()
	{
		return check;
	}
};
class SmartCalc
{
private:
	int result;
public:
	SmartCalc()
	{
		result = 0;
	}
	SmartCalc(string Data)
	{
		SmartCheck Check = SmartCheck(Data);
		if (Check.GetCheck() == 1)
		{
			vector<string> Stack;
			int preposition = 0;
			for (int i = 0; i < Data.length(); i++)
			{
				if (Data[i] == ' ')
				{
					Stack.push_back(Data.substr(preposition, i - preposition));
					preposition = i + 1;
				}
			}
			string LastNum = "";
			for (int i = Data.length(); i > 0; i--)
			{
				if (Data[i] != ' ' && Data[i] != '+' && Data[i] != '-' && Data[i] != '*' && Data[i] != '/')
				{
					LastNum.push_back(Data[i]);
				}
				else
				{
					break;
				}
			}
			string buf = LastNum;
			LastNum = "";
			for (int i = buf.size(); i > 0; i--)
			{
				LastNum.push_back(buf[i]);
			}
			string buf1 = LastNum;
			LastNum = "";
			for (int i = 1; i < buf1.size(); i++)
			{
				LastNum.push_back(buf1[i]);
			}
			Stack.push_back(LastNum);
			int BufResult = 0;
			while(true)
			{
				for (int i = 0; i < Stack.size(); i++)
				{
					if (Stack[i] == "/")
					{
						BufResult = atoi(Stack[i - 1].c_str()) / atoi(Stack[i + 1].c_str());
						string Result = "";
						stringstream ss;
						ss << BufResult;
						ss >> Result;
						Stack[i] = Result;
						Stack[i - 1].erase();
						Stack[i + 1].erase();
						BufResult = 0;
					}
					if (Stack[i] == "*")
					{
						BufResult = atoi(Stack[i - 1].c_str()) * atoi(Stack[i + 1].c_str());
						string Result = "";
						stringstream ss;
						ss << BufResult;
						ss >> Result;
						Stack[i] = Result;
						Stack[i - 1].erase();
						Stack[i + 1].erase();
						BufResult = 0;
					}
					for (int i = 0; i < Stack.size(); i++)
					{
						if (Stack[i] == "")
						{
							Stack.erase(Stack.begin() + i);
						}
					}
				}
				for (int i = 0; i < Stack.size(); i++)
				{
					if (Stack[i] == "+")
					{
						BufResult = atoi(Stack[i - 1].c_str()) + atoi(Stack[i + 1].c_str());
						string Result = "";
						stringstream ss;
						ss << BufResult;
						ss >> Result;
						Stack[i] = Result;
						Stack[i - 1].erase();
						Stack[i + 1].erase();
						BufResult = 0;
					}
					if (Stack[i] == "-")
					{
						BufResult = atoi(Stack[i - 1].c_str()) - atoi(Stack[i + 1].c_str());
						string Result = "";
						stringstream ss;
						ss << BufResult;
						ss >> Result;
						Stack[i] = Result;
						Stack[i - 1].erase();
						Stack[i + 1].erase();
						BufResult = 0;

					}
					for (int i = 0; i < Stack.size(); i++)
					{
						if (Stack[i] == "")
						{
							Stack.erase(Stack.begin() + i);
						}
					}
				}
		
				//Check
				for (int i = 0; i < Stack.size(); i++)
				{
					if (Stack[i] == "")
					{
						Stack.erase(Stack.begin() + i);
					}
				}
				if (Stack.size() == 1)
				{
					break;
				}
			}
			result = atoi(Stack[0].c_str());
			cout << "Result: " << result << endl;
		}
		else
		{
			cout << "Error" << endl;
		}
	}
};

