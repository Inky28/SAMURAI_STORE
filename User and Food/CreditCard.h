#pragma once

#include <iostream>
#define SIZE_CARD 16
#define SIZE 3

using namespace std;

class CreditCard
{
private:
	char arrMonth[SIZE]{};
	char arrYear[SIZE]{};
	char arrCvv[SIZE + 1]{};
	char NumberCard[SIZE_CARD + 1]{};
public:
	void SetMonth(char arrMonth[]);
	void SetYear(char arrYear[]);
	void SetCvv(char arrCvv[]);
	void ADDnumberCard(char tempCard[]);
	void PrintAll();
	void SetOtherData();
	void ShowCreditCard();
	void SetNumberCard();
	bool CorrectCard(const char* NumberCard);
};