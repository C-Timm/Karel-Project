#pragma once
using namespace System::Drawing;
ref class Cell
{
private:
	//Date Memebers;
	int row;
	int col;
	int beeperCount;
	bool hasBeeper = false;
	bool moveUp = true;
	bool moveDown = true;
	bool moveLeft = true;
	bool moveRight = true;


public:

	//Initializing Constructor
	Cell(int, int);

	//Accessors 
	int getRow();
	int getCol();
	int getBeepers();


	//Mutators 
	void setWalls(int);
	void setBeeper(int);

	bool canmoveUp();
	bool canmoveRight();
	bool canmoveDown();
	bool canmoveLeft();

	void drawBox(Graphics^,Rectangle^, Icon^ico);
	void DrawCell(Graphics^, Rectangle^);
	void DrawWalls(Graphics^ ,Rectangle^);


};