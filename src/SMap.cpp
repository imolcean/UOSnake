//
// Created by imolcean on 17.03.17.
//

#include "SMap.h"

SMap::SMap(int width, int height) : WIDTH(width), HEIGHT(height)
{
    // Create all the SCells and fill the vector
}

SMap::~SMap()
{
    // Delete all the SCells
}

int SMap::getWidth() const
{
    return WIDTH;
}

int SMap::getHeight() const
{
    return HEIGHT;
}

SCell* SMap::getCell(int x, int y) const
{
    if(x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
    {
        return nullptr;
    }

    // Return the correct SCell
}
