#pragma once
#include <iostream> 

using namespace std;

void ClearCin()
{
	cin.clear();
	while (cin.get() != '\n');
}