//
// Created by imolcean on 13.03.17.
//

#ifndef UOSNAKE_SNAKE_H
#define UOSNAKE_SNAKE_H


#include <vector>
#include "SDirection.h"
#include "SCell.h"

class Snake
{
private:
    SDirection m_direction;
    std::vector<SCell&> m_body;
    int m_toGrow;

    bool valid() const;
    void grow(int bits = 1);

public:
    Snake(SCell& start);
    virtual ~Snake();

    int size() const;

    SCell& getHead() const;

    SDirection getDirection() const;
    void setDirection(SDirection direction);

    void move();
};


#endif //UOSNAKE_SNAKE_H
