#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

struct Motion
{
	char mDir;
	int mDist;
};

struct Position
{
	int mX;
	int mY;
};

Motion StringToMotion(std::string s);

int main()
{
	std::vector<Motion> motionList;
	Position head = { 0, 0 };
	Position tail = { 0, 0 };

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

	//Challenge 1
	std::set<Position> visitedPosition;
	visitedPosition.insert(tail);

	for (Motion currentMotion : motionList)
	{
		//Move head and tail
		for (int i = 0; i < currentMotion.mDist; ++i)
		{

			switch (currentMotion.mDir) 
			{
			case 'U':	// Move Up

				head = { head.mX, head.mY + 1 };
				break;

			case 'D':	// Move Down

				head = { head.mX, head.mY - 1 };
				break;

			case 'L':	// Move Left

				head = { head.mX - 1, head.mY };
				break;

			case 'R':	// Move Right

				head = { head.mX + 1, head.mY };
				break;

			default:

				//Invalid
				break;

			}

			//Update tail position
			int distX = head.mX - tail.mX;
			int distY = head.mY - tail.mY;
			if (abs(distX) < 2 && abs(distY < 2))
			{

			}
			else if (head.mX == tail.mX) 
			{ 
				tail.mY += distY / 2;
			}
			else if (head.mY == tail.mY) 
			{ 
				tail.mX += distX / 2;
			}
			else
			{
				tail.mX += distX < 0 ? -1 : 1;
				tail.mY += distY < 0 ? -1 : 1;
			}


			visitedPosition.insert(tail);
		}
	}

	std::cout << "Solution 1: " << visitedPosition.size() << std::endl;

	return 0;
}

Motion StringToMotion(std::string s)
{
	Motion newMotion;

	newMotion.mDir = s[0];
	newMotion.mDist = int(s[2]) - 48;

	return newMotion;
}