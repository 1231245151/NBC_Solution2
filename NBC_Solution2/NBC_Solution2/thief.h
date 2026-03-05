#pragma once
#include "player.h"

class Thief :
    public Player
{
public:
    virtual void attack();
    virtual void attack(Monster* monster);

public:
    Thief(string _nickname);
    ~Thief();

};

