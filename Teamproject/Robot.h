#pragma once
#include "Item.h"


ref class Robot : public Item {

protected:
	static System::Drawing::Icon^ robotup;
	static System::Drawing::Icon^ robotright;
	static System::Drawing::Icon^ robotleft;
	static System::Drawing::Icon^ robotdown;
	int dir, beep, row, col;

public:
	Robot(int, int, int, int); //default constructor 
	System::Drawing::Icon^ Robot::getIcon() override;

	void Robot::setIcon() override;


	//Mutators
	void move();
	void turnLeft();
	void placeBeeper();
	void pickBeeper();

	//Accessors 
	int getRow();
	int getCol();
	int getbeepercount();
	int getDirc();


};