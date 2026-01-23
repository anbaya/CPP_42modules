#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);

        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Bender");
        PresidentialPardonForm pardonForm("Marvin");

        bob.signForm(shrubberyForm);
        bob.executeForm(shrubberyForm);

        bob.signForm(robotomyForm);
        bob.executeForm(robotomyForm);

        bob.signForm(pardonForm);
        bob.executeForm(pardonForm);

        alice.executeForm(shrubberyForm); // This should fail due to low grade
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        Intern someRandomIntern;
        AForm* form;

        form = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat bob("Bob", 1);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;

        form = someRandomIntern.makeForm("shrubbery creation", "Garden");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;

        form = someRandomIntern.makeForm("presidential pardon", "Alice");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;

        form = someRandomIntern.makeForm("unknown form", "Target");
        delete form;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}