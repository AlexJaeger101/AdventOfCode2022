#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

enum Operator
{
	ADD,
	MULT
};


struct Operation
{
	Operator mOperator;				// How worry level changes (can be + or *)
	std::string mVal;				// new = old + mOperationVal (can also be *, depends on mOperation)
};

struct Monkey
{
	int mMonkeyNum;					// Monkey number
	std::vector<int> mItemList;		// List of item worry levels
	Operation mOperation;			// The operation to calculate new value
	int mDivisor;					// Divisible by this value
	int mInspectCount = 0;			// Number of times a specific monkey has been looked at

	//Monkeys have two buddies they can throw to
	int mBuddy1;
	int mBuddy2;

};

int whereToThrow(int oldVal, Monkey monkeyToThrow);
void printMonkey(Monkey monkey);
int extractInt(std::string str);
std::vector<int> extractInts(std::string str);

auto monkeyBuisness(std::vector<Monkey>& monkeys, int rounds, bool divByThree)
{
	int mod = 1;
	for (auto& monkey : monkeys)
	{
		mod *= monkey.mDivisor;
	}

	for (int i = 0; i < rounds; ++i)
	{
		for (auto& currentMonkey : monkeys)
		{
			for (auto iter = currentMonkey.mItemList.begin(); iter != currentMonkey.mItemList.end(); iter = currentMonkey.mItemList.erase(iter))
			{
				++currentMonkey.mInspectCount;
				auto& currentVal = *iter;

				if (currentMonkey.mOperation.mVal == "old")
				{
					currentVal *= currentVal;
				}
				else if (currentMonkey.mOperation.mOperator == ADD)
				{
					currentVal += std::stoi(currentMonkey.mOperation.mVal);
				}
				else if (currentMonkey.mOperation.mOperator == MULT)
				{
					currentVal *= std::stoi(currentMonkey.mOperation.mVal);
				}

				// Update
				if (divByThree)
				{
					currentVal /= 3;
				}
				int newMonkey = whereToThrow(currentVal, currentMonkey);
				monkeys[newMonkey].mItemList.push_back(currentVal % mod);
			}
		}
	}

	// find the two most inspected monkey (add to list and sort
	std::vector<uint64_t> inspectList;
	for (auto& monkey : monkeys)
	{
		inspectList.push_back(monkey.mInspectCount);
	}
	std::sort(inspectList.begin(), inspectList.end(), std::greater<uint64_t>());

	// Calc monkey buisness :) ooo ooo aaa aaaa aaa 
	return inspectList[0] * inspectList[1];
}

int main()
{
	std::vector<Monkey> monkeyList;

	//Parse file and store monkey in list
	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		Monkey tempMonkey;
		while (std::getline(adventInputFile, textLine))
		{

			if (textLine == "")
			{
				monkeyList.push_back(tempMonkey);
			}
			else if (textLine.substr(0, 6) == "Monkey")
			{
				tempMonkey.mMonkeyNum = extractInt(textLine);
			}
			else if (textLine.substr(2, 14) == "Starting items")
			{
				tempMonkey.mItemList = extractInts(textLine);
			}
			else if (textLine.substr(2, 9) == "Operation")
			{
				Operation tempOperator;

				if (textLine[23] == '*')
				{
					tempOperator.mOperator = MULT;
				}
				else
				{
					tempOperator.mOperator = ADD;
				}

				tempOperator.mVal = textLine.substr(25);
				tempMonkey.mOperation = tempOperator;
			}
			else if (textLine.substr(2, 4) == "Test")
			{
				tempMonkey.mDivisor = extractInt(textLine);
			}
			else if (textLine.substr(4, 7) == "If true")
			{
				tempMonkey.mBuddy1 = extractInt(textLine);
			}
			else if (textLine.substr(4, 8) == "If false")
			{
				tempMonkey.mBuddy2 = extractInt(textLine);
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	std::cout << "Solution Part 1: " << monkeyBuisness(monkeyList, 20, true) << std::endl;
	std::cout << "Solution Part 2: " << monkeyBuisness(monkeyList, 10000, false);

	return 0;
}

// Returns value of monkey being thrown to
int whereToThrow(int oldVal, Monkey monkeyToThrow)
{
	return (oldVal % monkeyToThrow.mDivisor) == 0 ? monkeyToThrow.mBuddy1 : monkeyToThrow.mBuddy2;
}

// Prints values of a monkey (for testing/debug purposes)
void printMonkey(Monkey monkey)
{
	std::cout << "Monkey Number: " << monkey.mMonkeyNum << std::endl;

	std::cout << "Worry Values: ";
	for (int i : monkey.mItemList)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "Operator: " << monkey.mOperation.mOperator << std::endl;
	std::cout << "Operator Value: " << monkey.mOperation.mVal << std::endl;
	std::cout << "Divisor: " << monkey.mDivisor << std::endl;

	std::cout << "Buddy 1: " << monkey.mBuddy1 << std::endl;
	std::cout << "Buddy 2: " << monkey.mBuddy2 << std::endl;

	std::cout << std::endl;
}

int extractInt(std::string str)
{
	std::vector<int> temp;
	std::stringstream ss;

	std::string tempStr;
	ss << str;
	int foundInt;
	while (!ss.eof())
	{
		ss >> tempStr;
		if (std::stringstream(tempStr) >> foundInt)
		{
			return foundInt;
		}
	}

	return -100;	//INVALID
}

std::vector<int> extractInts(std::string str)
{
	std::vector<int> temp;
	std::stringstream ss;

	std::string tempStr;
	ss << str;
	int foundInt;
	while (!ss.eof())
	{
		ss >> tempStr;
		if (std::stringstream(tempStr) >> foundInt)
		{
			temp.push_back(foundInt);
		}
	}

	return temp;
}