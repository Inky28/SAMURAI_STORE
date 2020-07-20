#include "CreditCard.h"

#include <iostream>

//#define SIZE_CARD 16
//#define SIZE 3

using namespace std;

//const int SIZE_CARD = 16;
//const int SIZE = 3;

/*CreditCard(char arrMonth, char arrYear, char arrCvv, char NumberCard)
{
	this->arrMonth[SIZE] = arrMonth;
	this->arrYear[SIZE] = arrYear;
	this->arrCvv[SIZE + 1] = arrCvv;
	this->NumberCard[SIZE_CARD + 1] = NumberCard;
}*/
void CreditCard::SetMonth(char arrMonth[])
{
	for (size_t i = 0; i < SIZE; i++)
		this->arrMonth[i] = arrMonth[i];
}

void CreditCard::SetYear(char arrYear[])
{
	for (size_t i = 0; i < SIZE; i++)
		this->arrYear[i] = arrYear[i];
}

void CreditCard::SetCvv(char arrCvv[])
{
	for (size_t i = 0; i < SIZE + 1; i++)
		this->arrCvv[i] = arrCvv[i];
}

void CreditCard::ADDnumberCard(char tempCard[])
{
	for (size_t i = 0; i < SIZE_CARD; i++)
		this->NumberCard[i] = tempCard[i];
}

/*char GetMonth() const
{
	return this->arrMonth[SIZE];
}
char GetYear() const
{
	return this->arrYear[SIZE];
}

char GetCvv() const
{
	return this->arrCvv[SIZE + 1];
}*/

/*char GetCardNumber() const
{
	return this->NumberCard[SIZE_CARD + 1];
}*/

void CreditCard::PrintAll()
{
	cout << "\nMonth: ";
	for (size_t i = 0; i < SIZE; i++)
		cout << arrMonth[i];
	cout << "\nYear: ";
	for (size_t i = 0; i < SIZE; i++)
		cout << arrYear[i];
	cout << "\nCVV: ";
	for (size_t i = 0; i < SIZE + 1; i++)
		cout << arrCvv[i];
	cout << endl;
}

void CreditCard::SetOtherData()
{
	bool exit = true;
	char arrMonth[SIZE]{};
	char arrYear[SIZE]{};
	char arrCvv[SIZE + 1]{};

	do
	{
		char choice;

		cout << "Enter month: ";
		cin >> arrMonth;

		cout << "Enter year: ";
		cin >> arrYear;

		cout << "Enter CVV: ";
		cin >> arrCvv;

		if (strlen(arrMonth) > 2 || strlen(arrMonth) <= 1 || strlen(arrYear) > 2 ||
			strlen(arrYear) <= 1 || strlen(arrCvv) > 3 || strlen(arrCvv) <= 2)
			cout << "Incorrect input. Please try again\n";
		else if (arrMonth[0] >= '2' || arrMonth[0] == '1' && arrMonth[1] > '2')			// Ã≤—ﬂ÷‹
			cout << "Incorrect month. Please try again\n";
		else if (arrYear[0] < '2' || arrYear[0] >= '3')									// –≤ 
			cout << "Incorrect year. Please try again\n";
		else
			exit = false;

		if (!exit)
		{
			cout << "Month\\Year :\t" << arrMonth << "\\" << arrYear << endl;
			cout << "CVV : \t\t" << arrCvv << endl;

			cout << "The data is correct ? Enter Y\\y: ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
				exit = false;
			else
				exit = true;
			cin.clear();
			while (cin.get() != '\n');
		}

	} while (exit);

	SetMonth(arrMonth);
	SetYear(arrYear);
	SetCvv(arrCvv);
}

void CreditCard::ShowCreditCard()
{
	cout << "Your card number : ";
	for (size_t i = 0; i < SIZE_CARD; i++)
	{
		cout << NumberCard[i];

		if (i == 3 || i == 7 || i == 11)
			cout << " ";
	}
	cout << endl;
}

void CreditCard::SetNumberCard()
{
	bool exit = true;

	char tempCard[SIZE_CARD + 1];

	do
	{
		cout << "Enter YOUR card number (16 characters)\n";
		cin.getline(tempCard, SIZE_CARD + 1);

		cin.clear();
		while (cin.get() != '\n');

		tempCard[SIZE_CARD] = '\0';

		for (size_t i = 0; i < SIZE_CARD; i++)
		{
			if (tempCard[i] >= 0 && !(tempCard[i] > ':') && !(tempCard[i] < '/'))
			{
				if (i == SIZE_CARD - 1)
					exit = false;
			}
			else
			{
				cout << "Incorrect input. Please try again\n";

				cin.clear();
				while (cin.get() != '\n');

				break;
			}
		}
		if (!exit)
		{
			if (!CorrectCard(tempCard))
			{
				cout << "You have problems with the card\n";
				cout << "Please try again\n";
				exit = true;
			}
			/*else
				cout << "All is well with your card\n";*/
		}
	} while (exit);

	ADDnumberCard(tempCard);
}

bool CreditCard::CorrectCard(const char* NumberCard)
{
	int Sum = 0;
	int Size = strlen(NumberCard);
	int Parity = (Size - 1) % 2;
	char ZeroSymb[2] = "\0";

	for (int i = Size; i > 0; i--)
	{
		ZeroSymb[0] = NumberCard[i - 1];
		int Digit = atoi(ZeroSymb);

		if (Parity == i % 2)
			Digit = Digit * 2;

		Sum += Digit / 10;
		Sum += Digit % 10;
	}
	return 0 == Sum % 10;
}