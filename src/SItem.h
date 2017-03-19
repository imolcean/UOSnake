//
// Created by imolcean on 19.03.17.
//

#ifndef UOSNAKE_SITEM_H
#define UOSNAKE_SITEM_H


class SItem
{
private:
    Type m_type;
    int m_counter;

public:
    enum Type
    {
        APPLE,
        CHERRY
    };

    SItem(Type type, int ttl = -1);
    virtual ~SItem();

    SItem::Type getType();
    int getCounter();
    bool isTemporary();
    bool isExpired();

    void update();
};


#endif //UOSNAKE_SITEM_H
