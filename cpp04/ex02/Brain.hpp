#pragma once

#include <iostream>

class Brain {
protected:
    std::string* ideas;
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};