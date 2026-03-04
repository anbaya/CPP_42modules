#include <iostream>
#include "Array.hpp"




int main() {

    Array<int> arr(5);

    try
    {
        for (unsigned int i = 0; i < arr.Size(); i++)
        {
            arr[i] = i * 10;
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "first try completed" << std::endl;
    }
    catch(const Array<int>::outOfRangeExeption& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "first try failed" << std::endl;
        std::cout << std::endl;
    }
    
    try
    {
        std::cout << arr[10] << std::endl;
    }
    catch(const Array<int>::outOfRangeExeption& e)
    {
        std::cout << std::endl;
        std::cerr << e.what() << '\n';
        std::cout << "second try failed" << std::endl;
    }

    return 0;
}