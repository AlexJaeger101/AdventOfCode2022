#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	int row = 0;
	int col = 0;
	int visibleTrees = 0;
	std::vector<std::vector<int>> treeGrid;

	//Read text file and put into grid
	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			std::vector<int> rowList;
			for (char c : textLine)
			{
				rowList.push_back(int(c) - 48);
				++row;
			}

			treeGrid.push_back(rowList);
			++col;
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	//Print Grid
	for (int x = 0; x < row; ++x)
	{
		for (int y = 0; y < col; ++y)
		{
			std::cout << treeGrid[x][y];

			//int currentObstruct = 0;
			//int dist = 1;

			//if (x != 0 && y != 0)
			//{
			//	//Check Up
			//	while ((y - dist) < 0)
			//	{
			//		currentObstruct += treeGrid[x][y - dist];
			//	}

			//	if (currentObstruct < treeGrid[x][y])
			//	{
			//		++visibleTrees;
			//		continue;
			//	}

			//	//Check Down
			//	while ((y - dist) > col)
			//	{
			//		currentObstruct += treeGrid[x][y + dist];
			//	}

			//	if (currentObstruct < treeGrid[x][y])
			//	{
			//		++visibleTrees;
			//		continue;
			//	}
			//	
			//	//Check right
			//	while ((x - dist) < 0)
			//	{
			//		currentObstruct += treeGrid[x - dist][y];
			//	}

			//	if (currentObstruct < treeGrid[x][y])
			//	{
			//		++visibleTrees;
			//		continue;
			//	}

			//	//Check Left
			//	while ((x - dist) > row)
			//	{
			//		currentObstruct += treeGrid[x + dist][y];
			//	}

			//	if (currentObstruct < treeGrid[x][y])
			//	{
			//		++visibleTrees;
			//		continue;
			//	}
			//}
		}

		std::cout << std::endl;
	}

	std::cout << visibleTrees << std::endl;

	return 0;
}