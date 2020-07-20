#pragma once
#include <iostream> 

using namespace std;

inline void ClearCin()
{
	cin.clear();
	while (cin.get() != '\n');
}