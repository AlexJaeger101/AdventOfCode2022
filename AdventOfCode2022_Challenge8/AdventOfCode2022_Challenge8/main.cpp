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

	//Go through entire grid and check how many trees are visible from the edges
	for (int x = 0; x < row; ++x)
	{
		for (int y = 0; y < col; ++y)
		{
			int visibleDir = 4;

			// Check Right
			for (int offset = 0; offset < x; ++offset)
			{
				if (treeGrid[y][offset] >= treeGrid[y][x])
				{
					--visibleDir;
					break;
				}
			}

			// Check Left
			for (int offset = row - 1; offset > x; --offset)
			{
				if (treeGrid[y][offset] >= treeGrid[y][x])
				{
					--visibleDir;
					break;
				}
			}

			// Check Down
			for (int offset = 0; offset < y; ++offset)
			{
				if (treeGrid[offset][x] >= treeGrid[y][x])
				{
					--visibleDir;
					break;
				}
			}

			// Check Up
			for (int offset = col - 1; offset > y; --offset)
			{
				if (treeGrid[offset][x] >= treeGrid[y][x])
				{
					--visibleDir;
					break;
				}
			}


			visibleTrees += visibleDir > 0;

		}
	}

	std::cout << "Solution 1: " << visibleTrees << std::endl;


	//Go through grid and find the tree with the highest viewing distance
	int viewDist = 0;
	for (int x = 0; x < row; ++x) 
	{
		for (int y = 0; y < col; ++y) 
		{
			int totalDist = 1;
			int currentDist = 0;

			//Check Left
			for (int offset = x - 1; offset >= 0; --offset)
			{ 
				currentDist += 1;
				if (treeGrid[y][offset] >= treeGrid[y][x])
				{
					break;
				}
			} 
			totalDist *= currentDist;
			currentDist = 0;
			
			//Check Right
			for (int offset = x + 1; offset < row; ++offset)
			{ 
				currentDist += 1; 
				if (treeGrid[y][offset] >= treeGrid[y][x])
				{
					break;
				}
			} 
			totalDist *= currentDist;
			currentDist = 0;

			//Check up
			for (int offset = y - 1; offset >= 0; --offset) 
			{ 
				currentDist += 1; 
				if (treeGrid[offset][x] >= treeGrid[y][x]) 
				{ 
					break; 
				}
			} 
			totalDist *= currentDist;
			currentDist = 0;
			
			//Check Down
			for (int offset = y + 1; offset < col; ++offset) 
			{ 
				currentDist += 1; 
				if (treeGrid[offset][x] >= treeGrid[y][x]) 
				{ 
					break; 
				}
			} 
			totalDist *= currentDist; 
			currentDist = 0;
			
			//Check if total exceeds current viewDist
			if (totalDist > viewDist) 
			{ 
				viewDist = totalDist; 
			}
		}
	}

	std::cout << "Solution 2: " << viewDist << std::endl;

	return 0;
}