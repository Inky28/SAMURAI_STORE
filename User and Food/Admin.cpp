#include "Admin.h"
#include <iostream>
#include <fstream>
#define SIZE 256

string Admin::getName() const
{
	return this->name;
}

void Admin::setPassword(string password)
{
	if (!password.empty())
		this->password = password;
}

void Admin::setName(string name)
{
	if (!name.empty())
		this->name = name;
}

string Admin::getPassword() const
{
	return this->password;
}

void Admin::WriteData(string data, string info = "config")
{
	ofstream dataUser;

	dataUser.open(info + ".txt", ios::app);
	dataUser << data << endl;
	dataUser.close();
}

void Admin::Registration()
{
	const int SIZE_PASS = 64;
	//const int SIZE = 255;
	//string login;
	//char pass[SIZE];
	//char pass1[SIZE];

	ofstream loginSave;
	ofstream passSave;

	//ofstream emailSave;
	//ofstream numberSave;

	//ofstream dataUser;

	bool good = false;
	char temp[SIZE];
	string str;

	cout << "\tWelcome\n";

	//
	//cin.get();
	//system("cls");
	while (!good)
	{
		cout << "Enter name/login: ";
		cin.getline(temp, SIZE);
		str = temp;
		if (!str.empty())
		{
			setName(str);
			WriteData(str);
			//çàïèñóºìî ËÎÃ²Í
			/*loginSave.open("Login_User.txt", ios::app);
			loginSave << str << endl;
			loginSave.close();*/

			good = true;
		}
		system("cls");
	}
	good = false;

	while (!good)
	{
		cout << "Enter your pass (MAX 64 symbol): ";
		cin.getline(temp, SIZE_PASS);
		str = temp;
		if (!str.empty())
		{
			//system("cls");
			cout << "Enter again password: ";
			cin.getline(temp, SIZE_PASS);
			if (str == temp)
			{
				setPassword(str);
				//çàïèñóºìî ÏÀÐÎËÜ
				WriteData(str);
				/*passSave.open("Password_User.txt", ios::app);
				passSave << str << endl;
				passSave.close();*/
				good = true;
			}
			system("cls");
		}
	}
}
