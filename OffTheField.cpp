#include "OffTheField.h"
using namespace std;
OffTheField::OffTheField(string error)
	:m_error(error)
{

}

const char* OffTheField::getError()
{
	return m_error.c_str();
}