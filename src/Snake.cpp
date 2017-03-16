//
// Created by imolcean on 13.03.17.
//

#include <map>
#include <set>
#include "Snake.h"

Snake::Snake(SCoord start, SDirection direction) : m_direction(direction), m_toGrow(0)
{
    /* TODO Создать голову на стартовой позиции,
     * хвост и промежуточный сегмент
     */
}

Snake::~Snake() {}

int Snake::size() const
{
    // TODO Возвразать размер змеи
    return 0;
}

SCoord Snake::getHead()
{
    return *m_body.begin();
}

SDirection Snake::getDirection() const
{
    return this->m_direction;
}

void Snake::setDirection(SDirection direction)
{
    std::map<SDirection, std::set<SDirection>> valid;

    valid[SDirection::UP] = {SDirection::LEFT, SDirection::RIGHT};
    valid[SDirection::DOWN] = {SDirection::LEFT, SDirection::RIGHT};
    valid[SDirection::LEFT] = {SDirection::UP, SDirection::DOWN};
    valid[SDirection::RIGHT] = {SDirection::UP, SDirection::DOWN};

    if(valid[m_direction].find(direction) != valid[m_direction].end())
    {
        m_direction = direction;
    }
}

bool Snake::into() const
{
    // TODO
    return false;
}

void Snake::grow(int bits)
{
    m_toGrow += bits;
}

int Snake::getGrowth() const
{
    return m_toGrow;
}

void Snake::move()
{
    // TODO
}
