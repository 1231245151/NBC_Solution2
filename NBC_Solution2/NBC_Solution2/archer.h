#pragma once
#include "player.h"


class Archer :
    public Player
{
public:
    virtual void attack();
    virtual void attack(Monster* monster);

public:
    Archer(string _nickname);
    ~Archer();
};

