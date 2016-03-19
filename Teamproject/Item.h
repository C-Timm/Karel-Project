#pragma once


ref class Item abstract
{
protected:
	int row;
	int col;
	int icon;


public:
	Item(void) {};
public:
	Item(int newRow, int newCol)
	{
		if (newRow >= 0)
			row = newRow;
		if (newCol >= 0)
			col = newCol;
	};


	int getRow()
	{
		return row;
	}
	int getCol()
	{
		return col;
	}
	virtual System::Drawing::Icon^ getIcon() = 0;
	virtual void setIcon() = 0;


	void setCol(int newCol)
	{
		row = newCol;
	}
	void setRow(int newRow)
	{
		row = newRow;
	}


	void moveTo(int newRow, int newCol)
	{
		setRow(newRow);
		setCol(newCol);

	};


};