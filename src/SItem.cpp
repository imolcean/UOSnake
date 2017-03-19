//
// Created by imolcean on 19.03.17.
//

#include "SItem.h"

SItem::SItem(SItem::Type type, int ttl) : m_type(type), m_counter(ttl) {}

SItem::~SItem() {}

SItem::Type SItem::getType()
{
    return m_type;
}

int SItem::getCounter()
{
    return m_counter;
}

bool SItem::isTemporary()
{
    return m_counter >= 0;
}

bool SItem::isExpired()
{
    return m_counter == 0;
}

void SItem::update()
{
    if(m_counter > 0)
    {
        m_counter--;
    }
}
