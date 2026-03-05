#include "player.h"

#include <iostream>


Player::Player(string _nickname, string _job, int _hp, int _mp, int _pwr, int _def, int _acc, int _spd)
	: job_name(_job)
	, nickname(_nickname)
	, level(1)
	, HP(_hp)
	, MP(_mp)
	, power(_pwr)
	, defence(_def)
	, accuracy(_acc)
	, speed(_spd)
{


}

Player::~Player()
{
}

void Player::printPlayerStatus()
{
	cout << "------------------------------------" << endl;
	cout << "* 현재 능력치" << endl;
	cout << "닉네임: " << nickname << endl;
	cout << "직업: " << job_name << endl;
	cout << "Lv. " << level << endl;
	cout << "HP: " << HP << endl;
	cout << "MP: " << MP << endl;
	cout << "공격력: " << power << endl;
	cout << "방어력: " << defence << endl;
	cout << "정확도: " << accuracy << endl;
	cout << "속도: " << speed << endl;
	cout << "------------------------------------" << endl;
}