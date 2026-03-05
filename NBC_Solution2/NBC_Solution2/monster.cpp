#include "monster.h"

#include <iostream>
#include "player.h"


Monster::Monster(string name)
	: name(name)
	, HP(10)
	, power(30)
	, defence(10)
	, speed(10)
{

}

void Monster::attack(Player* player)
{
	int phit = player->getDefence();
	int pHP = player->getHP();
	string pname = player->getNickname();

	// 방어력과 공격력차이에 의한 피해연산
	phit = power - phit;
	if (phit <= 0)
		phit = 1;

	pHP -= phit;
	// 플레이어에게 몇의 데미지를 준건지 건네준다.
	cout << name << "의 공격!" << pname << "에게 " << phit << "데미지!" << endl;
	player->setHP(pHP);

	if (pHP > 0)
	{
		cout << pname << "의 남은 HP : " << pHP << endl;
	}
	else
	{
		cout << pname << "는 HP가 없어 눈앞이 깜깜해졌다. 패배!" << endl;
	}
}