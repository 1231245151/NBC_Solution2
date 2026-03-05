#include "Magician.h"
#include <iostream>
#include "monster.h"

Magician::Magician(string _nickname)
	:Player(_nickname, "Magician", 25, 30, 30, 10, 8, 8)
{
}

Magician::~Magician()
{
}

void Magician::attack()
{
	cout << "주문을 시전하여 마법 화살을 쏩니다!" << endl;
}

void Magician::attack(Monster* monster)
{
	int mdef = monster->getDefence();
	int mHP = monster->getHP();
	string mname = monster->getName();

	// 데미지 계산
	int demage = power - mdef;
	if (demage <= 0)
		demage = 1;

	// 문장 출력
	cout << "마법 화살을 쏩니다!" << mname << "에게 " << demage << "피해!" << endl;

	// hp반영
	mHP -= demage;
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