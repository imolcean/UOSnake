//
// Created by imolcean on 13.03.17.
//

#include <map>
#include <set>
#include <algorithm>
#include "Snake.h"

Snake::Snake(SCell& start) : m_direction(SDirection::NONE), m_toGrow(0)
{
    m_body.push_back(start);
}

Snake::~Snake() {}

int Snake::size() const
{
    // Size of the snake will definitely fit valid an int
    return (int) m_body.size();
}

SCell& Snake::getHead() const
{
    return m_body.front();
}

SDirection Snake::getDirection() const
{
    return this->m_direction;
}

void Snake::setDirection(SDirection direction)
{
    std::map<SDirection, std::set<SDirection>> valid;

    valid[SDirection::NONE]  = {SDirection::LEFT, SDirection::RIGHT, SDirection::UP, SDirection::DOWN};
    valid[SDirection::UP]    = {SDirection::LEFT, SDirection::RIGHT};
    valid[SDirection::DOWN]  = {SDirection::LEFT, SDirection::RIGHT};
    valid[SDirection::LEFT]  = {SDirection::UP, SDirection::DOWN};
    valid[SDirection::RIGHT] = {SDirection::UP, SDirection::DOWN};

    if(valid[m_direction].find(direction) != valid[m_direction].end())
    {
        m_direction = direction;
    }
}

void Snake::move()
{
    // TODO
}

bool Snake::valid() const
{
    if(getHead().isWall())
    {
        return false;
    }

    if(std::find(m_body.begin() + 1, m_body.end(), getHead()) != m_body.end())
    {
        return false;
    }

    return true;
}

void Snake::grow(int bits)
{
    m_toGrow += bits;
}