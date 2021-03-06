#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//���������� ��� ������������� ���������
#include "clocale"
#include <locale>
#include "Windows.h"
#include <iostream>
#include <fstream>// ���������� ��� ������ � �������
#include <string>

using namespace std;
// � �++ ������ ������� �������� �������������. �� ���������� �������� ����������� set � get. ����� ���� ������, ����������� �������� private ����� get

class Animal // ����� ������� �����
{

private:
	//     ���,  ���,  ���������,�����������, ������� �� �� �������  ���� ���������,  ����������  
	string Type, Kind, family, chislo, obitaet, Date, Primechanie;
	string ALL;

public:

	~Animal() // ���������� (������������ ��� �������� ������� ������)
	{
		cout << "������ ������ ������. ��������� ����������" << endl;
	}

	void AddAnimal(); // ����������
	void OutAnimal(); // ����� ���� ����� �����
	void Out_String(); // ����� ���������� ������ �����
	void Delete_String(); // �������� ���������� ������ �����
	void Delete_Animal(); // �������� ���� �����


}SP1;
//----------------------------------------------------------------------
void Animal::AddAnimal() //�������� ������ � ����
{
	ofstream file;
	file.open("F:\\����\puhovkurs\RedBook.txt", ios_base::app); // ��������� ����

	if (!file) //�������� �� �������� �����
	{
		cout << "���� �� ������\n\n";
	}
	else
	{
		cout << "���� ������ ��������!\n\n";
	}

	cout << "������� ���(���������): "; cin >> Type;
	cout << "������� ���(���������): "; cin >> Kind;
	cout << "������� ���������(���������): "; cin >> family;
	cout << "������� �����������: "; cin >> chislo;
	cout << "������� �� �� �������(���������): "; cin >> obitaet;
	cout << "������� ���� ��������� � �����: "; cin >> Date;

	cout << "����������: "; cin >> Primechanie;

	ALL = "���: " + Type + "; " + "���: " + Kind + "; " + "���������: " + family + "; " + "����������� ���������: " + chislo + "; " + "���� �� �� �������: " + obitaet + "; " + "���� ���������: " + Date + "; "  + "����������: " + Primechanie;

	file << ALL; // ������ � ���� ������
	file << "\n";
	file.close();
};
//---------------------------------------------------------------------------------------
void Animal::OutAnimal() // ������� ������ �� �����
{
	ifstream file;
	file.open("F:\\����\puhovkurs\RedBook.txt"); // ��������� ����

	if (!file)//�������� �� �������� �����
	{
		cout << "���� �� ������\n\n";
	}
	else
	{
		cout << "���� ������ ��������!\n\n";
	}

	char St[255];

	while (1) { //���������� ������ �� ����� � ������ � ������ St � ����������� ��� ������� �� ����� ������ �����
		if (file.eof()) break;
		file.getline(St, sizeof(St));
		cout << St << endl;
	}
	file.close();
};
//----------------------------------------------------------------------------

void Animal::Out_String() // ������� ������ �� �����
{
	ifstream file;
	file.open("F:\\����\puhovkurs\RedBook.txt");//�������� ����� �� ������

	char Mass[255];
	int StringNumber = 0;//������ ����� ������
	cout << "������� ����� ������ ��� ������: "; cin >> StringNumber;

	/*��������� ���� �� �����*/
	while (1)
	{
		file.getline(Mass, sizeof(Mass));
		StringNumber--;
		if (StringNumber == 0)break;
	}
	cout << Mass;
	file.close();

}
//----------------------------------------------------------------------------
void Animal::Delete_Animal() // ������� ��� ������ �� �����
{
	ofstream file;
	file.open("F:\\����\puhovkurs\RedBook.txt", ios::trunc); // ��������� ����
	file.close();
	cout << endl << "��� ������ ������� �������." << endl;
};
//-----------------------------------------------------------------------------
void Animal::Delete_String() // ������� ���������� ������ �� �����
{
	ifstream file;
	file.open("F:\\����\puhovkurs\RedBook.txt"); // �������� �����

	if (!file)//�������� �� �������� �����
	{
		cout << "���� �� ������\n\n";
	}
	else
	{
		cout << "���� ������ ��������!\n\n";
	}

	int s = 0; // ����� ������ ������� ���������� �������
	int k = 0; // ������� �����
	string Line;
	string Line_File; // �������� ������ �����

	cout << "������� ����� ������ ��� ��������: ";
	cin >> s;

	while (getline(file, Line))
	{
		k++;
		if (!(k == s))
		{
			Line_File.insert(Line_File.size(), Line); //���������� ������
			Line_File.insert(Line_File.size(), "\r\n");	//���������� �������� �� ��������� ������
		}
	}

	file.close();
	std::ofstream file_out;
	file_out.open("F:\\����\puhovkurs\RedBook.txt", std::ios::trunc | std::ios::binary);
	file_out.write(Line_File.c_str(), Line_File.size());
	file_out.clear();
	cout << "������ ������� ������� \n";
}
