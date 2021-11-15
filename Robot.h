#pragma once
#include "OffTheField.h"
#include "IllegalCommand.h"
#include <iostream>
using namespace std;
class Robot
{
private:
	const int iN = 10;
	string** ptrArr;
	string robotDown = "\\['-']/";
	string robotUp = " \\[ ]/ ";
	string robotLeft = "\\['-'\\]";
	string robotRight = "[/'-']/";
	string robotError = "\\['o']/";
	string robotIllegal = "/[-_-]\\";
	string robot = "~[^-^]~";
	bool isRobotOver;

	struct Position
	{
		int x,
			y;
	};

	enum class eDirection
	{
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

public:
	eDirection route;
	Position pos;
	Robot();
	void printField();
	void robotMovement();
	void Input();
	void Logic();
	void ClearScreen();
	~Robot();
};

