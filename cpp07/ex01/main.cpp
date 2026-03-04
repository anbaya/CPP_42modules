#include <iostream>
#include "header.hpp"




int main() {

    int arr[] = {1, 2, 3, 4, 5};


    iter(arr, 5, ::print<int>);


    return 0;
}