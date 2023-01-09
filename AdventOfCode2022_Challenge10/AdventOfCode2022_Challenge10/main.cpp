#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	int x = 1;
	int cycle = 0;
	int targetCycle = 20;
	int newLineCycle = 0;

	int sumStrength = 0;		// Solution for part 1
	std::string output = "";	// Solution for part 2

	//Read text file
	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string instruction;
		while (std::getline(adventInputFile, instruction))
		{
			//Calculate Output at begining of cycle
			if (abs(cycle % 40 - x) < 2)
			{
				output += "#";
			}
			else
			{
				output += ".";
			}

			//Line ending reached
			if (cycle == newLineCycle)
			{
				output += "\n";
				newLineCycle += 40;
			}


			++cycle;
			if (instruction == "noop")	// One Cycle to Complete, does nothing
			{
				if (cycle == targetCycle)
				{
					sumStrength += cycle * x;
					targetCycle += 40;
				}
			}
			else // Two Cycles, x is incresed by values
			{

				//Calculate Output when not running noop command
				if (abs(cycle % 40 - x) < 2)
				{
					output += "#";
				}
				else
				{
					output += ".";
				}

				//Line ending reached
				if (cycle == newLineCycle)
				{
					output += "\n";
					newLineCycle += 40;
				}

				//Calculate sum strength
				if (cycle == targetCycle)
				{
					sumStrength += cycle * x;
					targetCycle += 40;
				}

				++cycle;
				if (cycle == targetCycle)
				{
					sumStrength += cycle * x;
					targetCycle += 40;
				}

				x += std::stoi(instruction.substr(5));
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	std::cout << "Solution 1: " << sumStrength << std::endl;
	std::cout << "Solution 2: \n" << output << std::endl;

	return 0;
}