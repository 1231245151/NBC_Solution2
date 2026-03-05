#include "thief.h"
#include <iostream>
#include "monster.h"


Thief::Thief(string _nickname)
	:Player(_nickname, "Thief", 20, 10, 11, 10, 15, 30)
{
}

Thief::~Thief()
{
}

void Thief::attack()
{
	cout << "단검을 쌍수로 휘두릅니다!" << endl;
}

void Thief::attack(Monster* monster)
{
	int mdef = monster->getDefence();
	int mHP = monster->getHP();
	string mname = monster->getName();

	// 데미지 계산
	int demage = power - mdef;
	demage /= 5;
	if (demage <= 0)
		demage = 1;

	// 문장 출력
	cout << "단검을 휘두릅니다!" << mname << "에게 " << demage << "피해!" << endl;
	mHP -= demage;
	cout << "단검을 휘두릅니다!" << mname << "에게 " << demage << "피해!" << endl;
	mHP -= demage;
	cout << "단검을 휘두릅니다!" << mname << "에게 " << demage << "피해!" << endl;
	mHP -= demage;
	cout << "단검을 휘두릅니다!" << mname << "에게 " << demage << "피해!" << endl;
	mHP -= demage;
	cout << "단검을 휘두릅니다!" << mname << "에게 " << demage << "피해!" << endl;
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