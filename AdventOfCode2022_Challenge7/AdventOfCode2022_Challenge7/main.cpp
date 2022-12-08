#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

struct File
{
	std::string mName;
	int mSize;
};
int main()
{
	std::vector<std::string> filePathVec;
	std::vector<File> dir;

	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			//"$ ls" and "dir " don't matter to us
			if (textLine != "$ ls" || textLine.find("dir ") != 0)
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
					int size = textLine.find(' ');
					File currentFile;
					currentFile.find
					for (auto current : filePathVec)
					{

					}

				}
			}
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}


	return 0;
}
