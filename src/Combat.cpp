#include "Combat.h"
#include <thread>
#include <iostream>
#include <cmath>

void Combat::startCombat(std::unique_ptr<NPC>& npc, main_character& character) {
    while (npc && npc->getHealth() > 0 && character.get_parameter("hp") > 0) {
        // Perform actions for NPC and main character in parallel threads
        std::thread thread1(combatRound, std::ref(*npc), std::ref(character));

        // Wait for the combat round to finish
        thread1.join();
    }

    // Check if NPC has zero health to destroy them immediately
    if (npc && npc->getHealth() <= 0) {
        std::cout << npc->getName() << " is defeated!" << std::endl;
        npc.reset(); // Destroy npc
    }

    if (character.get_parameter("hp") <= 0) {
        std::cout << character.get_name() << " is defeated!" << std::endl;
    }
}

void Combat::combatRound(NPC& npc, main_character& character) {
    std::string npcAction = npc.performAction();
    std::string characterAction = character.player_action();

    // Resolve actions for both combatants
    resolveActions(npc, character, npcAction, characterAction);
}

void Combat::resolveActions(NPC& npc, main_character& character, const std::string& npcAction, const std::string& characterAction) {
    // Process the character's action first
    if (characterAction == "attack") {
        if (npcAction != "block") {
            npc.changeHealth(-character.get_parameter("att"));
            std::cout << character.get_name() << " attacks " << npc.getName() << " for " << character.get_parameter("att") << " damage." << std::endl;
        } else {
            npc.changeHealth(-std::floor(character.get_parameter("att") / 2));
            std::cout << character.get_name() << " attacks " << npc.getName() << " but " << npc.getName() << " blocks, reducing damage to " << std::floor(character.get_parameter("att") / 2) << "." << std::endl;
        }
    } else if (characterAction == "block") {
        std::cout << character.get_name() << " blocks." << std::endl;
    }

    // Now process the NPC's action
    if (npcAction == "attack") {
        if (characterAction != "block") {
            character.update_parameter("hp", -npc.getAttack());
            std::cout << npc.getName() << " attacks " << character.get_name() << " for " << npc.getAttack() << " damage." << std::endl;
        } else {
            character.update_parameter("hp", -std::floor(npc.getAttack() / 2));
            std::cout << npc.getName() << " attacks " << character.get_name() << " but " << character.get_name() << " blocks, reducing damage to " << std::floor(npc.getAttack() / 2) << "." << std::endl;
        }
    } else if (npcAction == "block") {
        std::cout << npc.getName() << " blocks." << std::endl;
    } else if (npcAction == "do nothing") {
        std::cout << npc.getName() << " does nothing." << std::endl;
    } else if (npcAction == "special attack") {
        character.update_parameter("hp", -npc.getAttack() * 2);
        std::cout << npc.getName() << " uses a special attack on " << character.get_name() << " for " << npc.getAttack() * 2 << " damage." << std::endl;
    } else if (npcAction == "insta kill") {
        character.update_parameter("hp", -character.get_parameter("hp"));
        std::cout << npc.getName() << " performs an insta kill on " << character.get_name() << "." << std::endl;
    }


        cout << npc.getName() << " has " << npc.getHealth() << " health remaining."
             << endl;


        cout << character.get_name() << " has " << character.get_parameter("hp") << " health remaining."
             << endl;

}
