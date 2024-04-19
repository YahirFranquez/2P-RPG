
#include "Character.h"
#include <cstdio>   
#include <cstdlib>  

Character::Character(const char* _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer) {
    strncpy(name, _name, sizeof(name) - 1); 
    name[sizeof(name) - 1] = '\0';         
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
}

char* Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

int Character::getSpeed() {
    return speed;
}

char* Character::toString() {
    static char buffer[256];
    sprintf(buffer, "Name: %s\nHealth: %d\nAttack: %d\nDefense: %d\nSpeed: %d", name, health, attack, defense, speed);
    return buffer;
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::flee(Character* target) {
    if (this->getSpeed() > target->getSpeed())
        return true;

    int chance = rand() % 100;
    return chance > 30;
}
