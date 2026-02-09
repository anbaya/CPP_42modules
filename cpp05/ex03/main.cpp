#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    // --- Test 1: Bureaucrats and Concrete Forms ---
    // This section verifies that Bureaucrats can sign and execute the different specific forms
    // and that grade checks are working correctly.
    try {
        Bureaucrat omar("Omar", 1);
        Bureaucrat ali("Ali", 150);

        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Bender");
        PresidentialPardonForm pardonForm("criminal");

        omar.signForm(shrubberyForm);
        omar.executeForm(shrubberyForm);

        omar.signForm(robotomyForm);
        omar.executeForm(robotomyForm);

        omar.signForm(pardonForm);
        omar.executeForm(pardonForm);

        ali.executeForm(shrubberyForm); // This should fail due to low grade
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // --- Test 2: Intern creating Forms ---
    // This section verifies that the Intern can correctly create forms by name.
    try {
        Intern someRandomIntern;
        AForm* form;

        // 1. Create and use a RobotomyRequestForm
        std::cout << "\n[ Creating Robotomy Request ]" << std::endl;
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat omar("Omar", 1);
        omar.signForm(*form);
        omar.executeForm(*form);
        delete form;

        // 2. Create and use a ShrubberyCreationForm
        std::cout << "\n[ Creating Shrubbery Creation ]" << std::endl;
        form = someRandomIntern.makeForm("shrubbery creation", "Garden");
        omar.signForm(*form);
        omar.executeForm(*form);
        delete form;

        // 3. Create and use a PresidentialPardonForm
        std::cout << "\n[ Creating Presidential Pardon ]" << std::endl;
        form = someRandomIntern.makeForm("presidential pardon", "Alice");
        omar.signForm(*form);
        omar.executeForm(*form);
        delete form;

        // 4. Test Error Case: Unknown Form
        std::cout << "\n[ Creating Unknown Form ]" << std::endl;
        form = someRandomIntern.makeForm("unknown form", "Target");
        delete form;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}