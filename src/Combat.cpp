#include "Combat.h"
#include "utility.h" // Include the utility header for the print function
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
        printLetterByLetter(npc->getName() + " is defeated!"); // Use letter-by-letter print function
        npc.reset(); // Destroy npc
    }

    if (character.get_parameter("hp") <= 0) {
        printLetterByLetter(character.get_name() + " is defeated!"); // Use letter-by-letter print function
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
            printLetterByLetter(character.get_name() + " attacks " + npc.getName() + " for " + std::to_string(character.get_parameter("att")) + " damage.");
        } else {
            npc.changeHealth(-std::floor(character.get_parameter("att") / 2));
            printLetterByLetter(character.get_name() + " attacks " + npc.getName() + " but " + npc.getName() + " blocks, reducing damage to " + std::to_string(std::floor(character.get_parameter("att") / 2)) + ".");
        }
    } else if (characterAction == "block") {
        printLetterByLetter(character.get_name() + " blocks.");
    }

    // Now process the NPC's action
    if (npcAction == "attack") {
        if (characterAction != "block") {
            character.update_parameter("hp", -npc.getAttack());
            printLetterByLetter(npc.getName() + " attacks " + character.get_name() + " for " + std::to_string(npc.getAttack()) + " damage.");
        } else {
            character.update_parameter("hp", -std::floor(npc.getAttack() / 2));
            printLetterByLetter(npc.getName() + " attacks " + character.get_name() + " but " + character.get_name() + " blocks, reducing damage to " + std::to_string(std::floor(npc.getAttack() / 2)) + ".");
        }
    } else if (npcAction == "block") {
        printLetterByLetter(npc.getName() + " blocks.");
    } else if (npcAction == "do nothing") {
        printLetterByLetter(npc.getName() + " does nothing.");
    } else if (npcAction == "special attack") {
        character.update_parameter("hp", -npc.getAttack() * 2);
        printLetterByLetter(npc.getName() + " uses a special attack on " + character.get_name() + " for " + std::to_string(npc.getAttack() * 2) + " damage.");
    } else if (npcAction == "insta kill") {
        character.update_parameter("hp", -character.get_parameter("hp"));
        printLetterByLetter(npc.getName() + " performs an insta kill on " + character.get_name() + ".");
    }

    printLetterByLetter(npc.getName() + " has " + std::to_string(npc.getHealth()) + " health remaining.");
    printLetterByLetter(character.get_name() + " has " + std::to_string(character.get_parameter("hp")) + " health remaining.");
}
