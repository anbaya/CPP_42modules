#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat anoir("anoir", 2);
        std::cout << anoir << std::endl;
        anoir.incrementGrade();
        std::cout << anoir << std::endl;
        anoir.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat other("other", 149);
        std::cout << other << std::endl;
        other.decrementGrade();
        std::cout << other << std::endl;
        other.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}