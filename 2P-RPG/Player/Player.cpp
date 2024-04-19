//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"
#include <iostream>
#include <cstring> 

using namespace std;


Player::Player(const char* _name, int _health, int _attack, int _defense, int _speed)
: Character(_name, _health, _attack, _defense, _speed, true) {
    level = 1;
    experience = 0;
}

void Player::doAttack(Character* target) {
    target->takeDamage(attack);
}

void Player::takeDamage(int damage) {
    int trueDamage = damage - defense;
    health -= trueDamage;

    cout << getName() << " took " << trueDamage << " damage!" << endl;

    if(health <= 0) {
        cout << getName() << " has been defeated!" << endl;
    }
}

void Player::levelUp() {
    level++;
    
}

void Player::gainExperience(int exp) {
    experience += exp;
    while (experience >= 100) {
        levelUp();
        experience -= 100; // Si se sobrepasa 100, conserva el exceso para el próximo nivel.
    }
}

Character* Player::selectTarget(vector<Enemy*> possibleTargets) {
    int selectedTarget = 0;
    cout << "Select a target: " << endl;
    for (size_t i = 0; i < possibleTargets.size(); i++) {
        cout << i << ". " << possibleTargets[i]->getName() << endl;
    }

    // TODO: Add input validation
    cin >> selectedTarget;
    return possibleTargets[selectedTarget];
}

Action Player::takeAction(vector<Enemy*> enemies) {
    int action = 0;
    cout << "Select an action: " << endl
         << "1. Attack" << endl;

    // TODO: Validate input
    cin >> action;
    Action currentAction;
    Character* target = nullptr;

    switch (action) {
        case 1:
            target = selectTarget(enemies);
            if (target) {
                currentAction.target = target;
                currentAction.action = [this, target]() {
                    doAttack(target);
                };
                currentAction.speed = getSpeed();
            }
            break;
        default:
            cout << "Invalid action" << endl;
            break;
    }

    return currentAction;
}