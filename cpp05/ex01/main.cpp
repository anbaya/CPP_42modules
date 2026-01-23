#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        Form taxForm("Tax Form", 1, 5);

        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;

        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat jane("Jane", 1);
        jane.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}