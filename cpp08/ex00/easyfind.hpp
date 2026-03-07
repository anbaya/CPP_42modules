#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class notfoundex : public std::exception
{
    public:
        virtual const char* what() const throw(){
            return "integer not found";
        };
};

template <typename T>
typename T::iterator easyfind(T& param1, int param2);

#include "easyfind.tpp"

#endif //EASYFIND