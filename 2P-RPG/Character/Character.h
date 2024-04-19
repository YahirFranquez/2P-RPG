//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>
#include <cstring> 
#include <cstdio>

class Character {
protected:
    char name[40];
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;

public:
  
    Character(const char* _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer) {
        strcpy(name, _name);  
        health = _health;
        attack = _attack;
        defense = _defense;
        speed = _speed;
        isPlayer = _isPlayer;
    }

    virtual void doAttack(Character* target) = 0;
    virtual void takeDamage(int damage) = 0;

   
    void defend() {
        // Incrementar la defensa un 20% solo por el turno actual
        defense += static_cast<int>(defense * 0.2);
    }

    bool flee(Character* target) {
       
        return false;
    }

    
    char* getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getAttack() {
        return attack;
    }

    int getDefense() {
        return defense;
    }

    bool getIsPlayer() {
        return isPlayer;
    }

    int getSpeed() {
        return speed;
    }

    
    char* toString() {
        static char buffer[200];
        sprintf(buffer, "Character: %s, Health: %d, Attack: %d, Defense: %d, Speed: %d, Player: %s", 
                name, health, attack, defense, speed, isPlayer ? "Yes" : "No");
        return buffer;
    }
};

#endif // RPG_CHARACTER_H
