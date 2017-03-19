//
// Created by imolcean on 17.03.17.
//

#include <iostream>
#include "SMap.h"

SMap::SMap(std::ifstream mapFile)
{
    // Skip the comments
    std::string line;
    while(true)
    {
        mapFile >> line;
        if(line[0] == '#' || line.length() == 0)
        {
            // Ignore the line
            continue;
        }

        break;
    }

    // Read width and height
    int width;
    int height;

    mapFile >> width >> height;

    m_width = width - 1;
    m_height = height - 1;

    // Read the start coordinates
    int start_x;
    int start_y;

    mapFile >> start_x >> start_y;

    // Allocate memory for the array
    m_cells = new SCell*[m_height];
    for(int i = 0; i < m_height; i++)
    {
        m_cells[i] = new SCell[m_width];
    }

    // Read all the SCells and fill the array with them
    int row = 0;
    int col = 0;
    char c;

    while(mapFile.get(c))
    {
        if(col > m_width)
        {
            // Line is over
            col = 0;
            row++;

            if(row > m_height)
            {
                // No more space in the array
                break;
            }
        }

        if(c == ' ')
        {
            m_cells[row][col] = SCell();
        }
        else
        {
            m_cells[row][col] = SCell(true);
        }

        col++;
    }

    if(!mapFile.eof())
    {
        std::cerr << "Error while reading map file" << std::endl;
    }

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
