#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Bank.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int answer = 0;
	Bank Test = Bank();
	while(true)
	{ 
		system("cls");
		Test.Show();
		cout << endl;
		Test.ShowMenu();
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			int answ = 0;
			string name;
			double valid_cash;
			string id_account;
			string type;
			string f, i, o;
			cout << "<������� �������>" << endl;
			cin >> f;
			cout << "<������� ���>" << endl;
			cin >> i;
			cout << "<������� ��������>" << endl;
			cin >> o;
			name = f + " " + i + " " + o;
			cout << "<������� ����� �����>" << endl;
			cin >> valid_cash;
			cout << "<������� Id>" << endl;
			cin >> id_account;
			cout << "<������� ��� ��������(1 - debit)(2 - deposit)(3 - credit)>" << endl;
			cin >> answ;
			if (answ == 1)
				type = "debit";
			if (answ == 2)
				type = "deposit";
			if (answ == 3)
				type = "credit";
			BankAccount to_add = BankAccount(name,valid_cash,id_account,type);
			Test.AddAccount(to_add);
			break;
		}
		case 2:
		{
			string delete_id;
			cout << "<������� Id(10)>" << endl;
			cin >> delete_id;
			Test.RemoveAccount(delete_id);
			break;
		}
		case 3:
		{
			Test.Save();
			cout << "<�������>" << endl;
			system("pause");
			break;
		}
		case 4:
		{
			//�� ������ ����������
			//�� �����
			string from_id, to_id;
			double transfer;
			cout << "<������� Id �����������>" << endl;
			cin >> from_id;
			cout << "<������� Id ����������>" << endl;
			cin >> from_id;
			cout << "<������� ����� �����>" << endl;
			cin >> transfer;
			Test.Transfer(from_id, to_id, transfer);
			break;
		}
		case 5:
		{
			//�� ������ ����������
		}
		case 6:
		{
			Test.SortSum();
			break;
		}
		case 7:
		{
			Test.SortName();
			break;
		}
		case 0:
		{
			cout << "<�����>" << endl;
			system("pause");
			return 0;
		}
		default:
		{

		}
		}
	}
	system("pause");
	return 0;
}