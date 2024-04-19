//
// Created by Victor Navarro on 15/02/24.
//


#pragma once
#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include "../Character/Character.h"
#include "../Enemy/Enemy.h"  
#include "../Combat/Action.h"
#include <vector>


class Enemy;

class Player: public Character {
private:
    int level;
    int experience;

    void levelUp();
public:
    
    Player(const char* _name, int _health, int _attack, int _defense, int _speed);

    void doAttack(Character* target) override;
    void takeDamage(int damage) override;
    Character* selectTarget(std::vector<Enemy*> possibleTargets);
    Action takeAction(std::vector<Enemy*> enemies);

    void gainExperience(int exp);

    
};

#endif // RPG_PLAYER_H

