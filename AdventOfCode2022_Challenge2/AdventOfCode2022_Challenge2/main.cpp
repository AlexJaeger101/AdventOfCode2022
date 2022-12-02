#include <iostream>
#include <map>
#include <fstream>
#include <string>

int ChallengePart1();
int ChallengePart2();

int main()
{
	int result1 = ChallengePart1();
	std::cout << result1 << std::endl;

	int result2 = ChallengePart2();
	std::cout << result2 << std::endl;

	return 0;
}

int ChallengePart1()
{
	std::map<char, char> winMap = {
	{'A', 'Y'},
	{'B', 'Z'},
	{'C', 'X'} };

	std::map<char, char> drawMap = {
	{'A', 'X'},
	{'B', 'Y'},
	{'C', 'Z'} };

	std::map<char, int> pointMap = {
	{'X', 1},
	{'Y', 2},
	{'Z', 3} };

	std::fstream adventInputFile;
	int totalPoints = 0;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			totalPoints += pointMap[textLine[2]];

			if (winMap[textLine[0]] == textLine[2])
			{
				totalPoints += 6;
			}
			else if (drawMap[textLine[0]] == textLine[2])
			{
				totalPoints += 3;
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return totalPoints;
}

int ChallengePart2()
{
	std::map<char, char> loseMap = {
	{'A', 'Z'},
	{'B', 'X'},
	{'C', 'Y'} };

	std::map<char, char> winMap = {
	{'A', 'Y'},
	{'B', 'Z'},
	{'C', 'X'} };

	std::map<char, char> drawMap = {
	{'A', 'X'},
	{'B', 'Y'},
	{'C', 'Z'} };

	std::map<char, int> pointMap = {
	{'X', 1},
	{'Y', 2},
	{'Z', 3} };

	std::fstream adventInputFile;
	int totalPoints = 0;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			if (textLine[2] == 'X')
			{
				totalPoints += pointMap[loseMap[textLine[0]]];
			}
			else if (textLine[2] == 'Y')
			{
				totalPoints += 3 + pointMap[drawMap[textLine[0]]];
			}
			else
			{
				totalPoints += 6 + pointMap[winMap[textLine[0]]];
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	 return totalPoints;
}