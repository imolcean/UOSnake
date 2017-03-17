//
// Created by imolcean on 17.03.17.
//

#ifndef UOSNAKE_SMAP_H
#define UOSNAKE_SMAP_H


#include <vector>
#include "SCell.h"

class SMap
{
private:
    const int WIDTH;
    const int HEIGHT;
    std::vector<SCell*> m_cells;

public:
    SMap(int width, int height);
    ~SMap();

    int getWidth() const;
    int getHeight() const;

    SCell* getCell(int x, int y) const;
};


#endif //UOSNAKE_SMAP_H
