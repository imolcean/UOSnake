//
// Created by imolcean on 13.03.17.
//

#include <iostream>
#include "../src/SCoord.h"

bool testCompareEqual()
{
    SCoord v1 = SCoord(0, 0);
    SCoord v2 = SCoord(0, 0);

    return v1 == v2;
}

bool testCompareDifferent()
{
    SCoord v1 = SCoord(0, 0);
    SCoord v2 = SCoord(3, 7);

    return !(v1 == v2);
}

int main(int argc, char** argv)
{
    std::cout << "Hello World!" << std::endl;
}