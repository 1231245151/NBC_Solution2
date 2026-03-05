#include "warrior.h"
#include <iostream>
#include "monster.h"

Warrior::Warrior(string _nickname)
	:Player(_nickname, "Warrior", 30, 5, 14, 22, 10, 10)
{
}

Warrior::~Warrior()
{
}

void Warrior::attack()
{
	cout << "대검을 휘두릅니다!" << endl;
}

void Warrior::attack(Monster* monster)
{
	// 플레이어의 공격력-몬스터의 방어력을 계산하여 데미지로 정의합니다.
	// 계산된 데미지가 0 이하일 경우, 데미지를 1로 정의합니다.

	// 공격 문장을 출력합니다.
	// - 전사, 마법사: 계산된 데미지로 1회 공격
	// - 궁수: 계산된 데미지/3으로 3회 공격 (소수점 생략)
	// - 도적: 계산된 데미지/5으로 5회 공격 (소수점 생략)
	// - 궁수와 도적의 경우, 3과 5로 나눈 결과가 0이라면 1로 정의합니다.
	// ex) * 슬라임에게 화살로 3의 피해를 입혔다! 3번 출력

	// 몬스터의 setHP를 호출하여 몬스터의 HP-데미지를 계산한 값을 매개변수로 전달합니다.
	// 몬스터의 getHP를 호출 분기문이 실행됩니다.
	// 몬스터가 생존했을 경우 몬스터의 남은 HP 출력
	// 몬스터가 생존하지 못했을 경우 플레이어의 승리 문구 출력

	int mdef = monster->getDefence();
	int mHP = monster->getHP();
	string mname = monster->getName();
	
	// 데미지 계산
	int demage = power - mdef;
	if (demage <= 0)
		demage = 1;

	// 문장 출력
	cout << "대검을 휘두릅니다!" << mname << "에게 " << demage << "피해!" << endl;

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