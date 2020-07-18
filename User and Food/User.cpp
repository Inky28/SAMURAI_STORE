#include "User.h"
#include "Logo_Store.h"
#include <iostream>
#include <fstream>
#define SIZE 256

void User:: WriteData(string data, string info)
{
	ofstream dataUser;

	dataUser.open(getName() + ".txt", ios::app);
	if (info == "Password")
		dataUser << info + ": " << data << endl;
	else
		dataUser << info + "\t: " << data << endl;
	dataUser.close();
}

void User::Registration()
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
			WriteData(str, "Name");
			//записуємо ЛОГІН
			loginSave.open("Login_User.txt", ios::app);
			loginSave << str << endl;
			loginSave.close();

			good = true;
		}
		system("cls");
	}
	good = false;
	//
	while (!good)
	{
		cout << "Enter mail: ";
		cin.getline(temp, SIZE);
		str = temp;
		if (!str.empty())
		{
			setEmail(str);
			WriteData(str, "Email");
			/*emailSave.open("Login_Email.txt", ios::app);
			emailSave << temp << endl;
			emailSave.close();*/
			good = true;
		}
		system("cls");
	}
	good = false;
	//
	while (!good)
	{
		cout << "Enter number: ";
		cin.getline(temp, SIZE);
		str = temp;
		if (!str.empty())
		{
			setNumber(str);
			WriteData(str, "Number");
			/*numberSave.open("Login_Number.txt", ios::app);
			numberSave << temp << endl;
			numberSave.close();*/
			good = true;
		}
		system("cls");
	}
	//
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
				WriteData(str, "Password");
				//записуємо ПАРОЛЬ
				passSave.open("Password_User.txt", ios::app);
				passSave << str << endl;
				passSave.close();
				good = true;
			}
			system("cls");
		}
	}

	///////////////////////other

	//cout << "Enter your login: ";
	//cin >> login;

	//loginSave.open("Login.txt", ios::app);	// відкрити для запису в кінець (не перезаписується)

	//loginSave << login << endl;
	//loginSave.close();

	//cin.clear();
	//while (cin.get() != '\n');

	//do
	//{
	//	cout << "Enter your pass (MAX 64 symbol): ";
	//	cin.getline(pass, SIZE);
	//	cout << "Enter again password: ";
	//	cin.getline(pass1, SIZE);

	//	if (strcmp(pass1, pass))
	//		cout << "Passwords do not match\n";
	//	else
	//		cout << "Passwords saved\n";

	//} while (strcmp(pass1, pass));

	//passSave.open("Password.txt", ios::app);
	//passSave << pass << endl;
	//passSave.close();
}

//void User::Registration()
//{
//	bool good = false;
//	char temp[SIZE];
//	string str;
//
//	cin.get();
//	system("cls");
//	while (!good)
//	{
//		cout << "Enter name: ";
//		cin.getline(temp, SIZE);
//		str = temp;
//		if (!str.empty())
//		{
//			setName(str);
//			good = true;
//		}
//		system("cls");
//	}
//	good = false;
//
//	while (!good)
//	{
//		cout << "Enter mail: ";
//		cin.getline(temp, SIZE);
//		str = temp;
//		if (!str.empty())
//		{
//			setEmail(str);
//			good = true;
//		}
//		system("cls");
//	}
//
//	good = false;
//	while (!good)
//	{
//		cout << "Enter number: ";
//		cin.getline(temp, SIZE);
//		str = temp;
//		if (!str.empty())
//		{
//			setNumber(str);
//			good = true;
//		}
//		system("cls");
//	}
//
//	good = false;
//	while (!good)
//	{
//		cout << "Enter password: ";
//		cin.getline(temp, SIZE);
//		str = temp;
//		if (!str.empty())
//		{
//			system("cls");
//			cout << "Enter password one more time: ";
//			cin.getline(temp, SIZE);
//			if (str == temp)
//			{
//				setPassword(str);
//				good = true;
//			}
//			system("cls");
//		}
//	}
//}

bool User::Login(string name, string password)
{
	// ФІКСИТИ
	if (this->name == name && this->password == password)
		return true;
	return false;
}

void User::putCash()
{
	float temp;
	bool ok = false;

	cin.get();
	system("cls");
	while (!ok)
	{
		cout << "Enter cash to put: ";
		cin >> temp;
		if (temp > 0)
		{
			setCash(temp + getCash());
			ok = true;
		}
		system("cls");
	}
}

bool User::buy(Product& myProduct)
{
	if (this->cash >= myProduct.getPrice() && myProduct.getCount() > 0)
	{
		myProduct--;
		inventory.push_back(myProduct);
		setCash(cash - myProduct.getPrice());
		return true;
	}
	return false;
}

void User::printInventory() const
{
	cout << "\tInventory\n\n";
	for (Product item : inventory)
		item.print();

	system("pause");
	system("cls");
}

void User::menu(list<Product>& products)
{
	bool exit = false;
	int choice;

	do
	{
		system("cls");

		cout << "\tUSER_MENU\n\n";
		cout << "1. Info\n";
		cout << "2. Put cash\n";
		cout << "3. Buy product\n";
		cout << "4. Show my inventory\n";
		cout << "0. Exit\n";
		cout << "Enter: ";
		cin >> choice;

		system("cls");
		switch (choice)
		{
		case 0:
			return;
		case 1:
			print();
			break;
		case 2:
			putCash();
			break;
		case 3:
			char otherChoice;
			for (Product item : products)
			{
				item.print();
				cout << "Buy this? [Y/N]: ";
				cin >> otherChoice;
				switch (otherChoice)
				{
				case 'Y': case 'y':
					buy(item);
					break;
				}
				system("cls");
			}
			break;

		case 4:
			ShowLogoBasket();  	// Logo Basket
			printInventory();
			break;
		}
	} while (!exit);
}



void User::print() const
{
	system("cls");

	cout << "\tInformation\n\n";
	cout << "Name:   " << this->name << endl;
	cout << "Mail:  " << this->email << endl;
	cout << "Number: " << this->number << endl;
	cout << "Cash:   " << this->cash << endl;
	cout << "\n===========\n";

	system("pause");
	system("cls");
}

User::User()
{
	name = "";
	email = "";
	number = "";
	password = "";
	cash = 0;
}

string User::getName() const
{
	return this->name;
}

string User::getEmail() const
{
	return this->email;
}

string User::getNumber() const
{
	return this->number;
}

string User::getPassword() const
{
	return this->password;
}

float User::getCash() const
{
	return this->cash;
}

void User::setName(string name)
{
	if (!name.empty())
		this->name = name;
}

void User::setEmail(string email)
{
	if (!email.empty())
		this->email = email;
}

void User::setNumber(string number)
{
	if (!number.empty())
		this->number = number;
}

void User::setPassword(string password)
{
	if (!password.empty())
		this->password = password;
}

void User::setCash(float cash)
{
	if (cash > 0)
		this->cash = cash;
}
