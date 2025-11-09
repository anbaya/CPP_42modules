#include "replase.hpp"

int fileCounter(std::ifstream* infile)
{
	int lines = 0;
	std::string line;

	while (std::getline(*infile, line))
		lines++;
	infile->clear();
	return lines;
}

char** loadFileToArray(std::ifstream *infile, int lines)
{
	char** file = new char*[lines];
	int index = 0;
	std::string line;

	while (std::getline(*infile, line))
	{
		file[index] = new char[line.length() + 1];
		strcpy(file[index], line.c_str());
		index++;
	}
	return file;
}

char** replaceString(char** array, char *s1, char *s2)
{
	int i = 0;

	while (array[i])
	{
		if (!std::strcmp(array[i], s1))
		{
			// delete array[i];
			strcpy(array[i], s2);
		}
		i++;
	}
	return (array);
}