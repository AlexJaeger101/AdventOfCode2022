#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string ChallengePart1();
std::string ChallengePart2();

int main()
{
	std::string solution1 = ChallengePart1();
	std::cout << solution1 << std::endl;

	std::string solution2 = ChallengePart2();
	std::cout << solution2 << std::endl;

	return 0;
}

std::string ChallengePart1()
{
	std::fstream adventInputFile;

	/*
	Initial Input


					[V]     [C]     [M]
	[V]     [J]     [N]     [H]     [V]
	[R] [F] [N]     [W]     [Z]     [N]
	[H] [R] [D]     [Q] [M] [L]     [B]
	[B] [C] [H] [V] [R] [C] [G]     [R]
	[G] [G] [F] [S] [D] [H] [B] [R] [S]
	[D] [N] [S] [D] [H] [G] [J] [J] [G]
	[W] [J] [L] [J] [S] [P] [F] [S] [L]
	1   2   3   4   5   6   7   8   9 
	*/
	std::string inputArray[9] = {
		"VRHBGDW",
		"FRCGNJ",
		"JNDHFSL",
		"VSDJ",
		"VNWQRDHS",
		"MCHGP",
		"CHZLGBJF",
		"RJS",
		"MVNBRSGL"
	};

	std::string solution = "";

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			int moveOrder[3] = { -1 };

			//Get ints from textLine
			std::stringstream stream;
			stream << textLine;
			std::string temp;
			int i = 0;
			int found;
			while (!stream.eof())
			{
				stream >> temp;
				if (std::stringstream(temp) >> found)
				{
					moveOrder[i] = found;
					++i;
					if (i == 3)
					{
						break;
					}
				}
			}

			//Move Crates
			int moveCounter = moveOrder[0];
			int startPos = moveOrder[1] - 1;
			int endPos = moveOrder[2] - 1;
			while (moveCounter != 0)
			{
				//Remove top crate
				std::string oldStack = inputArray[startPos];
				char moveTarget = oldStack[0];
				inputArray[startPos].erase(0, 1);
				
				//Add crate to another stack
				std::string newStack = inputArray[endPos];
				inputArray[endPos] = moveTarget + newStack;

				--moveCounter;
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	//Build solution string
	for (std::string stack : inputArray)
	{
		solution += stack[0];
	}

	return solution;
}

std::string ChallengePart2()
{
	std::fstream adventInputFile;

	/*
	Initial Input


					[V]     [C]     [M]
	[V]     [J]     [N]     [H]     [V]
	[R] [F] [N]     [W]     [Z]     [N]
	[H] [R] [D]     [Q] [M] [L]     [B]
	[B] [C] [H] [V] [R] [C] [G]     [R]
	[G] [G] [F] [S] [D] [H] [B] [R] [S]
	[D] [N] [S] [D] [H] [G] [J] [J] [G]
	[W] [J] [L] [J] [S] [P] [F] [S] [L]
	1   2   3   4   5   6   7   8   9
	*/
	std::string inputArray[9] = {
		"VRHBGDW",
		"FRCGNJ",
		"JNDHFSL",
		"VSDJ",
		"VNWQRDHS",
		"MCHGP",
		"CHZLGBJF",
		"RJS",
		"MVNBRSGL"
	};

	std::string solution = "";

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			int moveOrder[3] = { -1 };

			//Get ints from textLine
			std::stringstream stream;
			stream << textLine;
			std::string temp;
			int i = 0;
			int found;
			while (!stream.eof())
			{
				stream >> temp;
				if (std::stringstream(temp) >> found)
				{
					moveOrder[i] = found;
					++i;
					if (i == 3)
					{
						break;
					}
				}
			}

			//Move Crates
			int moveAmount = moveOrder[0];
			int startPos = moveOrder[1] - 1;
			int endPos = moveOrder[2] - 1;

			//Remove top crates
			std::string oldStack = inputArray[startPos];
			std::string moveTarget = oldStack.substr(0, moveAmount);
			inputArray[startPos].erase(0, moveAmount);

			//Add crate to another stack
			std::string newStack = inputArray[endPos];
			inputArray[endPos] = moveTarget + newStack;
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	//Build solution string
	for (std::string stack : inputArray)
	{
		solution += stack[0];
	}

	return solution;
}