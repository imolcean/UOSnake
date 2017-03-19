//
// Created by imolcean on 17.03.17.
//

#ifndef UOSNAKE_SMAP_H
#define UOSNAKE_SMAP_H


#include <vector>
#include <fstream>
#include "SCell.h"

class SMap
{
private:
    int m_width;
    int m_height;
    SCell* m_start;
    SCell** m_cells;

public:
    SMap(std::ifstream mapFile);
    virtual ~SMap();

    int getWidth() const;
    int getHeight() const;

    SCell* getCell(int x, int y) const;
    SCell* getStart() const;
};


#endif //UOSNAKE_SMAP_H
