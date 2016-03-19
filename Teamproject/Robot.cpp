#include "Robot.h"

Robot::Robot(int newDir, int newBeep, int newRow, int newCol) : Item(newRow, newCol)
{
	setIcon();
	dir = newDir;
	beep = newBeep;
	row = newRow;
	col = newCol;

}

void Robot::setIcon()
{

	robotup = gcnew System::Drawing::Icon("robotup.ico");
	robotright = gcnew System::Drawing::Icon("robotright.ico");
	robotleft = gcnew System::Drawing::Icon("robotleft.ico");
	robotdown = gcnew System::Drawing::Icon("robotDown.ico");
	icon = 0;

}
System::Drawing::Icon^ Robot::getIcon()
{

	if (icon == 0)
		return robotright;
	else if (icon == 1)
		return robotleft;
	else if (icon == 2)
	return robotup;
	else
		return robotdown;


}

void Robot::move()
{
	switch (dir)
	{
	case 1:
		col--;
		icon = 1;
		break;
	case 2:
		row++;
		icon = 3;
		break;
	case 3:
		col++;
		icon = 0;
		break;
	case 4:
		row--;
		icon = 2;
		break;
	}
}
void Robot::turnLeft()
{
	if (dir = 1)
		dir = 4;
	else
		dir--;
}

void Robot::placeBeeper()
{
	beep--;
}
void Robot::pickBeeper()
{
	beep++;
}
int Robot::getRow()
{
	return row;
}
int Robot::getCol()
{
	return col;
}
int Robot::getbeepercount()
{
	return beep;
}
int Robot::getDirc()
{
	return dir;
}