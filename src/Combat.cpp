#include "Combat.h"
#include <thread>
#include <iostream>
#include <cmath>

void Combat::startCombat(NPC& npc1, NPC& npc2) {
    while (npc1.getHealth() > 0 && npc2.getHealth() > 0) {
        // Perform actions for both NPCs in parallel threads
        std::thread thread1(combatRound, std::ref(npc1), std::ref(npc2));
        std::thread thread2(combatRound, std::ref(npc2), std::ref(npc1));

        // Wait for both threads to finish
        thread1.join();
        thread2.join();
    }

    if (npc1.getHealth() <= 0 && npc2.getHealth() <= 0) {
        std::cout << "Both " << npc1.getName() << " and " << npc2.getName() << " are defeated!" << std::endl; }
    else if (npc1.getHealth() <= 0) {
        std::cout << npc1.getName() << " is defeated!" << std::endl; }
    else if (npc2.getHealth() <= 0) {
        std::cout << npc2.getName() << " is defeated!" << std::endl; }
}

void Combat::combatRound(NPC& npc1, NPC& npc2) {
    std::string action1 = npc1.performAction();
    std::string action2 = npc2.performAction();

    // Resolve actions for both NPCs
    resolveActions(npc1, npc2, action1, action2);
}

void Combat::resolveActions(NPC& npc1, NPC& npc2, const std::string& action1, const std::string& action2) {
    if (action1 == "attack" && action2 != "block") {
        npc2.changeHealth(-npc1.getAttack());
        std::cout << npc1.getName() << " attacks " << npc2.getName() << " for " << npc1.getAttack() << " damage." << std::endl;
    } else if (action1 == "attack" && action2 == "block") {
        npc2.changeHealth(-std::floor(npc1.getAttack() / 2));
        std::cout << npc1.getName() << " attacks " << npc2.getName() << " but " << npc2.getName() << " blocks, reducing damage to " << std::floor(npc1.getAttack() / 2) << "." << std::endl;
    } else if (action1 == "block") {
        std::cout << npc1.getName() << " blocks." << std::endl;
    } else if (action1 == "do nothing") {
        std::cout << npc1.getName() << " does nothing." << std::endl;
    } else if (action1 == "special attack") {
        npc2.changeHealth(-npc1.getAttack() * 2);
        std::cout << npc1.getName() << " uses a special attack on " << npc2.getName() << " for " << npc1.getAttack() * 2 << " damage." << std::endl;
    } else if (action1 == "insta kill") {
        npc2.changeHealth(-npc2.getHealth());
        std::cout << npc2.getName() << " is escorted off the plane by air marshal Simon Miller" << "." << std::endl;
    }

    if (action2 == "attack" && action1 != "block") {
        npc1.changeHealth(-npc2.getAttack());
        std::cout << npc2.getName() << " attacks " << npc1.getName() << " for " << npc2.getAttack() << " damage." << std::endl;
    } else if (action2 == "attack" && action1 == "block") {
        npc1.changeHealth(-std::floor(npc2.getAttack() / 2));
        std::cout << npc2.getName() << " attacks " << npc1.getName() << " but " << npc1.getName() << " blocks, reducing damage to " << std::floor(npc2.getAttack() / 2) << "." << std::endl;
    } else if (action2 == "special attack") {
        npc1.changeHealth(-npc2.getAttack() * 2);
        std::cout << npc2.getName() << " uses a special attack on " << npc1.getName() << " for " << npc2.getAttack() * 2 << " damage." << std::endl;
    } else if (action2 == "insta kill") {
        npc1.changeHealth(-npc1.getHealth());
        std::cout << npc1.getName() << " is escorted off the plane by air marshal Simon Miller" << "." << std::endl;
    }
}
