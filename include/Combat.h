#ifndef COMBAT_H
#define COMBAT_H

#include "NPC.h"

class Combat {
public:
    // Function to initiate combat between two NPCs
    static void startCombat(std::unique_ptr<NPC>& npc1, std::unique_ptr<NPC>& npc2);

private:
    // Helper function to handle a single combat round
    static void combatRound(NPC& npc1, NPC& npc2);

    // Helper function to resolve the actions of both NPCs
    static void resolveActions(NPC& npc1, NPC& npc2, const std::string& action1, const std::string& action2);
};

#endif // COMBAT_H
