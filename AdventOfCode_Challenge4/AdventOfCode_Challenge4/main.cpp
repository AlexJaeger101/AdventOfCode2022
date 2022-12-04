#include <iostream>
#include <fstream>
#include <string>

int ChallengePart1();
int ChallengePart2();

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
	int pairCount = 0;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			std::string groupA;
			std::string groupB;

			int commaPos = textLine.find_first_of(',');
			groupA = textLine.substr(0, commaPos);
			groupB = textLine.substr(commaPos + 1);

			int hyphenPos = groupA.find_first_of('-');
			std::string groupALower = groupA.substr(0, hyphenPos);
			std::string groupAHigher = groupA.substr(hyphenPos + 1);

			hyphenPos = groupB.find_first_of('-');
			std::string groupBLower = groupB.substr(0, hyphenPos);
			std::string groupBHigher = groupB.substr(hyphenPos + 1);

			if (std::stoi(groupALower) <= std::stoi(groupBLower)
			 && std::stoi(groupAHigher) >= std::stoi(groupBHigher))
			{
				++pairCount;
			}
			else if (std::stoi(groupALower) >= std::stoi(groupBLower)
			      && std::stoi(groupAHigher) <= std::stoi(groupBHigher))
			{
				++pairCount;
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return pairCount;
}

int ChallengePart2()
{
	std::fstream adventInputFile;
	int pairCount = 0;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			std::string groupA;
			std::string groupB;

			int commaPos = textLine.find_first_of(',');
			groupA = textLine.substr(0, commaPos);
			groupB = textLine.substr(commaPos + 1);

			int hyphenPos = groupA.find_first_of('-');
			std::string groupALower = groupA.substr(0, hyphenPos);
			std::string groupAHigher = groupA.substr(hyphenPos + 1);

			hyphenPos = groupB.find_first_of('-');
			std::string groupBLower = groupB.substr(0, hyphenPos);
			std::string groupBHigher = groupB.substr(hyphenPos + 1);

			if (std::stoi(groupALower) <= std::stoi(groupBHigher)
			 && std::stoi(groupAHigher) >= std::stoi(groupBLower))
			{
				++pairCount;
			}
			else if (std::stoi(groupALower) >= std::stoi(groupBHigher)
				  && std::stoi(groupAHigher) <= std::stoi(groupBLower))
			{
				++pairCount;
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return pairCount;
}