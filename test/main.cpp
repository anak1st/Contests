/**
 * @author: XiaFan
 * @date: 2023-12-30 21:46
 */
#include <array>
#include <chrono>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory_resource>
#include <ranges>
#include "other/Tracknew.hpp"


int main()
{
    int i = 1;

    int j = ++i+i++;

    std::cout << j << std::endl;
}