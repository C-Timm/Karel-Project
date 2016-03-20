#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


class fileParse {

private:
	char **comArray;
	
	//array that holds the number of commands from the file
	std::ifstream inputFile;
	const std::string FILENAME = "commands2.txt";//file name when we get one
	int numberofCom;


public:
	fileParse();
	int getNumLines(); //gets number of line is file
	char **parsingComs(); //parse through file and stores commands
	int getnumberofCom(); //gets the number of commands


};