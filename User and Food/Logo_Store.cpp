#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include "Color.h"
#include "Logo_Store.h"

HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);

void Space(size_t size)
{
	string step = " ";

	for (size_t i = 0; i < size; i++)
		cout << step;
}

void Loading(size_t time)
{
	for (int i = 1; i < 101; ++i)
	{
		cout << " Loading " << "\\\r" << i;
		/*for (size_t j = 0; j < i; j++)
		{
			cout << "#";
		}*/
		Sleep(time);
		cout << " Loading " << "|\r" << i;
		/*for (size_t j = 0; j < i; j++)
		{
			cout << "#";
		}*/
		Sleep(time);
		cout << " Loading " << "/\r" << i;
		/*for (size_t j = 0; j < i; j++)
		{
			cout << "#";
		}*/
		Sleep(time);
		cout << " Loading " << "-\r" << i;
		/*for (size_t j = 0; j < i; j++)
		{
			cout << "#";
		}*/
		Sleep(time);
	}
}

bool ShowLogo(const size_t SIZE)
{
	ifstream in("ninja_1.txt");					 //відкриємо файл для зчитування 
	string line;

	if (in.is_open())							//перевіряємо чи відкритий файл
	{
		if (SIZE % 3 == 0)
			cout << "\n\n";

		while (getline(in, line))			// зчитуємо по рядково з файлу IN в змінну LINE і виводимо по кожному рядку
		{
			Space(SIZE);
			cout << line << endl;			// виводимо по рядково
		}

		SetConsoleTextAttribute(hOUTPUT, RedFore);
		Space(SIZE);
		cout << "            ##        ###";
		SetConsoleTextAttribute(hOUTPUT, GrayFore);
		cout << "        ####   ##\n";

		in.close();

		ifstream in("ninja_2.txt");		//відкриємо файл для зчитування 

		while (getline(in, line))		// зчитуємо по рядково з файлу IN в змінну LINE і виводимо по кожному рядку
		{
			Space(SIZE);
			cout << line << endl;		// виводимо по рядково
		}

		in.close();
	}
	else
	{
		/*SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "ERROR. ";
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "File is empty\n";*/
		in.close();						// закриваємо файл
		return false;
	}
}

void ShowAnimationLogo()
{
	const size_t SIZE = 40;
	/*int choice;

	do
	{*/
	for (size_t i = 0; i < SIZE; i++)
	{
		if (!ShowLogo(i))
		{
			SetConsoleTextAttribute(hOUTPUT, RedFore);
			cout << "ERROR. ";
			SetConsoleTextAttribute(hOUTPUT, GrayFore);
			cout << "File is empty\n";
			break;
		}
		Sleep(150), system("cls");
	}

	ShowLogo(SIZE);

	SetConsoleTextAttribute(hOUTPUT, RedFore);
	cout << "  " << "\n\t\t\t GOODBYE  SAMURAI\n";
	SetConsoleTextAttribute(hOUTPUT, GrayFore);
	//	cout << "Try again ? 1 - yes ";
	//	cin >> choice;

	//} while (choice == 1);
}

void ShowLogoStore(size_t sleep, size_t color, size_t colorText)
{
	ifstream in("Color_logo.txt");					//відкриємо файл для зчитування 
	string line;

	if (in.is_open())								//перевіряємо чи відкритий файл
	{
		while (getline(in, line))					// зчитуємо по рядково з файлу IN в змінну LINE і виводимо по кожному рядку
		{
			SetConsoleTextAttribute(hOUTPUT, color);
			cout << "\t" << line << endl;			// виводимо по рядково
		}

		in.close();

		ifstream in("Text.txt");

		for (size_t i = 0; getline(in, line); i++)          // зчитуємо по рядково з файлу IN в змінну LINE і виводимо по кожному рядку
		{
			SetConsoleTextAttribute(hOUTPUT, color);
			i % 2 == 0 ? cout << "\t( " : cout << "\t )";

			/*if (i % 2 == 0)
				cout << "\t( ";

			else
				cout << "\t )";*/

			SetConsoleTextAttribute(hOUTPUT, colorText);//FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << line;			// виводимо по рядково
			//SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			SetConsoleTextAttribute(hOUTPUT, color);
			i % 2 == 0 ? cout << ")\n" : cout << "(\n";

			/*if (i % 2 == 0)
				cout << ")\n";
			else
				cout << "(\n";*/
		}

		cout << "\t'--------------------------------------------------------------------------------------------------'\n";
		SetConsoleTextAttribute(hOUTPUT, GrayFore);

		Sleep(sleep), system("cls");

		in.close();
	}
	else
	{
		SetConsoleTextAttribute(hOUTPUT, RedFore);
		cout << "ERROR. ";
		SetConsoleTextAttribute(hOUTPUT, WhiteFore);
		cout << "File is empty\n";
		in.close();						// закриваємо файл
	}
}

void ShowLogoStoreBlackAndWhite(size_t sleep)
{
	ifstream in("Logo_store_black.txt");					//відкриємо файл для зчитування 
	string line;

	if (in.is_open())								//перевіряємо чи відкритий файл
	{
		while (getline(in, line))					// зчитуємо по рядково з файлу IN в змінну LINE і виводимо по кожному рядку
			cout << "\t" << line << endl;			// виводимо по рядково

		in.close();
	}
	else
	{
		SetConsoleTextAttribute(hOUTPUT, RedFore);
		cout << "ERROR. ";
		SetConsoleTextAttribute(hOUTPUT, WhiteFore);
		cout << "File is empty\n";
		in.close();						// закриваємо файл
	}

	Sleep(sleep), system("cls");
}

void ShowLogoBasket()
{
	ifstream in("Basket.txt");						//відкриємо файл для зчитування 
	string line;

	if (in.is_open())								//перевіряємо чи відкритий файл
	{
		while (getline(in, line))					// зчитуємо по рядково з файлу IN в змінну LINE і виводимо по кожному рядку
		{
			SetConsoleTextAttribute(hOUTPUT, LimeFore);
			cout << "\t\t" << line << endl;			// виводимо по рядково
		}
		SetConsoleTextAttribute(hOUTPUT, GrayFore);
		in.close();

		SetConsoleTextAttribute(hOUTPUT, FuchsiaFore);
		cout << "\n\t\t\t\t\t\t WELCOME TO THE CART\n";
		SetConsoleTextAttribute(hOUTPUT, GrayFore);
		Sleep(4000), system("cls");				 // Час затримки
	}
	else
	{
		cout << "ERROR. File is empty\n";
		in.close();									// закриваємо файл
	}
}