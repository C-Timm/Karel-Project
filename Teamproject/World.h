#pragma once
#include "Cell.h"
#include "Robot.h"


using namespace System;

ref class World
{
private:
	//Beeper^ myBeeper;
	Robot^ myRobot;
	array <Cell^, 2>^ grid;


public:
	//int wHeight, wWidth;
	//World()
	//{
	//	//Construct grid array
	//	grid = gcnew array<Cell^, 2>(wHeight, wWidth);
	//	for (int row = 0; row < wHeight; row++)
	//	{
	//		for (int col = 0; col < wWidth; col++)
	//		{
	//			grid[row, col] = gcnew Cell(row, col);
	//		}
	//	}
	//};
	////Beeper^ getBeeper() { return myBeeper; };
	//Robot^ getRobot() { return myRobot; };
	//array <Cell^, 2>^ getGrid() { return grid; };
};