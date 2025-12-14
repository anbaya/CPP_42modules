#pragma once

#include <iostream>

class Brain;

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    virtual void makeSound() const = 0;
    virtual Brain* getBrain() const = 0;
    std::string getType() const;
};