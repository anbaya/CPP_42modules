#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

    return 0;
}