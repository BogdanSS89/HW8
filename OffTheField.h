#pragma once
#include <iostream>
using namespace std;
class OffTheField
{
private:
	string m_error;
public:
	OffTheField(string error);
	const char* getError();
};