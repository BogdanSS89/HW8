#include "IllegalCommand.h"
using namespace std;
IllegalCommand::IllegalCommand(string error)
	:m_error(error)
{

}

const char* IllegalCommand::getError()
{
	return m_error.c_str();
}