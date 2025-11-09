#ifndef REPLASE_HPP
#define REPLASE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

char** replaceString(char** array, char *s1, char *s2);
int fileCounter(std::ifstream* infile);
char** loadFileToArray(std::ifstream* infile, int lines);


#endif // !REPLASE_HPP