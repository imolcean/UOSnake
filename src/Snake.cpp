//
// Created by imolcean on 13.03.17.
//

#include <map>
#include <set>
#include <algorithm>
#include "Snake.h"

Snake::Snake(SCell* start) : m_direction(Snake::Direction::NONE), m_toGrow(0)
{
    m_body.push_back(start);
}

Snake::~Snake() {}

int Snake::size() const
{
    // Size of the snake will definitely fit valid an int
    return (int) m_body.size();
}

SCell* Snake::getHead() const
{
    return m_body.front();
}

Snake::Direction Snake::getDirection() const
{
    return this->m_direction;
}

void Snake::setDirection(Snake::Direction direction)
{
    std::map<Direction, std::set<Direction>> valid;

    valid[Direction::NONE]  = {Direction::LEFT, Direction::RIGHT, Direction::UP, Direction::DOWN};
    valid[Direction::UP]    = {Direction::LEFT, Direction::RIGHT};
    valid[Direction::DOWN]  = {Direction::LEFT, Direction::RIGHT};
    valid[Direction::LEFT]  = {Direction::UP, Direction::DOWN};
    valid[Direction::RIGHT] = {Direction::UP, Direction::DOWN};

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
    if(getHead()->isWall())
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