//
// Created by imolcean on 17.03.17.
//

#ifndef UOSNAKE_SCELL_H
#define UOSNAKE_SCELL_H


class SCell
{
private:
    const bool WALL;
    Item* m_item;

public:
    SCell(bool wall);
    ~SCell();

    bool isWall();

    bool empty();
    Item* getItem();
    bool placeItem(Item* item);
    bool removeItem();
};


#endif //UOSNAKE_SCELL_H
