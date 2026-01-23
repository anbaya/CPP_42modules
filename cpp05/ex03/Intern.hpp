#pragma once

#include <string>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    AForm* makePresidentialPardonForm(const std::string& target) const;
    AForm* makeRobotomyRequestForm(const std::string& target) const;
    AForm* makeShrubberyCreationForm(const std::string& target) const;
    AForm* makeForm(const std::string& formName, const std::string& target) const;
};