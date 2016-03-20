#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

class moveparse {
private:
	int position;
	std::ifstream inputFile;
	/*const std::string FILENAME = "movecommands.txt";*///file name when we get one
	int numberofCom;
public:
	
	moveparse();
	int getlines();
	int readfile(int &);
	



};