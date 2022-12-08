#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>


int main()
{
	std::vector<std::string> filePathVec;

	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string filePath;

		//Create vector of all files (with filepath as name)
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			//"$ ls" and "dir " don't matter to us
			if (textLine != "$ ls" && textLine.find("dir ") != 0)
			{
				if (textLine == "$ cd /") //very top of directory
				{
					filePath = "/";
				}
				else if (textLine == "$ cd ..") //go back one
				{
					int removeLocation = filePath.find_last_of('/');
					filePath = filePath.substr(0, removeLocation);
				}
				else if (textLine.find("$ cd ") == 0) //got down one
				{
					filePath = filePath + textLine.substr(5) + "/";
				}
				else
				{
					int space = textLine.find(' ');
					std::string fileToAdd = filePath + textLine.substr(space + 1) + " " + textLine.substr(0, space);
					filePathVec.push_back(fileToAdd);
				}
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
		return 0;
	}

	//create map of files
	//basically a lookup table of filenames to sizes
	std::map<std::string, int> fileMap;
	for (auto file : filePathVec)
	{
		int size = std::stoi(file.substr(file.find(' ')));
		std::string currentFilePath = file;
		while (currentFilePath.size() > 0)
		{
			std::string fileName = currentFilePath.substr(0, currentFilePath.find_last_of('/'));
			fileMap[fileName] += size;
			currentFilePath = fileName;
		}
	}

	//Part 1 answer: sum of all file size under 100000
	int result = 0;
	for (auto size : fileMap)
	{
		if (size.second < 100000)
		{
			result += size.second;
		}
	}

	std::cout << "Solution 1: " << result << std::endl;

	//Part 2 answer: find size of smallest directory that can free upp enough space
	result = 30000000;
	int avalialbeSpace = 70000000 - fileMap[""];
	for (auto size : fileMap)
	{
		if (size.second > (30000000 - avalialbeSpace) && size.second < result)
		{
			result = size.second;
		}
	}

	std::cout << "Solution 2: " << result;

	return 0;
}
