#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makePresidentialPardonForm(const std::string& target) const {
    std::cout << "Intern creates Presidential Pardon Form" << std::endl;
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) const {
    std::cout << "Intern creates Robotomy Request Form" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target) const {
    std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
    return new ShrubberyCreationForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found exception";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    // array of form names
    const std::string formNames[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    // array of pointers to member functions
    AForm* (Intern::*formCreators[3])(const std::string& target) const = {
        &Intern::makePresidentialPardonForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makeShrubberyCreationForm
    };
    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            return (this->*formCreators[i])(target);
        }
    }
    throw FormNotFoundException();
}