#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

int ChallengePart1();
int ChallengePart2();
bool IsRepeating(std::string s);

int main()
{
	int solution1 = ChallengePart1();
	std::cout << solution1 << std::endl;

	int solution2 = ChallengePart2();
	std::cout << solution2 << std::endl;

	return 0;
}


int ChallengePart1()
{
	std::fstream adventInputFile;
	std::string inputString;
	int counter = 0;

	//Get String from text File
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			inputString = textLine;
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	for (int i = 0; i < inputString.length(); ++i)
	{
		std::string currentSubString = inputString.substr(i, 4);
		if (IsRepeating(currentSubString))
		{
			//NON-REPEATING FOUND
			return i + 4;
		}
	}

	return -1;
}

int ChallengePart2()
{
	std::fstream adventInputFile;
	std::string inputString;
	int counter = 0;

	//Get String from text File
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			inputString = textLine;
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	for (int i = 0; i < inputString.length(); ++i)
	{
		std::string currentSubString = inputString.substr(i, 14);
		if (IsRepeating(currentSubString))
		{
			//NON-REPEATING FOUND
			return i + 14;
		}
	}

	return -1;
}

bool IsRepeating(std::string s)
{
	std::sort(s.begin(), s.end());

	for (int i = 0; i < s.length() - 1; i++) 
	{
		if (s[i] == s[i + 1]) 
		{
			return false;
		}
	}


	return true;
}