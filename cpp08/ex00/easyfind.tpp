#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& param1, int param2){
    typename T::iterator it;
    it = std::find(param1.begin(),param1.end(), param2);
    if (it == param1.end())
        throw notfoundex();
    return (it);
}