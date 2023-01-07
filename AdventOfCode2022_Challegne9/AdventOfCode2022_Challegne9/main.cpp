#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <array>

struct Motion
{
	char mDir;
	int mDist;
};

struct Position
{
	int mX;
	int mY;

	bool operator == (const Position& other) const
	{
		return mX == other.mX && mY == other.mY;
	}
};

struct Hash 
{
public:

	size_t operator()(const Position pos) const 
	{
		return std::hash<uint32_t>()(pos.mX) ^ std::hash<uint32_t>()(pos.mY);
	}
};

Motion StringToMotion(std::string s);

int main()
{
	std::vector<Motion> motionList;

	//Get input from text file
	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			motionList.push_back(StringToMotion(textLine));
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	//Solving Both Challenges at once!
	std::unordered_set<Position, Hash> visitedPosPart1;	//Keeping track of visited pos for part 1
	std::unordered_set<Position, Hash> visitedPosPart2;	//Keeping track of visited pos for part 2
	std::array<Position, 10> knotArray;

	for (Motion currentMotion : motionList)
	{
		//Move head and tail
		for (int i = 0; i < currentMotion.mDist; ++i)
		{

			switch (currentMotion.mDir) 
			{
			case 'U':	// Move Up

				++knotArray[0].mY;
				break;

			case 'D':	// Move Down

				--knotArray[0].mY;
				break;

			case 'L':	// Move Left

				--knotArray[0].mX;
				break;

			case 'R':	// Move Right

				++knotArray[0].mX;
				break;

			default:

				//Invalid
				break;

			}

			//Update tail position
			for (int i = 1; i < knotArray.size(); ++i) 
			{
				Position& head = knotArray[i - 1];
				Position& tail = knotArray[i];

				Position diff;
				diff.mX = head.mX - tail.mX;
				diff.mY = head.mY - tail.mY;

				if (abs(diff.mX) == 2 || abs(diff.mY) == 2) 
				{
					knotArray[i].mX += ((diff.mX > 0) - (diff.mX < 0));
					knotArray[i].mY += ((diff.mY > 0) - (diff.mY < 0));
				}
			}

			visitedPosPart1.insert(knotArray[1]);
			visitedPosPart2.insert(knotArray[knotArray.size() - 1]);
		}
	}

	std::cout << "Solution 1: " << visitedPosPart1.size() << std::endl;
	std::cout << "Solution 2: " << visitedPosPart2.size() << std::endl;

	return 0;
}

Motion StringToMotion(std::string s)
{
	Motion newMotion;

	newMotion.mDir = s[0];
	newMotion.mDist = std::stoi(s.substr(2));

	return newMotion;
}