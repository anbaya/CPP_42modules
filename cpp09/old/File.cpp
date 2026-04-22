#include "File.hpp"

File::File(char *fileName)
{
    try{
        namechecker();
        this->fileName = fileName;
    }
    catch (const File::invalidFileNameException &e)
    {
        throw File::invalidFileNameException();
    }
    this->file.open(fileName);
    if (!this->file.is_open())
        throw CantOpenFileException();
    std::string line;
    while (std::getline(this->file, line))
        this->fileContent += line + "\n";
    if (this->fileContent.empty())
        throw EmptyFileException();
}

int File::namechecker()
{
    size_t len = std::strlen(this->fileName);
    if (len == 0)
        throw invalidFileNameException();
    for (size_t i = 0; i < len; ++i)
    {
        if (this->fileName[i] == '/' || this->fileName[i] == '\\')
            throw invalidFileNameException();
    }
    if (std::strcmp(this->fileName+len-4, ".txt") != 0)
        throw invalidFileNameException();
    return 0;
}

File::~File()
{
    if (this->file.is_open())
        this->file.close();
    delete[] this->fileName;
}