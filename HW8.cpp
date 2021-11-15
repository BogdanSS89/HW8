#include <iostream>
#include <sstream>
#include "Ex.h"
#include "Bar.h"
#include "Robot.h"
using namespace std;
double numericValidation();

template < typename T >
const double& div(const T& num1, const T& num2)
{
    if (num2 == 0)
        throw "Division by zero!";
    return (num1 / num2);
}

double numericValidation()
{
    string userInput = "";

    int numCount = 0,
        floatCount = 0;
    double userConvertedNum;

    bool isIntNumber = false;
    bool isExit = false;

    do
    {
        cin >> userInput;
        if (userInput[0] == '#')
        {
            isExit = true;
            numCount = 0;
            break;
        }
        else
        {
            for (size_t i = 0; i < userInput.size(); i++)
            {
                if (isdigit(userInput[i]))
                {
                    numCount++;
                    isIntNumber = true;
                }
                else if (isalnum(userInput[i]))
                {
                    isIntNumber = false;
                    numCount = 0;
                    break;
                }
                if (userInput[i] == '.')
                {
                    numCount++;
                    floatCount++;
                    isIntNumber = true;
                }
            }
        }
        if (userInput[0] == '-')
        {
            numCount++;
            for (size_t i = numCount; i < userInput.size(); i++)
            {
                if (isdigit(userInput[i]))
                {
                    numCount++;
                    isIntNumber = true;
                }
                else if (isalnum(userInput[i]))
                {
                    isIntNumber = false;
                    numCount = 0;
                    break;
                }
                if (userInput[i] == '.')
                {
                    numCount++;
                    floatCount++;
                    isIntNumber = true;
                }
            }
        }
        if (floatCount > 1)
        {
            isIntNumber = false;
            numCount = 0;
            break;
        }
        if (numCount == userInput.size())
        {
            std::stringstream ssInput(userInput);
            ssInput >> userConvertedNum;
        }
        else
        {
            if (isIntNumber == false && numCount == 0)
               cout << "It's not a number!\nEnter the number (only digits without letters, symbols): "<<endl;
            else if (isExit == true)
                break;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            numCount = 0;
            isIntNumber = false;
        }

    } while (isIntNumber == false && isExit == false);

    if (isExit == true)
        userConvertedNum = 0;

    return  static_cast<double>(userConvertedNum);
}

int main()
{
#pragma region Task1
    double num1 = 0;
    double num2 = 0;
    double valueDiv = 0;

    cout << "Enter first number : " << endl;
    num1 = numericValidation();
    cout << "Enter second number : "<<endl;
    num2 = numericValidation();
    try
    {
        valueDiv = div(num1, num2);
        cout << "Division : " << valueDiv << endl;
    }
    catch (const char* message)
    {
        cout << message << endl;
    }

#pragma endregion

#pragma region Task2
    double n;
    Bar bar;

    try
    {
        do
        {
            cout << "Enter number : "<<endl;
            n = numericValidation();
            bar.setBar(n);
            cout << "y = " << bar.getBar() << endl;
        }         while (n != 0);

    }
    catch (Ex ex)
    {
        cout << "Error!"<<endl;
        cout << bar.getBar() << " + " << n << " > 100 , so " << bar.getBar() << " * " << n << " = " << ex.getEx() << endl;
    }
#pragma endregion

#pragma region Task3
    Robot robot;
    robot.robotMovement();

#pragma endregion

    return 0;
}
