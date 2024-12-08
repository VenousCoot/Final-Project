#ifndef COMBAT_H
#define COMBAT_H

#include "NPC.h"
#include "character.h"
#include <memory>

class Combat {
public:
    // Function to initiate combat between an NPC and the main character
    static void startCombat(std::unique_ptr<NPC>& npc, main_character& character);

private:
    // Helper function to handle a single combat round
    static void combatRound(NPC& npc, main_character& character);

    // Helper function to resolve the actions of both combatants
    static void resolveActions(NPC& npc, main_character& character, const std::string& npcAction, const std::string& characterAction);
};

#endif // COMBAT_H
