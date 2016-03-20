#pragma once
#include "Item.h"
#include "World.h"
#include "Robot.h"
#include "Cell.h"
#include "Parse2.h"

#include "fileParse.h"


namespace Teamproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
				 this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick_1);
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
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load_1);
				 this->ResumeLayout(false);

			 }
#pragma endregion
			 Drawing::Icon^ robt = gcnew System::Drawing::Icon("robotleft.ico");
			 int numofCommands;
			 int comline = 0;
			 int worldHeight, worldWidth;
			 int cellWidth, cellHeight;
			 World^ world;
			 Robot^ robot;
			 fileParse *parse;
			 char **commands;
			 array <Cell^, 2>^ worl; 
			 moveparse *read;
			 Drawing::Icon ^ic;
			 Bitmap ^ b;




	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		g = panel1->CreateGraphics();
		/*grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);*/
		blackPen = gcnew System::Drawing::Pen(Color::Black);
		initalize();
		
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		
	}


			 // initalize all varibale form text file using fileParse object

public: System::Void initalize()
	{
		parse = new fileParse();

		commands = parse->parsingComs();
		numofCommands = parse->getnumberofCom();
		int args = 5;


		//loop to initlize wolrdWidth and wolrdHeight

		int u = 0;
			if (commands[u][0] == 'w')
			{
				 worldWidth = commands[u][1]-48 ;
				 worldHeight = commands[u][2]-48;
			}
	
		worl = gcnew array<Cell^, 2>(worldWidth, worldHeight);
		cellWidth = panel1->Width / worldWidth;
		cellHeight = panel1->Height / worldHeight;


		for (int q = 0; q < worldWidth; q++)
		{
			for (int k = 0; k < worldHeight; k++)
			{
				worl[q, k] = gcnew Cell(q, k);
			}
		}


		for (int i = 0; i < numofCommands ; i++)
		{
			for (int j = 0; j < args; j++)
			{
				if (commands[i][j] == 'e') {
					worl[commands[i][j + 1] - 48, commands[i][j + 2] - 48]->setWalls(commands[i][j + 3] - 48);
				}
				else if (commands[i][j] == 'b') {
					worl[commands[i][j + 1] - 48, commands[i][j + 2] - 48]->setBeeper(commands[i][j + 3] - 48);
				}
				else  if (commands[i][j] == 'r') {
					robot = gcnew Robot(commands[i][j + 1] - 48, commands[i][j + 2] - 48, commands[i][j + 3] - 48, commands[i][j + 4] - 48);
				}

			}
		}
		
	}



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
		void drawWorld() {
	
		//Declare local variables;
		//		int row, col;
		int x, y;

		//Refresh the panel
		panel1->Refresh();

		Drawing::Icon^ street = gcnew System::Drawing::Icon("street.ico");
		//Draw the empty maze
		for (int row = 0; row < worldHeight; row++)
		{
			for (int col = 0; col < worldWidth; col++)
			{
				x = col * cellWidth;
				y = row * cellHeight;
				Rectangle gridRect1 = Rectangle(x, y, cellWidth - 1, cellHeight - 1);
				g->DrawIcon(street, gridRect1);
				g->DrawRectangle(blackPen, gridRect1);
			
				
			
				
			}
			panel1->Refresh();
		}
	}
	private:
		System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e) {
			read = new moveparse();

			int h = read->getlines();
			array<Int32 ^> ^ com2 = gcnew array<Int32 ^>(h);
			
			for (int i = 0; i <h; i++)
			{
				com2[i] = read->readfile(i);
			}

		
		if (comline < h)
		{
			if (com2[comline] = 1)
			{
				switch (robot->getDirc()) {
				case 1:
					//not the top
					//Checks for wall ahead(up) or if the next cell behind(down) is open
					if (robot->getCol() != 0)
					{
						if (worl[robot->getRow(), robot->getCol()]->canmoveUp() &&
							worl[robot->getRow(), robot->getCol() - 1]->canmoveDown())
						{
							robot->move();
							comline++;
						}
					}
					break;

				case 2:
					//not at right side
					//Checks for wall to the right or if the next cell to the left is open
					if (robot->getRow() != worldWidth)
					{
						if (worl[robot->getRow(), robot->getCol()]->canmoveRight() &&
							worl[robot->getRow(), robot->getCol() + 1]->canmoveLeft())
						{
							robot->move();
							comline++;
						}
					}

					break;

				case 3:
					//not at bottom 
					//checks for wall behind(down) or if the cell ahead is open(up)
					if (robot->getCol() != worldHeight)
					{
						if (worl[robot->getRow(), robot->getCol()]->canmoveDown() &&
							worl[robot->getRow(), robot->getCol() + 1]->canmoveUp())
						{
							robot->move();
							comline++;
						}
					}
					break;

				case 4:
					//not at left side 
					//cheack for wall to the left or if the next cell to the right is open
					if (robot->getRow() != 0)
					{
						if (worl[robot->getRow(), robot->getCol()]->canmoveLeft() &&
							worl[robot->getRow(), robot->getCol() - 1]->canmoveRight())
						{
							robot->move();
							comline++;
						}
					}
					break;
				}
			}
			if (com2[comline] = 2)
			{
				robot->turnLeft();
				comline++;
			}
			if (com2[comline] =3)
			{
				if (worl[robot->getRow(), robot->getCol()]->getBeepers() > 0)
				{
					robot->pickBeeper();
					worl[robot->getRow(), robot->getCol()]->setBeeper
						(worl[robot->getRow(), robot->getCol()]->getBeepers() - 1);
				}
			}
			if (com2[comline] =4)
			{
				if (robot->getbeepercount() > 0)
				{
					robot->placeBeeper();
					worl[robot->getRow(), robot->getCol()]->setBeeper
						(worl[robot->getRow(), robot->getCol()]->getBeepers() + 1);
				}
			}
			if (com2[comline] =-1)
			{
				timer1->Stop();
			}



		}
		/*MessageBox::Show("Number of Beeper in Karel's Bag is" + robot->getbeepercount());*/
		
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
drawWorld();
	int x,y;
	x = robot->getRow() * cellWidth;
	y = robot->getCol() * cellHeight;

	

	Rectangle robotRect = Rectangle(x, y, cellWidth, cellHeight);
	g->DrawIcon(robt, robotRect);
	timer1->Start();

	
}
private: System::Void MyForm_Load_1(System::Object^  sender, System::EventArgs^  e) {
	g = panel1->CreateGraphics();
		

	blackPen = gcnew System::Drawing::Pen(Color::Black);
	initalize();

}
};
}