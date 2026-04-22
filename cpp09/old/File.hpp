#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

class File
{
public:
    char *fileName;
    std::ifstream file;
    std::string fileContent;
    File(char *fileName);
    ~File();
    int namechecker();
    class CantOpenFileException : public std::exception
    {    public:
        virtual const char *what() const throw()
        {return "FileException: Failed to open the file.";}
    };
    class EmptyFileException : public std::exception
    {    public:
        virtual const char *what() const throw()
        {return "FileException: The file is empty.";}
    };
    class invalidFileNameException : public std::exception
    {    public:
        virtual const char *what() const throw()
        {return "FileException: Invalid file name.";}
    };
    class inalidFileContentException : public std::exception
    {    public:
        virtual const char *what() const throw()
        {return "FileException: Invalid file content.";}
    };
};

#endif // FILE_HPP