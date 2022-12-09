#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
	//Grid positions (for keeping track of where we were
	std::vector<std::vector<int>> gridPos = 
	{
		std::vector<int> {0, 0, 0, 0, 0, 0},
		std::vector<int> {0, 0, 0, 0, 0, 0},
		std::vector<int> {0, 0, 0, 0, 0, 0},
		std::vector<int> {0, 0, 0, 0, 0, 0},
		std::vector<int> {0, 0, 0, 0, 0, 0}
	};
	
	std::vector<std::string> motionList;
	int positionCount = 1;

	//Get input from text file
	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			motionList.push_back(textLine);
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}


	return 0;
}