#include "fileParse.h"


fileParse::fileParse()
{
	//finds number of lines in the file
	numberofCom = getNumLines();
	/*array<char^, 2> ^ comArray = gcnew array<char^, 2>(numberofCom, 5);*/
	//initialize array 
	comArray = new char*[numberofCom];
	//add loop
	for (int i = 0; i < numberofCom; i++)
	{
		comArray[i] = new char[5];
	}

}

int fileParse::getNumLines()
{
	inputFile.open(FILENAME);
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
int fileParse::getnumberofCom()
{
	return numberofCom;
}

char** fileParse::parsingComs()
{
	/*array<char^, 2> ^ comArray = gcnew array<char^, 2>(numberofCom, 5);*/
	std::string currentLine; //buffer for reading lines and parsing
	std::string words[5];    //array of words of the current line
	std::string currentWord;
	inputFile.open(FILENAME);

	int l = 0;
	while (std::getline(inputFile, currentLine))
	{
		std::transform(currentLine.begin(), currentLine.end(), currentLine.begin(), ::tolower);
		std::stringstream sstream(currentLine);
		int i = 0;

		while (sstream.good() && i <5)
		{
			sstream >> words[i];
			i++;
		}
		//different command options

		/* word, beepers, wall, robot,
		move, turn, turn left,
		pick beeper, place beeper
		and turn off
		*/

		currentWord = words[0];
		if (currentWord == "wor")
		{
			comArray[l][0] = words[0][0];
			comArray[l][1] = words[1][0];
			comArray[l][2] = words[2][0];
		}
		else if (currentWord == "beep")
		{
			comArray[l][0] = words[0][0];
			comArray[l][1] = words[1][0];
			comArray[l][2] = words[2][0];
			comArray[l][3] = words[3][0];
		}
		else if (currentWord == "edge")
		{
			comArray[l][0] = words[0][0];
			comArray[l][1] = words[1][0];
			comArray[l][2] = words[2][0];
			comArray[l][3] = words[3][0];
		}
		else if (currentWord == "robo")
		{
			comArray[l][0] = words[0][0];
			comArray[l][1] = words[1][0];
			comArray[l][2] = words[2][0];
			comArray[l][3] = words[3][0];
			comArray[l][4] = words[4][0];
		}
		

		l++;
	}

	inputFile.close();
	return comArray;

}




