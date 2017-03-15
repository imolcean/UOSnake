//
// Created by imolcean on 13.03.17.
//

#include "SCoord.h"

SCoord::SCoord(int x, int y) : m_x(x), m_y(y) {}

SCoord::SCoord(const SCoord& other) : m_x(other.getX()), m_y(other.getY()) {}

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

SCoord& SCoord::operator=(const SCoord& rhs)
{
    SCoord tmp(rhs);
    std::swap(*this, tmp);

    return *this;
}

SCoord& SCoord::operator+=(const SCoord& rhs)
{
    m_x += rhs.getX();
    m_y += rhs.getY();

    return *this;
}

SCoord& SCoord::operator-=(const SCoord& rhs)
{
    m_x -= rhs.getX();
    m_y -= rhs.getY();

    return *this;
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

SCoord operator+(SCoord lhs, const SCoord& rhs)
{
    return lhs += rhs;
}

SCoord operator-(SCoord lhs, const SCoord& rhs)
{
    return lhs -= rhs;
}
