# ifndef TEST_HPP
# define TEST_HPP

#include <iostream>

template <typename T,typename L, typename F> void iter(T *arr, L len, F func)
{
    for (L i = 0; i < len; i++){
        func(arr[i]);
    }
}
template <typename T> void print(T elm)
{
    std::cout << elm << std::endl;
}


# endif // TEST_HPP