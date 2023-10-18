#pragma once
#include <iostream>
#include <string>


char GetCorrectChar();


template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((std::cin >> x).fail() || std::cin.peek() != '\n' || x < min || x > max)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Type correct number (" << min << "-" << max << "):";
    }
    return x;
}


