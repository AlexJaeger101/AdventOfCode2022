#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>


int main()
{
	std::vector<std::string> filePathVec;
	std::vector<std::string> fileVec;

	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			//"$ ls" and "dir " don't matter to us
			if (textLine != "$ ls" && textLine.find("dir ") != 0)
			{
				if (textLine == "$ cd /") //very top of directory
				{
					filePathVec.clear();
					filePathVec.push_back("/");
				}
				else if (textLine == "$ cd ..") //go back one
				{
					filePathVec.pop_back();
				}
				else if (textLine.find("$ cd ") == 0) //got down one
				{
					filePathVec.push_back(textLine.substr(5) + "/");
				}
				else
				{
					int space = textLine.find(' ');
					std::string filename = "";
					for (auto current : filePathVec)
					{
						filename += current;
					}

					filename += textLine.substr(space + 1) + " " + textLine.substr(0, space);
					fileVec.push_back(filename);

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

	std::map<std::string, int> fileSize;
	for (auto file : fileVec)
	{
		int size = std::stoi(file.substr(file.find(' ')));
		std::string dir = file;
		while (dir.size() > 0)
		{
			int i = dir.find_last_of('/');
			std::string sub = dir.substr(0, i);
			fileSize[sub] += size;
			dir = sub;
		}
	}

	int result = 0;
	for (auto size : fileSize)
	{
		if (size.second < 100000)
		{
			result += size.second;
		}
	}

	std::cout << result << std::endl;

	int free = 70000000 - fileSize[""];
	int needed = 30000000 - free;
	int toDelete = 30000000;
	for (auto size : fileSize)
	{
		if (size.second > needed && size.second < toDelete)
		{
			toDelete = size.second;
		}
	}

	std::cout << toDelete;

	return 0;
}
