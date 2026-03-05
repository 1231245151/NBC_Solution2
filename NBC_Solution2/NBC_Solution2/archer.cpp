#include "archer.h"
#include <iostream>
#include "monster.h"


Archer::Archer(string _nickname)
	:Player(_nickname, "Archer", 30, 10, 25, 10, 20, 15)
{
}

Archer::~Archer()
{
}

void Archer::attack()
{
	cout << "활을 당겨 화살을 연발로 쏩니다!" << endl;
}

void Archer::attack(Monster* monster)
{
	int mdef = monster->getDefence();
	int mHP = monster->getHP();
	string mname = monster->getName();

	// 데미지 계산
	int demage = power - mdef;
	demage /= 3;
	if (demage <= 0)
		demage = 1;

	// 문장 출력
	cout << "화살을 연발로 쏩니다!" << mname << "에게 " << demage << "피해!" << endl;
	mHP -= demage;
	cout << "화살을 연발로 쏩니다!" << mname << "에게 " << demage << "피해!" << endl;
	mHP -= demage;
	cout << "화살을 연발로 쏩니다!" << mname << "에게 " << demage << "피해!" << endl;
	mHP -= demage;

	// hp반영
	monster->setHP(mHP);

	// hp상황에 따른출력
	if (mHP > 0)
	{
		cout << mname << "의 남은 HP : " << mHP << endl;
	}
	else
	{
		cout << "축하합니다!" << mname << "에게 승리!" << endl;
	}
}