#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include "Monster.h"

//Hinfällig weil im header eine initializer list angelegt ist
//Monster::Monster(Stats _stats)
//{
//};
// 
//Monster::Monster(ERace _race, int _hp, int _ap, int _dp, int _s)
//{
//}

Monster::~Monster()
{
    //if (race != nullptr)
    //{
    //    delete race;
    //    race = nullptr;
    //}
}

void Monster::Attack(Monster _monsterA, Monster _monsterB)
{
    int counter = 0;
    std::stringstream sStream;
    //std::stringstream* pSStream = &sStream;

    // Angriff ausführen solange HP nicht 0
    do
    {
        counter++;

        sStream << "\n" << counter << ".Runde:";
        std::string sText = sStream.str();
        std::cout << sText;
        sText.clear();
        sStream.str(std::string());

        //Angriff schnelleres Monster
        if (_monsterA.GetAttackPoints() > _monsterB.GetDefensePoints())
        {
            sStream << "\n" << _monsterA.enum_to_string(_monsterA.GetRace()) << " attakiert.";
            sText = sStream.str();
            std::cout << sText;
            sText.clear();
            sStream.str(std::string());

            if (_monsterA.GetAttackPoints() - _monsterB.GetDefensePoints() <= 0)
            {
                _monsterA.attackPoints = 0;

                sStream << "\nDie übrigen HP vom " << _monsterB.enum_to_string(_monsterB.GetRace()) << " sind" << _monsterB.GetHealthPoints() << ".";
                sText = sStream.str();
                std::cout << sText;
                sText.clear();
                sStream.str(std::string());
                sStream << "\nDie übrigen HP vom " << _monsterA.enum_to_string(_monsterA.GetRace()) << " sind" << _monsterA.GetHealthPoints() << ".";
                sText = sStream.str();
                std::cout << sText;
                sText.clear();
                sStream.str(std::string());
            }
            else
            {
                _monsterB.healthPoints = _monsterB.healthPoints - (_monsterA.attackPoints - _monsterB.defensePoints);

                sStream << "\nDie übrigen HP vom " << _monsterB.enum_to_string(_monsterB.GetRace()) << " sind" << _monsterB.GetHealthPoints() << ".";
                sText = sStream.str();
                std::cout << sText;
                sText.clear();
                sStream.str(std::string());
                sStream << "\nDie übrigen HP vom " << _monsterA.enum_to_string(_monsterA.GetRace()) << " sind" << _monsterA.GetHealthPoints() << ".";
                sText = sStream.str();
                std::cout << sText;
                sText.clear();
                sStream.str(std::string());

            }
        }
        if (_monsterB.healthPoints <= 0)
        {
            sStream << "\n" << _monsterB.enum_to_string(_monsterB.GetRace()) << " wurde nach " << counter << " Runden besiegt.\n";
            sText = sStream.str();
            std::cout << sText;
            sText.clear();
            sStream.str(std::string());
            break;
        }

        //Angriff langsameres Monster
        if (_monsterB.GetAttackPoints() > _monsterA.GetDefensePoints())
        {
            sStream << "\n" << _monsterB.enum_to_string(_monsterB.GetRace()) << " attakiert.";
            sText = sStream.str();
            std::cout << sText;
            sText.clear();
            sStream.str(std::string());

            if (_monsterB.attackPoints - _monsterA.defensePoints <= 0)
            {
                _monsterB.attackPoints = 0;

                sStream << "\nDie übrigen HP vom " << _monsterA.enum_to_string(_monsterA.GetRace()) << " sind" << _monsterA.GetHealthPoints() << ".";
                sText = sStream.str();
                std::cout << sText;
                sText.clear();
                sStream.str(std::string());
                sStream << "\nDie übrigen HP vom " << _monsterB.enum_to_string(_monsterB.GetRace()) << " sind" << _monsterB.GetHealthPoints() << ".";
                sText = sStream.str();
                std::cout << sText;
                sText.clear();
                sStream.str(std::string());

            }
            else
            {
                _monsterA.healthPoints = _monsterA.healthPoints - (_monsterB.attackPoints - _monsterA.defensePoints);
                sStream << "\nDie übrigen HP vom " << _monsterA.enum_to_string(_monsterA.GetRace()) << " sind" << _monsterA.GetHealthPoints() << ".";
                sText = sStream.str();
                std::cout << sText;
                sText.clear();
                sStream.str(std::string());
                sStream << "\nDie übrigen HP vom " << _monsterB.enum_to_string(_monsterB.GetRace()) << " sind" << _monsterB.GetHealthPoints() << ".";
                sText = sStream.str();
                std::cout << sText;
                sText.clear();
                sStream.str(std::string());
            }
        }
        if (_monsterA.GetHealthPoints() <= 0)
        {
            sStream << "\n" << _monsterA.enum_to_string(_monsterA.GetRace()) << " wurde nach " << counter << " Runden besiegt.\n";
            sText = sStream.str();
            std::cout << sText;
            sText.clear();
            sStream.str(std::string());
            break;
        }

        //Wenn Angriff von dem einen höher als Verteidigung vom andern für beide Monster
        if (_monsterA.GetAttackPoints() < _monsterB.GetDefensePoints() && _monsterB.GetAttackPoints() < _monsterA.GetDefensePoints())
        {
            sStream << "\nDieser Kampf geht unentschieden aus!\n";
            sText = sStream.str();
            std::cout << sText;
            sText.clear();
            sStream.str(std::string());
            break;
        }


    } while (_monsterA.GetHealthPoints() > 0 && _monsterB.GetHealthPoints() > 0);
}

void Monster::WhoAttacksFirst(Monster _monsterA, Monster _monsterB)
{

    if (_monsterA.GetSpeedPoints() > _monsterB.GetSpeedPoints())
    {
        Monster::Attack(_monsterA, _monsterB);
    }


    if (_monsterA.GetSpeedPoints() < _monsterB.GetSpeedPoints())
    {
        Monster::Attack(_monsterB, _monsterA);
    }

    if (_monsterA.GetSpeedPoints() == _monsterB.GetSpeedPoints())
    {
        std::cout << "Beide Monster sind gleich schnell, daher beginnt das 1.Monster!\n";
        Monster::Attack(_monsterA, _monsterB);
    }
}

const ERace Monster::GetRace(void) const
{
    return race;
}
void Monster::SetRace(const ERace& _race)
{
    race = _race;
}

const int Monster::GetHealthPoints(void) const
{
    return healthPoints;
}
void Monster::SetHealthPoints(const int& _hp)
{
    healthPoints = _hp;
}

const int Monster::GetAttackPoints(void) const
{
    return attackPoints;
}
void Monster::SetAttackPoints(const int& _ap)
{
    attackPoints = _ap;
}

const int Monster::GetDefensePoints(void) const
{
    return defensePoints;
}
void Monster::SetDefensePoints(const int& _dp)
{
    defensePoints = _dp;
}

const int Monster::GetSpeedPoints(void) const
{
    return speed;
}
void Monster::SetSpeedPoints(const int& _s)
{
    speed = _s;
}
