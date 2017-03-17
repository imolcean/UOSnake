//
// Created by imolcean on 17.03.17.
//

#include "SMap.h"

SMap::SMap(FILE map)
{
    // TODO Read width and height

    int start_x;
    int start_y;
    // TODO Read the start coordinates

    // Allocate memory for the array
    m_cells = new SCell*[m_width];
    for(int i = 0; i < m_width; i++)
    {
        m_cells[i] = new SCell[m_height];
    }

    // TODO Read all the SCells and fill the array with them

    // Set the start position
    m_start = &m_cells[start_x][start_y];
}

SMap::~SMap()
{
    for(int i = 0; i < m_width; i++)
    {
        delete[] m_cells[i];
    }

    delete[] m_cells;
}

int SMap::getWidth() const
{
    return m_width;
}

int SMap::getHeight() const
{
    return m_height;
}

SCell* SMap::getCell(int x, int y) const
{
    if(x < 0 || y < 0 || x > m_width || y > m_height)
    {
        return nullptr;
    }

    return &m_cells[x][y];
}

SCell* SMap::getStart() const
{
    return m_start;
}
