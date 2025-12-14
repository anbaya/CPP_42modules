#include "Brain.hpp"

Brain::Brain() {
    ideas = new std::string[100];
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    ideas = new std::string[100];
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        delete[] ideas;
        ideas = new std::string[100];
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain() {
    delete[] ideas;
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}