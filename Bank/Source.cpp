#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <Windows.h>
#include "Bank.h"

using namespace std;

void PrintMenu()
{
	cout << "<1><��������� ����>" << endl;
	cout << "<2><������� ����>" << endl;
	cout << "<3><������� ����(ID)>" << endl;
	cout << "<4><��������� ����(ID)>" << endl;
	cout << "<5><����� ������ �� �����(ID)>" << endl;
	cout << "<0><�����>" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int answer = -1;
	Bank Database;
	cout << "<���� �������>" << endl;
	while (answer != 0)
	{
		system("cls");
		Database.Show();
		cout << endl;
		PrintMenu();
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			Database.Save();
			cout << "<�������>" << endl;
			break;
		}
		case 2:
		{
			int answ_type = 0;
			string _name;
			double _valid_cash;
			string _id_account;
			string _type;
			string _first, _second, _third;
			cout <<"<������� ���>"<< endl;
			cin >> _first;
			cout << "<������� �������>" << endl;
			cin >> _second;
			cout << "<������� ��������>" << endl;
			cin >> _third;
			_name = _first + " " + _second + " " + _third;
			cout << "<������� Id><10 ����>" << endl;
			cin >> _id_account;
			cout << "<������� ��������>" << endl;
			cin >> _valid_cash;
			cout << "<������� ���><1->����������><2->���������><3->���������>" << endl;
			cin >> answ_type;
			if (answ_type == 1)
				_type = "deposit";
			if (answ_type == 2)
				_type = "debit";
			if (answ_type == 3)
				_type = "credit";
			BankAccount add = BankAccount(_name, _valid_cash, _id_account, _type);
			Database.AddAccount(add);
			break;
		}
		case 3:
		{
			string delete_id = "";
			cout << "<������� ID>" << endl;
			cin >> delete_id;
			Database.RemoveAccount(delete_id);
			cout << "<�������>" << endl;
			break;
		}
		case 4:
		{
			string _id = "";
			double _sum = 0;
			cout << "<������� ID>" << endl;
			cin >> _id;
			cout << "<������� �����>" << endl;
			cin >> _sum;
			Database.AddCashToAccount(_sum,_id);
			break;
		}
		case 5:
		{
			string _id = "";
			double _sum = 0;
			cout << "<������� ID>" << endl;
			cin >> _id;
			cout << "<������� �����>" << endl;
			cin >> _sum;
			Database.WithdrawCashToAccount(_sum, _id);
			break;
		}
		case 0:
		{
			char symbol = ' ';
			while (true)
			{
				
				system("cls");
				cout << "<��������� ��������� � ����(Y/N)>" << endl;
				cin >> symbol;
				if (symbol == 'Y' || symbol == 'y')
				{
					Database.Save();
					cout << "<�������>" << endl;
					break;
				}
				else
				{
					if (symbol == 'N' || symbol == 'n')
					{
						cout << "<�����>" << endl;
						break;
					}
					else
					{
						cout << "<������>" << endl;
					}
				}
				system("pause");
			}
		}
		default:
		{
			continue;
		}
		}
		system("pause");
	}
	system("pause");
	return 0;
}