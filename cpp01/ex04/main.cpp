#include "replase.hpp"



int main(int argc, char** argv){

	std::ifstream infile;
	std::ofstream outfile;

	if (argc != 4) {
		std::cerr << "Usage: ./program <string_to_replace> <replacement_string>" << std::endl;
		return 1;
	}
	infile.open(argv[1]);
	if (!infile.is_open()){
		std::cerr << "can't open input file" << std::endl;
		exit(1);
	}
	outfile.open(argv[1] + std::string(".replace"));
	if (!outfile.is_open()){
		std::cerr << "can't open output file" << std::endl;
		exit(1);
	}

	int lines = fileCounter(&infile);
	infile.clear();
	infile.seekg(0);
	char** file = loadFileToArray(&infile, lines);
	file = replaceString(file, argv[2], argv[3]);
	for (int i = 0; i < lines; i++)
	{
		outfile << file[i] << std::endl;
		delete[] file[i];
	}
	if (file)
		delete[] file;
	infile.close();
	return 0;
}