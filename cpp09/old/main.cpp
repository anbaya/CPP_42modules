#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <map>
#include "File.hpp"


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try{
            File file(argv[1]);
            std::cout << "File content:\n" << file.fileContent << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " <file name>" << std::endl;
        return 1;
    }
    std::map<std::string, std::string> btc;
    return 0;
}