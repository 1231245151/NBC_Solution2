#pragma once
#include "player.h"

class Magician :
    public Player
{
public:
    virtual void attack();
    virtual void attack(Monster* monster);

public:
    Magician(string _nickname);
    ~Magician();

};

