#include "input.h"
#include <iostream>

int numericalInput()
{
    std::cout << ">> ";
    int x;
    std::cin >> x;
    return x;
}