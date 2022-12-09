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
				row = textLine.size();
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
			int visibleDir = 0;

			// Check Right
			for (int offset = 0; offset < x; ++offset)
			{
				if (treeGrid[y][offset] >= treeGrid[y][x])
				{
					++visibleDir;
					break;
				}
			}

			// Check Left
			for (int offset = row - 1; offset > x; --offset)
			{
				if (treeGrid[y][offset] >= treeGrid[y][x])
				{
					++visibleDir;
					break;
				}
			}

			// Check Down
			for (int offset = 0; offset < y; ++offset)
			{
				if (treeGrid[offset][x] >= treeGrid[y][x])
				{
					++visibleDir;
				}
			}

			// Check Up
			for (int offset = col - 1; offset > y; --offset)
			{
				if (treeGrid[offset][x] >= treeGrid[y][x])
				{
					++visibleDir;
				}
			}


			if (visibleDir > 0)
			{
				visibleTrees += visibleDir;
			}

		}

		std::cout << std::endl;
	}

	std::cout << visibleTrees << std::endl;

	return 0;
}