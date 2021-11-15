#pragma once
#include <iostream>
using namespace std;
class IllegalCommand
{
private:
	string m_error;
public:
	IllegalCommand(string error);
	const char* getError();
};
