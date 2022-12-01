#include <iostream>
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

// Part 1: Find the Elf carrying the most Calories. How many total Calories is that Elf carrying?
int ChallengePart1()
{
	std::fstream adventInputFile;
	int topCount = 0;
	int currentCount = 0;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			if (textLine == "")
			{
				if (currentCount > topCount)
				{
					topCount = currentCount;
				}

				currentCount = 0;
			}
			else
			{
				currentCount += std::stoi(textLine);
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return topCount;
}

// Part 2: Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?
int ChallengePart2()
{
	std::fstream adventInputFile;

	int first = 0;
	int second = 0;
	int third = 0;

	int currentCount = 0;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			if (textLine == "")
			{
				if (currentCount > first)
				{
					third = second;
					second = first;
					first = currentCount;
				}
				else if (currentCount > second)
				{
					third = second;
					second = currentCount;
				}
				else if (currentCount > third)
				{
					third = currentCount;
				}

				currentCount = 0;
			}
			else
			{
				currentCount += std::stoi(textLine);
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return first + second + third;
}