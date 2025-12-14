#include "Dog.hpp"
#include <sstream>

Dog::Dog(){
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
    for(int i = 0; i < 100; i++){
        std::stringstream ss;
        ss << "Dog idea " << i;
        this->brain->setIdea(i, ss.str());
    }
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other){
    std::cout << "copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << "Dog makes a sound" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}