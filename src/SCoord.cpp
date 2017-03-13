//
// Created by imolcean on 13.03.17.
//

#include "SCoord.h"

SCoord::SCoord(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

SCoord::~SCoord() {}

int SCoord::getX() const
{
    return this->m_x;
}

int SCoord::getY() const
{
    return this->m_y;
}

void SCoord::setX(int val)
{
    this->m_x = val;
}

void SCoord::setY(int val)
{
    this->m_y = val;
}

std::ostream& operator<<(std::ostream& os, const SCoord& coord)
{
    os << coord.m_x << " : " << coord.m_y;

    return os;
}

bool operator==(const SCoord& lhs, const SCoord& rhs)
{
    return lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y;
}

bool operator!=(const SCoord& lhs, const SCoord& rhs)
{
    return !(rhs == lhs);
}
