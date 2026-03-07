#include <iostream>
#include "header.hpp"




int main() {

    int         intArr[] = {1, 2, 3, 4, 5};
    double      dblArr[] = {1.1, 2.2, 3.3};
    std::string strArr[] = {"hello", "world", "42"};
    const int   constArr[] = {10, 20, 30};

    std::cout << "--- int array ---" << std::endl;
    iter(intArr, 5, ::print<int>);

    std::cout << "--- double array ---" << std::endl;
    iter(dblArr, 3, ::print<double>);

    std::cout << "--- string array ---" << std::endl;
    iter(strArr, 3, ::print<std::string>);

    std::cout << "--- const int array ---" << std::endl;
    iter(constArr, 3, ::print<int>);

    return 0;
}