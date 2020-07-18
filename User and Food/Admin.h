#pragma once

#include <list>
#include <string>
//#include "Product.h"
#include "RegistrationData.h"
//#include "Database.h"

using namespace std;

class Admin :public RegistrationData
{
private:
	string name;
	string password;

public:

	string getName() const;

	void setPassword(string password);

	void setName(string name);

	string getPassword() const;

	void WriteData(string data, string info) override;

	void Registration() override;
};