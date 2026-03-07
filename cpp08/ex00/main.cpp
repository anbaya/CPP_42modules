#include "easyfind.hpp"


int main(){

    std::vector<int> numbers;

    for(int i = 0; i < 10; i++){
        numbers.push_back(0 + i);
    }
    try
    {
        easyfind(numbers, 5);
        std::cout << "test 1: 5 is found in the vector." << std::endl;
    }
    catch(const notfoundex& e)
    {
        std::cerr << "test 1: " << e.what() << std::endl;
    }
    try {
        easyfind(numbers, 51);
        std::cout << "test 2: 51 is found in the vector." << std::endl;
    }
    catch(const notfoundex &e){
        std::cerr<< "test 2: " << e.what() << std::endl;
    }
    return 0;
}