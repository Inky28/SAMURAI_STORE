#pragma once
#include <string>
using namespace std;

class RegistrationData
{
public:
	virtual void Registration() = 0;
	virtual void WriteData(string data, string info) = 0;
};