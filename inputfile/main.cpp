#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
std::ifstream inputfile("input.txt");
std::ofstream outputfile("output.txt");
std::vector<std::string> ArmeniaContainingLines()
{
	std::vector<std::string> LinesContainingArmenia;
	if (inputfile.is_open())
	{
		std::string line;
		while (std::getline(inputfile, line))
		{
			if (line.find("Armenia") != std::string::npos)
			{
				LinesContainingArmenia.push_back(line);
			}
		}
		inputfile.close();
		return LinesContainingArmenia;
	}
	else
	{
		std::cerr << "File cant opened:\nError\n";
		throw abort;
	}
}

int main()
{
	std::vector<std::string> LinesContainingArmenia = ArmeniaContainingLines();
	for_each(LinesContainingArmenia.begin(), LinesContainingArmenia.end(), [](const std::string& N) {outputfile << N << std::endl; });
}
