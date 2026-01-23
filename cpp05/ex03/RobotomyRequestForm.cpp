#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!this->isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getExecuteGrade()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Bzzzzzz... Vrrrrrr..." << std::endl;
    if (rand() % 2) {
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}