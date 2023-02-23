#pragma once 
#include <iostream>

enum class ERace
{
    ORK = 1,
    TROLL = 2,
    GOBBLIN = 3
};

struct Stats
{
    ERace race;
    int healthPoints;
    int attackPoints;
    int defensePoints;
    int speed;
};

class Monster
{
public:

    inline Monster(Stats _stats)
        : race(_stats.race), healthPoints(_stats.healthPoints), 
        attackPoints(_stats.attackPoints), defensePoints(_stats.defensePoints), speed(_stats.speed)
    {

    };

    //ohne Stats struct
    //inline Monster(ERace _race, int _hp, int _ap, int _dp, int _s)
    //    : race(_race), healthPoints(_hp), attackPoints(_ap), defensePoints(_dp), speed(_s)
    //{
    //
    //};

    ~Monster();

    void Attack(Monster _monsterA, Monster _monsterB);

    void WhoAttacksFirst(Monster _monsterA, Monster _monsterB);

    inline std::string enum_to_string(ERace t)
    {
        switch (t)
        {
        case ERace::ORK:
            return "ORK";
        case ERace::TROLL:
            return "TROLL";
        case ERace::GOBBLIN:
            return "GOBBLIN";
        default:
            return "INVALID ENUM";
        };
    }

    const ERace GetRace(void) const;
    void SetRace(const ERace& _race);

    const int GetHealthPoints(void) const;
    void SetHealthPoints(const int& _hp);

    const int GetAttackPoints(void) const;
    void SetAttackPoints(const int& _ap);

    const int GetDefensePoints(void) const;
    void SetDefensePoints(const int& _dp);

    const int GetSpeedPoints(void) const;
    void SetSpeedPoints(const int& _s);


private:
    ERace race;
    int healthPoints;
    int attackPoints;
    int defensePoints;
    int speed;
};
