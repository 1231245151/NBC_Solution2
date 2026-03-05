#pragma once
#include "player.h"


class Warrior :
    public Player
{
public:
    virtual void attack();
    virtual void attack(Monster* monster);


public:
    Warrior(string _nickname);
    ~Warrior();
};

