//
// Created by imolcean on 13.03.17.
//

#ifndef UOSNAKE_SCOORD_H
#define UOSNAKE_SCOORD_H

#include <ostream>

class SCoord
{
private:
    int m_x;
    int m_y;

public:
    SCoord(int x, int y);
    SCoord(const SCoord& other);
    virtual ~SCoord();

    int getX() const;
    int getY() const;
    void setX(int val);
    void setY(int val);

    SCoord& operator=(const SCoord& rhs);
    SCoord& operator+=(const SCoord& rhs);
    SCoord& operator-=(const SCoord& rhs);

    friend std::ostream& operator<<(std::ostream& os, const SCoord& coord);

    friend bool operator==(const SCoord& lhs, const SCoord& rhs);
    friend bool operator!=(const SCoord& lhs, const SCoord& rhs);

    friend SCoord operator+(SCoord lhs, const SCoord& rhs);
    friend SCoord operator-(SCoord lhs, const SCoord& rhs);
};


#endif //UOSNAKE_SCOORD_H
