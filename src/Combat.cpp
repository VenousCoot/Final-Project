#include "Combat.h"
#include "utility.h" // Include the utility header for the print function
#include <thread>
#include <iostream>
#include <cmath>
#include <algorithm>

void Combat::startCombat(std::unique_ptr<NPC>& npc, main_character& character) {
    pLBL(npc->getName() + " Has picked a fight with " + character.get_name() + ".");
    while (npc && npc->getHealth() > 0 && character.get_parameter("hp") > 0) {
        // Perform actions for NPC and main character in parallel threads
        //std::thread thread1(combatRound, std::ref(*npc), std::ref(character));
        combatRound(std::ref(*npc), std::ref(character));
        // Wait for the combat round to finish
        //thread1.join();
    }

    // Check if NPC has zero health to destroy them immediately
    if (npc && npc->getHealth() <= 0) {
        pLBL(npc->getName() + " is defeated!"); // Use letter-by-letter print function
        int dropped_money = rand() % 50;
        pLBL(npc->getName() + " has dropped $" + to_string(dropped_money));
        character.update_parameter("money", dropped_money);
        npc.reset(); // Destroy npc
    }

    if (character.get_parameter("hp") <= 0) {
        pLBL(character.get_name() + " is defeated!"); // Use letter-by-letter print function
        pLBL("GAME OVER!!!!!!");
        return;
    }
}

void Combat::combatRound(NPC& npc, main_character& character) {
    std::string npcAction = npc.performAction();
    std::string characterAction = character.player_action();

    // Resolve actions for both combatants
    resolveActions(npc, character, npcAction, characterAction);
    vector <Item> inv = character.get_inventory();
    bool OTU = true;
        for (auto it = inv.begin(); it != inv.end(); ++it) {
        if (it->isUsed == true) {
            string item_name;
            if(it->damage != 0){
                item_name = "att";
                character.update_parameter(item_name, -(it->damage));
            }
            if(it->health != 0 && it->name != "Meat Shield"){
                item_name = "hp";
                character.update_parameter(item_name, -(it->health));
            }
            if(it->name == "Meat Shield"){
                item_name = "def";
                character.update_parameter(item_name, -(it->health));
            }
            character.remove_item(it->name);
        }
    }

}

void Combat::resolveActions(NPC& npc, main_character& character, const std::string& npcAction, const std::string& characterAction) {
    // Process the character's action first
    if (characterAction == "attack") {
        if (npcAction != "block") {
            npc.changeHealth(-character.get_parameter("att"));
            pLBL(character.get_name() + " attacks " + npc.getName() + " for " + std::to_string(character.get_parameter("att")) + " damage.");
        } else {
            npc.changeHealth(-std::floor(character.get_parameter("att") / 2));
            pLBL(character.get_name() + " attacks " + npc.getName() + " but " + npc.getName() + " blocks, reducing damage to " + std::to_string(std::floor(character.get_parameter("att") / 2)) + ".");
        }
    } else if (characterAction == "block") {
        pLBL(character.get_name() + " blocks.");
    }

    // Now process the NPC's action
    if (npcAction == "attack") {
        if (characterAction != "block") {
            character.update_parameter("hp", -npc.getAttack());
            pLBL(npc.getName() + " attacks " + character.get_name() + " for " + std::to_string(npc.getAttack()) + " damage.");
        } else {
            character.update_parameter("hp", -std::floor(npc.getAttack() / character.get_parameter("def")));
            pLBL(npc.getName() + " attacks " + character.get_name() + " but " + character.get_name() + " blocks, reducing damage to " + std::to_string(std::floor(npc.getAttack() / character.get_parameter("def"))) + ".");
        }
    } else if (npcAction == "block") {
        pLBL(npc.getName() + " blocks.");
    } else if (npcAction == "do nothing") {
        pLBL(npc.getName() + " does nothing.");
    } else if (npcAction == "special attack") {
        character.update_parameter("hp", -npc.getAttack() * 2);
        pLBL(npc.getName() + " uses a special attack on " + character.get_name() + " for " + std::to_string(npc.getAttack() * 2) + " damage.");
    } else if (npcAction == "insta kill") {
        character.update_parameter("hp", -character.get_parameter("hp"));
        pLBL(npc.getName() + " Air Marshal Símon Muler 'escorts' you off the aircraft.");
    }

    pLBL(npc.getName() + " has " + std::to_string(npc.getHealth()) + " health remaining.");
    pLBL(character.get_name() + " has " + std::to_string(character.get_parameter("hp")) + " health remaining.");
}
