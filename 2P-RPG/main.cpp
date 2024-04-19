#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"

using std::vector;

int main() {
    
    Player *player = new Player("Victor", 100, 15, 10, 20);
    Enemy *enemy = new Enemy("Goblin", 50, 5, 5, 15, 10);
    Enemy *enemy2 = new Enemy("Orc", 75, 10, 8, 10, 20);

    vector<Character*> participants;

  
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    
    Combat *combat = new Combat(participants);
    combat->doCombat();

   
    delete player;
    delete enemy;
    delete combat;

    return 0;
}
