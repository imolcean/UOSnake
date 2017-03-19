//
// Created by imolcean on 17.03.17.
//

#ifndef UOSNAKE_SCELL_H
#define UOSNAKE_SCELL_H


#include "SItem.h"

class SCell
{
private:
    bool m_wall;
    SItem* m_item;

public:
    SCell(bool wall = false);
    SCell(const SCell& other);
    virtual ~SCell();

    SCell& operator=(const SCell& rhs);

    bool isWall() const;

    bool empty() const;
    SItem* getItem() const;
    bool placeItem(SItem::Type type);
    void removeItem();

    friend void swap(SCell& x, SCell& y);
};


#endif //UOSNAKE_SCELL_H
