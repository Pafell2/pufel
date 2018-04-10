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

// В с++ методы доступа являются формальностью. Не существует жетского определения set и get. Любой член класса, возращающий значение private будет get

class Menu // Класс меню
{
private:
	int number;
public:
	void output_menu() // Функция вывода меню на экран
	{
		cout << "Меню программы \n\n";
		cout << "\n 1. Добавление записи в Красную книгу";
		cout << "\n 2. Вывод конкретной записи на экран";
		cout << "\n 3. Вывод всех записей на экран";
		cout << "\n 4. Удаление конкретной записи из файла";
		cout << "\n 5. Удаление всех записей из файла";
		cout << "\n 6. Выход из программы \n\n";
	}

	int choose_number() // Функция выбора паремтра меню
	{
		cout << "Введите параметр меню: "; cin >> number;
		return number;
	}

};
//==============================================================

//-----------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "russian");

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
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

		cout << "Еще раз? 1 - ДА / 0 - Нет: "; cin >> flag;
		cout << endl;

		if (flag == 0)exit(0);
	}

	system("pause");
	return 0;
}
