#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "clocale"
#include <locale>
#include "Windows.h"
#include <iostream>
#include <fstream>
#include <string>
#include <class.cpp>
using namespace std;

// � �++ ������ ������� �������� �������������. �� ���������� �������� ����������� set � get. ����� ���� ������, ����������� �������� private ����� get

class Menu // ����� ����
{
private:
	int number;
public:
	void output_menu() // ������� ������ ���� �� �����
	{
		cout << "���� ��������� \n\n";
		cout << "\n 1. ���������� ������ � ������� �����";
		cout << "\n 2. ����� ���������� ������ �� �����";
		cout << "\n 3. ����� ���� ������� �� �����";
		cout << "\n 4. �������� ���������� ������ �� �����";
		cout << "\n 5. �������� ���� ������� �� �����";
		cout << "\n 6. ����� �� ��������� \n\n";
	}

	int choose_number() // ������� ������ �������� ����
	{
		cout << "������� �������� ����: "; cin >> number;
		return number;
	}

};
//==============================================================

//-----------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "russian");

	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);
	int flag = 1;
	while (flag = 1)
	{
		Animal ST1;
		Menu M1;

		M1.output_menu();

		int nnumber = M1.choose_number();

		if (nnumber == 1) ST1.AddAnimal();
		if (nnumber == 2) ST1.Out_String();
		if (nnumber == 3) ST1.OutAnimal();
		if (nnumber == 4) ST1.Delete_String();
		if (nnumber == 5) ST1.Delete_Animal();
		if (nnumber == 6) exit(0);
		cout << endl;

		cout << "��� ���? 1 - �� / 0 - ���: "; cin >> flag;
		cout << endl;

		if (flag == 0)exit(0);
	}

	system("pause");
	return 0;
}
