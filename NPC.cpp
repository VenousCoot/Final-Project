#include "NPC.h"
#include <iostream>
#include <cstdlib>

// Constructor
NPC::NPC(const std::string& npcName, int initialHealth, int initialAttack,
         int attackW, int blockW, int doNothingW, int specialW, int instaW)
        : name(npcName), health(initialHealth), attack(initialAttack),
          attackWeight(attackW), blockWeight(blockW),
          doNothingWeight(doNothingW), specialAttackWeight(specialW), instaKillWeight(instaW) {}

// Get the NPC's name
std::string NPC::getName() const {
    return name;
}

// Get the NPC's health
int NPC::getHealth() const {
    return health;
}

// Get the NPC's initial attack value
int NPC::getAttack() const {
    return attack;
}

// Modify the NPC's health
void NPC::changeHealth(int amount) {
    health += amount;
    if (health < 0) {
        health = 0;
    }
}

// Modify the NPC's attack
void NPC::changeAttack(int amount) {
    attack += amount;
    if (attack < 0) {
        attack = 0;
    }
}

// Perform an action based on weights
void NPC::performAction() const {
    int totalWeight = attackWeight + blockWeight + doNothingWeight + specialAttackWeight + instaKillWeight;
    int randomValue = rand() % totalWeight;

    if (randomValue < attackWeight) {
        std::cout << name << " attacks! Deals " << attack << " damage." << std::endl;
    } else if (randomValue < attackWeight + blockWeight) {
        std::cout << name << " blocks!" << std::endl;
    } else if (randomValue < attackWeight + blockWeight + doNothingWeight) {
        std::cout << name << " does nothing." << std::endl;
    } else if (randomValue < attackWeight + blockWeight + doNothingWeight + specialAttackWeight) {
        std::cout << name << " uses a special attack! Deals " << attack * 2 << " damage!" << std::endl;
    } else {
        std::cout << name << " Air Marshal personally escorts you off of the plane" << std::endl;
    }
}