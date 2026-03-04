#include <iostream>
#include "header.hpp"




int main() {
    int a = 2;
    int b = 3;

    std::cout << "before swap" << std::endl;
    std::cout << "a = "<< a << " b = " << b << std::endl;
    std::cout << "the max of " << a << " and " << b << " is " << ::mymax<int>(a, b) << std::endl;
    std::cout << "the min of " << a << " and " << b << " is " << ::mymin<int>(a, b) << std::endl;
    
    
    myswap<int>(a, b);
    std::cout << "after swap" << std::endl;
    std::cout << "a = "<< a << " b = " << b << std::endl;
    std::cout << "the max of " << a << " and " << b << " is " << ::mymax<int>(a, b) << std::endl;
    std::cout << "the min of " << a << " and " << b << " is " << ::mymin<int>(a, b) << std::endl;
    return 0;
}