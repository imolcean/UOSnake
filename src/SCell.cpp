//
// Created by imolcean on 17.03.17.
//

#include "SCell.h"

SCell::SCell(bool wall) : WALL(wall) {}

SCell::~SCell() {}

bool SCell::isWall()
{
    return WALL;
}

bool SCell::empty()
{
    return m_item == nullptr;
}

Item* SCell::getItem()
{
    return m_item;
}

bool SCell::placeItem(Item* item)
{
    if(empty())
    {
        m_item = item;
        return true;
    }

    return false;
}

bool SCell::removeItem()
{
    m_item = nullptr;
}


