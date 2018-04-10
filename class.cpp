#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//Библиотека для использования кириллицы
#include "clocale"
#include <locale>
#include "Windows.h"
#include <iostream>
#include <fstream>// библиотека для работы с файлами
#include <string>

using namespace std;
// В с++ методы доступа являются формальностью. Не существует жетского определения set и get. Любой член класса, возращающий значение private будет get

class Animal // Класс красная книга
{

private:
	//     вид,  род,  семейство,численность, обитает ли на Украине  Дата занесения,  Примечание  
	string Type, Kind, family, chislo, obitaet, Date, Primechanie;
	string ALL;

public:

	~Animal() // деструктор (используется для удаления объекта класса)
	{
		cout << "Объект класса удален. Программа завершенна" << endl;
	}

	void AddAnimal(); // Добавление
	void OutAnimal(); // Вывод всех строк файла
	void Out_String(); // Вывод конкретной строки файла
	void Delete_String(); // Удаление конкретной строки файла
	void Delete_Animal(); // Удаление всех строк


}SP1;
//----------------------------------------------------------------------
void Animal::AddAnimal() //Добавить запись в файл
{
	ofstream file;
	file.open("F:\\ТРПО\puhovkurs\RedBook.txt", ios_base::app); // открываем файл

	if (!file) //Проверка на открытие файла
	{
		cout << "Файл не открыт\n\n";
	}
	else
	{
		cout << "Файл открыт коректно!\n\n";
	}

	cout << "Введите вид(латиницой): "; cin >> Type;
	cout << "Введите род(латиницой): "; cin >> Kind;
	cout << "Введите семейство(латиницой): "; cin >> family;
	cout << "Введите численность: "; cin >> chislo;
	cout << "Обитает ли на Украине(латиницой): "; cin >> obitaet;
	cout << "Введите дату занесение в книгу: "; cin >> Date;

	cout << "Примечание: "; cin >> Primechanie;

	ALL = "Вид: " + Type + "; " + "Род: " + Kind + "; " + "Семейство: " + family + "; " + "Численность популяции: " + chislo + "; " + "Есть ли на Украине: " + obitaet + "; " + "Дата занесения: " + Date + "; "  + "Премичание: " + Primechanie;

	file << ALL; // Запись в файл данных
	file << "\n";
	file.close();
};
//---------------------------------------------------------------------------------------
void Animal::OutAnimal() // Вывести данные из файла
{
	ifstream file;
	file.open("F:\\ТРПО\puhovkurs\RedBook.txt"); // открываем файл

	if (!file)//проверка на открытие файла
	{
		cout << "Файл не открыт\n\n";
	}
	else
	{
		cout << "Файл открыт коректно!\n\n";
	}

	char St[255];

	while (1) { //Считывание данных из файла и запись в массив St с последующим его выводом на экран внутри цикла
		if (file.eof()) break;
		file.getline(St, sizeof(St));
		cout << St << endl;
	}
	file.close();
};
//----------------------------------------------------------------------------

void Animal::Out_String() // Вывести данные из файла
{
	ifstream file;
	file.open("F:\\ТРПО\puhovkurs\RedBook.txt");//открытие файла на чтение

	char Mass[255];
	int StringNumber = 0;//хранит номер строки
	cout << "Введите номер строки для вывода: "; cin >> StringNumber;

	/*считываем файл до конца*/
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
void Animal::Delete_Animal() // Удалить все записи из файла
{
	ofstream file;
	file.open("F:\\ТРПО\puhovkurs\RedBook.txt", ios::trunc); // открываем файл
	file.close();
	cout << endl << "Все записи удалены успешно." << endl;
};
//-----------------------------------------------------------------------------
void Animal::Delete_String() // Удалить конкретную запись из файла
{
	ifstream file;
	file.open("F:\\ТРПО\puhovkurs\RedBook.txt"); // Открытие файла

	if (!file)//проверка на открытие файла
	{
		cout << "Файл не открыт\n\n";
	}
	else
	{
		cout << "Файл открыт коректно!\n\n";
	}

	int s = 0; // Номер строки которую необходимо удалить
	int k = 0; // Счетчик строк
	string Line;
	string Line_File; // Хранение текста файла

	cout << "Введите номер строки для удаления: ";
	cin >> s;

	while (getline(file, Line))
	{
		k++;
		if (!(k == s))
		{
			Line_File.insert(Line_File.size(), Line); //дабавление строки
			Line_File.insert(Line_File.size(), "\r\n");	//добавление переноса на следующую строку
		}
	}

	file.close();
	std::ofstream file_out;
	file_out.open("F:\\ТРПО\puhovkurs\RedBook.txt", std::ios::trunc | std::ios::binary);
	file_out.write(Line_File.c_str(), Line_File.size());
	file_out.clear();
	cout << "Строка успешно удалена \n";
}
