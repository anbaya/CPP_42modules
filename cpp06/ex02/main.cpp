#include "main.hpp"

int main()
{
    Base *ptr = generate();

    std::cout << "Identifying pointer:" << std::endl;
    identify(ptr);

    std::cout << "Identifying reference:" << std::endl;
    identify(*ptr);

    delete ptr;
    return 0;
}