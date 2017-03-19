//
// Created by imolcean on 17.03.17.
//

#include "SCell.h"

SCell::SCell(bool wall) : m_wall(wall), m_item(nullptr) {}

SCell::SCell(const SCell& other) : m_wall(other.isWall()), m_item(other.getItem()) {}

SCell::~SCell() {}

SCell& SCell::operator=(const SCell& rhs)
{
    SCell tmp(rhs);
    swap(*this, tmp);

    return *this;
}

bool SCell::isWall() const
{
    return m_wall;
}

bool SCell::empty() const
{
    return m_item == nullptr;
}

SItem* SCell::getItem() const
{
    return m_item;
}

bool SCell::placeItem(SItem::Type type)
{
    if(empty())
    {
        m_item = new SItem(type);
        return true;
    }

    return false;
}

void SCell::removeItem()
{
    if(!empty())
    {
        delete m_item;
        m_item = nullptr;
    }
}

void swap(SCell& x, SCell& y)
{
    SCell tmp(x);

    x.m_wall = y.m_wall;
    x.m_item = y.m_item;

    y.m_wall = tmp.m_wall;
    y.m_item = tmp.m_item;
}


