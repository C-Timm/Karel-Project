#include "Parse2.h"


moveparse::moveparse() {
	numberofCom = getlines();
	
	
	array<char ^> ^ Moving = gcnew array<char ^>(numberofCom);


}
int moveparse::getlines()
{
	inputFile.open("movecommands.txt");
	int lines = 0; //hold number of lines
	std::string tempHolder;

	//Steps through file line by line
	while (getline(inputFile, tempHolder))
	{
		lines++;
	}

	inputFile.close();

	return lines;

}
int moveparse::readfile(int & l)
{

	numberofCom = getlines();
	int m;


	array<const char ^> ^ Moving = gcnew array<const char ^>(numberofCom);
	std::string currentLine; //buffer for reading lines and parsing
	std::string words[5];    //array of words of the current line
	std::string currentWord;
	inputFile.open("movecommands.txt");

	
	while (std::getline(inputFile, currentLine) && l < numberofCom)
	{
		std::transform(currentLine.begin(), currentLine.end(), currentLine.begin(), ::tolower);
		std::stringstream sstream(currentLine);
		int i = 0;

		while (sstream.good() && i < 5)
		{
			sstream >> words[i];
			i++;
		}
		currentWord = words[0];
		if (currentWord == "move")
		{
			m = 1;
			return m;
			
		}
		else if (currentWord == "left")
		{
			m = 2;
			return m;
			
		}
		else if (currentWord == "pick")
		{
			m = 3;
			return m;
			
		}
		else if (currentWord == "plac")
		{
			m = 4;
			return m;
			
		}
		else if (currentWord == "off")
		{
			m = -1;
			return m;
			
		}


		
		
	}
inputFile.close();
}