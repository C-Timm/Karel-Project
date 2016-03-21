#pragma once
#include "Item.h"
#include "World.h"
#include "Robot.h"
#include "Cell.h"
#include "Parse2.h"

#include "fileParse.h"
#include "fstream"

namespace Teamproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		Graphics^ g;
		Brush^ grayBrush;
		Brush^ whiteBrush;

		Brush^ paleTurquoiseBrush;

		Pen^ blackPen;



	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::ComponentModel::IContainer^  components;


			 /// <summary>
			 /// Required designer variable.
			 /// </summary>


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Interval = 1000;
				 this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(220, 409);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(188, 23);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"button1";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // panel1
				 // 
				 this->panel1->Location = System::Drawing::Point(125, 3);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(400, 400);
				 this->panel1->TabIndex = 2;
				 // 
				 // MyForm
				 // 
				 this->ClientSize = System::Drawing::Size(736, 427);
				 this->Controls->Add(this->panel1);
				 this->Controls->Add(this->button1);
				 this->Name = L"MyForm";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->ResumeLayout(false);

			 }
#pragma endregion
			 Drawing::Icon^ robt = gcnew System::Drawing::Icon("robotleft.ico");
			 int numofCommands;
			 int comline = 0;
			 int worldHeight, worldWidth;
			 int cellWidth, cellHeight;
			 Robot^ robot;
			 Graphics^ di;
			 moveparse *read;
			 Drawing::Icon ^ic;
			 Bitmap ^ b;
			 Pen ^ pen;


			 static System::Drawing::Icon^ robotup;
			 static System::Drawing::Icon^ robotright;
			 static System::Drawing::Icon^ robotleft;
			 static System::Drawing::Icon^ robotdown;


	private: System::Void MyForm_Load_1(System::Object^  sender, System::EventArgs^  e) {


		//g = panel1->CreateGraphics();
		///*grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);*/
		//blackPen = gcnew System::Drawing::Pen(Color::Black);

		//string parse;
		//string p2;
		//int r, c;
		//int	r1, c1, bN;
		//int r2, c2, bN1, d;
		//int r3, c3, n;
		//fstream infile;
		//infile.open("commands.txt");
		//infile >> parse;

		//if (parse == "world")
		//{
		//	infile >> r;
		//	infile >> c;
		//	drawWorld(r, c);
		//}
		//if (parse == "beepers")
		//{
		//	infile >> r1;
		//	infile >> c1;
		//	infile >> bN;
		//	drawBeeper(r1, r2, bN);

		//}

		//if (parse == " Robot")
		//{
		//	infile >> r2;
		//	infile >> c2;
		//	infile >> bN1;
		//	infile >> d;
		//	drawRobot(r2, c2, bN1, d);

		//}
		//if (parse == " wall")
		//{
		//	infile >> r3;
		//	infile >> c3;
		//	infile >> n;
		//	drawWalls(r3, c3, n);
		//}


	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	}


			 // initalize all varibale form text file using fileParse object





	//private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//	//creating robot, using cheese icon as placeholder
	//	int x, y;
	//	Drawing::Icon^ beeper = gcnew System::Drawing::Icon("beeper.ico");


	//	int robotRow = 3;
	//	int robotCol = 3;

	//	//direction = 'r';

	//	x = robotCol * CELLSIZE;
	//	y = robotRow * CELLSIZE;				   
	//	Rectangle beeperRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
	//	g->DrawIcon(beeper, beeperRect);

	//	//world->getRobot()->MoveTo(robotRow, robotCol);

	//	x = robotCol * CELLSIZE;
	//	y = robotRow * CELLSIZE;
	//	Rectangle robotRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
	//	g->DrawIcon(world->getRobot()->getIcon(), robotRect);

	//	drawWorld();
	//}

	private:
		void drawWorld(int r, int c) {

			//Declare local variables;
			//		int row, col;
			int x, y;
			cellWidth = panel1->Width / c;
			cellHeight = panel1->Height / r;
			//Refresh the panel
			panel1->Refresh();

			Drawing::Icon^ street = gcnew System::Drawing::Icon("street.ico");
			//Draw the empty maze
			for (int row = 0; row < r; row++)
			{
				for (int col = 0; col < c; col++)
				{
					x = col * cellWidth;
					y = row * cellHeight;
					Rectangle gridRect1 = Rectangle(x, y, cellHeight - 1, cellWidth - 1);
					g->DrawIcon(street, gridRect1);
					g->DrawRectangle(blackPen, gridRect1);




				}
				/*panel1->Refresh();*/
			}
		}
		private: void drawMove(int r2, int c2, int bN1, int d, int r, int c) {
			int x, y;
			cellWidth = panel1->Width / r;
			cellHeight = panel1->Height / c;
			Drawing::Icon^ street = gcnew System::Drawing::Icon("street.ico");
			
			/*Drawing::Icon^ robot = gcnew System::Drawing::Icon("beeper.ico");*/
			//Draw the empty maze



			int icon = d;


			x = r2 * 50;
			y = c2 * 50;
			Rectangle roborect = Rectangle(x, y, cellHeight - 1, cellWidth - 1);

			g->DrawIcon(street, roborect);

			/*g->DrawIcon(robot, beeprect);*/
			/*g->DrawIcon(y,roborect );*/


		}
	private: void drawRobot(int r2, int c2, int bN1, int d, int r, int c) {
		int x, y;
		cellWidth = panel1->Width / r;
		cellHeight = panel1->Height / c;
		Drawing::Icon^ up = gcnew System::Drawing::Icon("robotup.ico");
		Drawing::Icon^ left = gcnew System::Drawing::Icon("robotleft.ico");
		Drawing::Icon^ right = gcnew System::Drawing::Icon("robotright.ico");
		Drawing::Icon^ down = gcnew System::Drawing::Icon("robotdown.ico");
		/*Drawing::Icon^ robot = gcnew System::Drawing::Icon("beeper.ico");*/
		//Draw the empty maze



		int icon = d;


		x = r2 * 50;
		y = c2 * 50;
		Rectangle roborect = Rectangle(x, y, cellHeight - 1, cellWidth - 1);

		if (icon == 1)
		{
			g->DrawIcon(up, roborect);
		}

		else if (icon == 2)
		{
			g->DrawIcon(right, roborect);
		}

		else if (icon == 3)
		{
			g->DrawIcon(down, roborect);
		}
		else
		{
			g->DrawIcon(left, roborect);
		}

		/*g->DrawIcon(robot, beeprect);*/
		/*g->DrawIcon(y,roborect );*/


	}
	private: void drawBeeper(int r1, int c1, int bN, int r, int c) {
		int x, y;
		cellWidth = panel1->Width / r;
		cellHeight = panel1->Height / c;

		Drawing::Icon^ beeper = gcnew System::Drawing::Icon("beeper.ico");
		//Draw the empty maze

		x = r1 * 50;
		y = c1 * 50;
		Rectangle beeprect = Rectangle(x, y, cellHeight - 1, cellWidth - 1);
		g->DrawIcon(beeper, beeprect);
		/*g->DrawRectangle(blackPen, beeprect);*/


	}
	private: void drawWalls(int r3, int c3, int n, int r, int c) {
		int x, y;
		cellWidth = panel1->Width / r;
		cellHeight = panel1->Height / c;
		Pen^ pen = gcnew Pen(Color::Black);
		x = r3 * 50;
		y = c3 * 50;
		Point p1 = Point(x, y);
		if (n == 1)
		{

			x = c3* cellWidth;
			y = r3* cellHeight;
			int x1 = (c3*cellWidth) + cellWidth;
			int y1 = (r3*cellHeight);
			Point p1 = Point(x, y);
			Point p2 = Point(x1, y1);
			g->DrawLine(pen, p1, p2);

		}
		else if (n == 2)
		{
			int x2 = (c3*cellWidth) + cellWidth;
			int y2 = (r3*cellHeight);
			int x3 = (c3* cellWidth) + cellWidth;
			int y3 = (r3* cellHeight) + cellHeight;
			Point  p3 = Point(x2, y2);
			Point p4 = Point(x3, y3);
			g->DrawLine(pen, p3, p4);
		}
		else if (n == 3)
		{
			int x4 = c3* cellWidth;
			int y4 = (r3*cellHeight) + cellHeight;
			int x5 = (c3* cellWidth) + cellWidth;
			int y5 = (r3* cellHeight) + cellHeight;
			Point  p5 = Point(x4, y4);
			Point p6 = Point(x5, y5);
			g->DrawLine(pen, p5, p6);
		}
		else
		{
			int x6 = c3* cellWidth;
			int	y6 = r3* cellHeight;
			int x7 = c3* cellWidth;
			int y7 = (r3*cellHeight) + cellHeight;
			Point  p7 = Point(x6, y6);
			Point p8 = Point(x7, y7);


			g->DrawLine(pen, p7, p8);
		}


	}





			 //			 }
			 //	private:
			 //		System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e) {
			 //			read = new moveparse();
			 //
			 //			int h = read->getlines();
			 //			array<Int32 ^> ^ com2 = gcnew array<Int32 ^>(h);
			 //			
			 //			for (int i = 0; i <h; i++)
			 //			{
			 //				com2[i] = read->readfile(i);
			 //			}
			 //
			 //		
			 //		if (comline < h)
			 //		{
			 //			if (com2[comline] = 1)
			 //			{
			 //				switch (robot->getDirc()) {
			 //				case 1:
			 //					//not the top
			 //					//Checks for wall ahead(up) or if the next cell behind(down) is open
			 //					if (robot->getCol() != 0)
			 //					{
			 //						if (worl[robot->getRow(), robot->getCol()]->canmoveUp() &&
			 //							worl[robot->getRow(), robot->getCol() - 1]->canmoveDown())
			 //						{
			 //							robot->move();
			 //							comline++;
			 //						}
			 //					}
			 //					break;
			 //
			 //				case 2:
			 //					//not at right side
			 //					//Checks for wall to the right or if the next cell to the left is open
			 //					if (robot->getRow() != worldWidth)
			 //					{
			 //						if (worl[robot->getRow(), robot->getCol()]->canmoveRight() &&
			 //							worl[robot->getRow(), robot->getCol() + 1]->canmoveLeft())
			 //						{
			 //							robot->move();
			 //							comline++;
			 //						}
			 //					}
			 //
			 //					break;
			 //
			 //				case 3:
			 //					//not at bottom 
			 //					//checks for wall behind(down) or if the cell ahead is open(up)
			 //					if (robot->getCol() != worldHeight)
			 //					{
			 //						if (worl[robot->getRow(), robot->getCol()]->canmoveDown() &&
			 //							worl[robot->getRow(), robot->getCol() + 1]->canmoveUp())
			 //						{
			 //							robot->move();
			 //							comline++;
			 //						}
			 //					}
			 //					break;
			 //
			 //				case 4:
			 //					//not at left side 
			 //					//cheack for wall to the left or if the next cell to the right is open
			 //					if (robot->getRow() != 0)
			 //					{
			 //						if (worl[robot->getRow(), robot->getCol()]->canmoveLeft() &&
			 //							worl[robot->getRow(), robot->getCol() - 1]->canmoveRight())
			 //						{
			 //							robot->move();
			 //							comline++;
			 //						}
			 //					}
			 //					break;
			 //				}
			 //			}
			 //			if (com2[comline] = 2)
			 //			{
			 //				robot->turnLeft();
			 //				comline++;
			 //			}
			 //			if (com2[comline] =3)
			 //			{
			 //				if (worl[robot->getRow(), robot->getCol()]->getBeepers() > 0)
			 //				{
			 //					robot->pickBeeper();
			 //					worl[robot->getRow(), robot->getCol()]->setBeeper
			 //						(worl[robot->getRow(), robot->getCol()]->getBeepers() - 1);
			 //				}
			 //			}
			 //			if (com2[comline] =4)
			 //			{
			 //				if (robot->getbeepercount() > 0)
			 //				{
			 //					robot->placeBeeper();
			 //					worl[robot->getRow(), robot->getCol()]->setBeeper
			 //						(worl[robot->getRow(), robot->getCol()]->getBeepers() + 1);
			 //				}
			 //			}
			 //			if (com2[comline] =-1)
			 //			{
			 //				timer1->Stop();
			 //			}
			 //
			 //
			 //
			 //		}
			 //		/*MessageBox::Show("Number of Beeper in Karel's Bag is" + robot->getbeepercount());*/
			 //		
			 //	}
			 //
			 //private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 //drawWorld();
			 //	int x,y;
			 //	x = robot->getRow() * cellWidth;
			 //	y = robot->getCol() * cellHeight;
			 //
			 //	
			 //
			 //	Rectangle robotRect = Rectangle(x, y, cellWidth, cellHeight);
			 //	g->DrawIcon(robt, robotRect);
			 //	timer1->Start();
			 //
			 //	
			 //}


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
			 //g = panel1->CreateGraphics();
			 ///*grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);*/
			 //blackPen = gcnew System::Drawing::Pen(Color::Black);

			 //string parse;
			 //string p2;
			 //int r, c;
			 //int	r1, c1, bN;
			 //int r2, c2, bN1, d;
			 //int r3, c3, n;
			 //fstream infile;
			 //infile.open("commands.txt");
			 //


			 //while (infile.eof() != true)
			 //{  
			 //	infile >> parse;
			 //	if (parse == "world")
			 //	{
			 //		infile >> r;
			 //		infile >> c;
			 //		/*drawWorld(r, c);*/
			 //	}
			 //	if (parse == "beepers")
			 //	{
			 //		infile >> r1;
			 //		infile >> c1;
			 //		infile >> bN;
			 //		drawBeeper(r1, c1, bN);

			 //	}

			 //	if (parse == "robot")
			 //	{
			 //		infile >> r2;
			 //		infile >> c2;
			 //		infile >> bN1;
			 //		infile >> d;
			 //		drawRobot(r2, c2, bN1, d);

			 //	}
			 //	if (parse == " wall")
			 //	{
			 //		infile >> r3;
			 //		infile >> c3;
			 //		infile >> n;
			 //		drawWalls(r3, c3, n);
			 //	}



			 //}
			 int globr, globc,globr2, globc2,globd,globeep;
			 void parseFile() {
				 Cell^ cell;
				 g = panel1->CreateGraphics();
				 /*grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);*/
				 blackPen = gcnew System::Drawing::Pen(Color::LightGray);

				 string parse;
				 string p2;
				 int r, c;
				 int	r1, c1, bN;
				 int r2, c2, bN1, d;
				 int r3, c3, n;

				 fstream infile;
				 infile.open("commands.txt");



				 while (infile.eof() != true)
				 {
					 infile >> parse;
					 if (parse == "world")
					 {
						 infile >> r;
						 infile >> c;
						 globr = r;
						 globc = c;
						 drawWorld(r, c);
					 }
					 if (parse == "beepers")
					 {
						 infile >> r1;
						 infile >> c1;
						 infile >> bN;
						 drawBeeper(r1, c1, bN, r, c);

					 }

					 if (parse == "robot")
					 {
						 infile >> r2;
						 infile >> c2;
						 infile >> bN1;
						 infile >> d;
						 globr2 = r2;
						 globc2 = c2;
						 globeep = bN1;
						 globd = d;
						 drawRobot(r2, c2, bN1, d, r, c);

					 }
					 if (parse == "wall")
					 {
						 infile >> r3;
						 infile >> c3;
						 infile >> n;
						 drawWalls(r3, c3, n, r, c);
					 }
					 /*switch (robot->getDirc()) {*/
					 //				case 1:
					 //					//not the top
					 //					//Checks for wall ahead(up) or if the next cell behind(down) is open
					 //					if (robot->getCol() != 0)
					 //					{
					 //						if (worl[robot->getRow(), robot->getCol()]->canmoveUp() &&
					 //							worl[robot->getRow(), robot->getCol() - 1]->canmoveDown())
					 //						{
					 //							robot->move();
					 //							comline++;
					 //						}
					 //					}
					 //					break;
					 //
					 //				case 2:
					 //					//not at right side
					 //					//Checks for wall to the right or if the next cell to the left is open
					 //					if (robot->getRow() != worldWidth)
					 //					{
					 //						if (worl[robot->getRow(), robot->getCol()]->canmoveRight() &&
					 //							worl[robot->getRow(), robot->getCol() + 1]->canmoveLeft())
					 //						{
					 //							robot->move();

				 }
			 }
				 void parse2(string p2)
				 {
					 
					 /*array<string>^ movArray;*/
					 /*movArray = gcnew array<string>(100);*/
					 string parse;
					 string p23;
					 

					 fstream infile;
					 infile.open("MoveCommands2.txt");
						 infile >> p2;
						 
						 if (p2 == "move")
						 {

							 if (globd == 1)
							 {
								 drawMove(globr2, globc2, globeep, globd, globr, globc);
								 globc2--;
								 drawRobot(globr2, globc2, globeep, globd, globr, globc);
							 }
							 else if (globd == 2)
							 {
								 drawMove(globr2, globc2, globeep, globd, globr, globc);
								 globr2++;
								 drawRobot(globr2, globc2, globeep, globd, globr, globc);
							 }
							 else if (globd == 3)
							 {
								 drawMove(globr2, globc2, globeep, globd, globr, globc);
								 globc2++;
								 drawRobot(globr2, globc2, globeep, globd, globr, globc);
							 }
							 else
							 {
								 drawMove(globr2, globc2, globeep, globd, globr, globc);
								 globr2--;
								 drawRobot(globr2, globc2, globeep, globd, globr, globc);
							 }

						 
					 }
					 if (p2 == "turnoff")
					 {
						 infile.eof();
						 timer1->Stop();
					 }
					 /*
					 if (parse == "pickbeeper")
					 {
					 infile >> r3;
					 infile >> c3;
					 infile >> n;
					 drawWalls(r3, c3, n, r, c);
					 }
					 if (parse == "placebeeper")
					 {
					 infile >> r3;
					 infile >> c3;
					 infile >> n;
					 drawWalls(r3, c3, n, r, c);
					 }*/



				 }
			 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Start();
		parseFile();
		



		



	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		string parse;
		string p2;


		fstream infile;
		infile.open("MoveCommands2.txt");
		parse2(p2);

	}
};
}