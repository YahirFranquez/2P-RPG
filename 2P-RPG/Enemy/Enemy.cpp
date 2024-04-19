//
// Created by Victor Navarro on 15/02/24.
//

#include "Enemy.h"
#include "../Utils.h"
#include <iostream>
#include <cstring> 

using namespace std;
using namespace combat_utils;


Enemy::Enemy(const char* _name, int _health, int _attack, int _defense, int _speed, int _experience)
: Character(_name, _health, _attack, _defense, _speed, false) {
    experience = _experience;
}

void Enemy::doAttack(Character *target) {
    target->takeDamage(getRolledAttack(attack));
}

void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;
    health -= trueDamage;

    cout << getName() << " took " << trueDamage << " damage!" << endl;
    if (health <= 0) {
        cout << getName() << " has been defeated!" << endl;
    }
}

int Enemy::getExperience() {
    return experience;
}

Character* Enemy::selectTarget(vector<Player*> possibleTargets) {
    // Target with less health
    int lessHealth = 9999999;
    Character* target = nullptr;
    for (auto character : possibleTargets) {
        if (character->getHealth() < lessHealth) {
            lessHealth = character->getHealth();
            target = character;
        }
    }
    return target;
}

Action Enemy::takeAction(vector<Player*> partyMembers) {
    Action currentAction;
    currentAction.speed = getSpeed();

    Character* target = selectTarget(partyMembers);
    currentAction.target = target;
    currentAction.action = [this, target](){
        doAttack(target);
    };

    return currentAction;
}
