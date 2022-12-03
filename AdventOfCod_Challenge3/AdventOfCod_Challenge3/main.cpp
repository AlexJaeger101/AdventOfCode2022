#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

int ChallengePart1();
int ChallengePart2();

std::string FindCommonChar(std::string a, std::string b);
std::string FindCommonChar(std::string a, std::string b, std::string c);

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
	std::map<char, int> charValue = {
		{'a', 1},
		{'b', 2},
		{'c', 3},
		{'d', 4},
		{'e', 5},
		{'f', 6},
		{'g', 7},
		{'h', 8},
		{'i', 9},
		{'j', 10},
		{'k', 11},
		{'l', 12},
		{'m', 13},
		{'n', 14},
		{'o', 15},
		{'p', 16},
		{'q', 17},
		{'r', 18},
		{'s', 19},
		{'t', 20},
		{'u', 21},
		{'v', 22},
		{'w', 23},
		{'x', 24},
		{'y', 25},
		{'z', 26},

	};

	std::fstream adventInputFile;
	int prioritySum = 0;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			std::string rugsack1 = textLine.substr(0, (textLine.size() / 2));
			std::string rugsack2 = textLine.substr((textLine.size() / 2), (textLine.size() / 2));
			std::string commonChar = FindCommonChar(rugsack1, rugsack2);

			if (std::isupper(commonChar[0]))
			{
				prioritySum += 26;
				commonChar[0] = commonChar[0] + 32; //Convert to lower
			}

			prioritySum += charValue[commonChar[0]];
			
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return prioritySum;
}

int ChallengePart2()
{
	std::map<char, int> charValue = {
	{'a', 1},
	{'b', 2},
	{'c', 3},
	{'d', 4},
	{'e', 5},
	{'f', 6},
	{'g', 7},
	{'h', 8},
	{'i', 9},
	{'j', 10},
	{'k', 11},
	{'l', 12},
	{'m', 13},
	{'n', 14},
	{'o', 15},
	{'p', 16},
	{'q', 17},
	{'r', 18},
	{'s', 19},
	{'t', 20},
	{'u', 21},
	{'v', 22},
	{'w', 23},
	{'x', 24},
	{'y', 25},
	{'z', 26},
	};

	std::fstream adventInputFile;
	int prioritySum = 0;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		std::string rugsack1 = "";
		std::string rugsack2 = "";
		std::string rugsack3 = "";
		while (std::getline(adventInputFile, textLine))
		{
			if (rugsack1 == "")
			{
				rugsack1 = textLine;
			}
			else if (rugsack2 == "")
			{
				rugsack2 = textLine;
			}
			else if (rugsack3 == "")
			{
				rugsack3 = textLine;

				std::string commonChar = FindCommonChar(rugsack1, rugsack2, rugsack3);

				if (std::isupper(commonChar[0]))
				{
					prioritySum += 26;
					commonChar[0] = commonChar[0] + 32; //Convert to lower
				}

				prioritySum += charValue[commonChar[0]];

				rugsack1 = "";
				rugsack2 = "";
				rugsack3 = "";
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}


	return prioritySum;
}

std::string FindCommonChar(std::string a, std::string b)
{
	std::sort(std::begin(a), std::end(a));
	std::sort(std::begin(b), std::end(b));

	std::string common;
	std::set_intersection(std::begin(a), std::end(a), std::begin(b), std::end(b), std::back_inserter(common));

	return common;
}

std::string FindCommonChar(std::string a, std::string b, std::string c)
{
	std::sort(std::begin(a), std::end(a));
	std::sort(std::begin(b), std::end(b));
	std::sort(std::begin(c), std::end(c));

	std::string lastIntersection = a;
	std::string currentIntersection;

	std::set_intersection(lastIntersection.begin(), lastIntersection.end(), a.begin(), a.end(), std::back_inserter(currentIntersection));
	lastIntersection = currentIntersection;
	currentIntersection = "";

	std::set_intersection(lastIntersection.begin(), lastIntersection.end(), b.begin(), b.end(), std::back_inserter(currentIntersection));
	lastIntersection = currentIntersection;
	currentIntersection = "";

	std::set_intersection(lastIntersection.begin(), lastIntersection.end(), c.begin(), c.end(), std::back_inserter(currentIntersection));
	lastIntersection = currentIntersection;
	currentIntersection = "";

	return lastIntersection;
}