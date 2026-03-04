# ifndef TEST_HPP
# define TEST_HPP

#include <iostream>

template <typename T>void myswap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T> T mymax(T &a, T &b)
{
    return (a > b) ? a : b;
}

template <typename T> T mymin(T &a, T &b)
{
    return (a < b) ? a : b;
}

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