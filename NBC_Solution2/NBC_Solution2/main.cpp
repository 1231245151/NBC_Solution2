#include <iostream>
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
#include "monster.h"
using namespace std;

void Battle(Monster* _monster, Player* _player);

// 메인 함수
int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) 
    {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    while (player == nullptr)
    {
        cout << "선택: ";
        cin >> job_choice;

        switch (job_choice) 
        {
        case 1:
            player = new Warrior(nickname);
            break;
        case 2:
            player = new Magician(nickname);
            break;
        case 3:
            player = new Thief(nickname);
            break;
        case 4:
            player = new Archer(nickname);
            break;
        default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
    }
    player->printPlayerStatus();

    Monster* monster = new Monster("Slime");

    // 전투 개시
    Battle(monster, player);


    if (player != nullptr)
        delete player;

    if (monster != nullptr)
        delete monster;

    return 0;
}

void Battle(Monster* _monster, Player* _player)
{
    cout << "전투가 시작됩니다." << endl;

    if (_monster->getSpeed() <= _player->getSpeed())
        cout << "속도가 높아 선공을 가져갑니다." << endl;
    else
        cout << "속도가 낮아 선공을 빼앗깁니다." << endl;

    int round = 1;

    //전투를 반복한다.
    while (true)
    {
        cout << "==============" << round << "라운드" << "==============" << endl;

        // 속도가 가장 빠른사람이 선공때린다. 동수면 플레이어 우선권
        if (_monster->getSpeed() <= _player->getSpeed())
        {
            // 선빵친다
            _player->attack(_monster);

            // 죽었는지 확인. 죽으면 종료
            if (_monster->getHP() <= 0)
                break;

            // 공격당함
            _monster->attack(_player);

            // 죽었는지 확인. 죽으면 종료
            if (_player->getHP() <= 0)
                break;
        }
        else
        {
            // 선빵당한다
            _monster->attack(_player);

            // 죽었는지 확인. 죽으면 종료
            if (_player->getHP() <= 0)
                break;

            // 공격
            _player->attack(_monster);

            // 죽었는지 확인. 죽으면 종료
            if (_monster->getHP() <= 0)
                break;
        }

        ++round;
    }
}