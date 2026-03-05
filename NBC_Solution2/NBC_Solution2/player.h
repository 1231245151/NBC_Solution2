#pragma once
#include <string>

class Monster;

using namespace std;

class Player 
{
public:
    virtual void attack() = 0;
    virtual void attack(Monster* monster) = 0;
    void printPlayerStatus();

    // getter 함수
    string getJobName() { return job_name; }
    string getNickname() { return nickname; }
    int getLevel() { return level; }
    int getHP() { return HP; }
    int getMP() { return MP; }
    int getPower() { return power; }
    int getDefence() { return defence; }
    int getAccuracy() { return accuracy; }
    int getSpeed() { return speed; }

    // setter 함수
    void setNickname(string _nickname) { nickname = _nickname; }
    void setHP(int _HP) { HP = _HP; }
    void setMP(int _MP) { MP = _MP; }
    void setPower(int _power) { power = _power; }
    void setDefence(int _defence) { defence = _defence; }
    void setAccuracy(int _accuracy) { accuracy = _accuracy; }
    void setSpeed(int _speed) { speed = _speed; }

protected:
    string job_name;
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;

public:
    Player(string _nickname, string _job, int _hp = 30, int _mp = 30, int _pwr = 10, int _def = 10, int _acc = 10, int _spd = 10);
    ~Player();
};