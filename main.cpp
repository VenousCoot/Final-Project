#include "NPC.h"
#include <iostream>
#include <ctime> // For time()

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Create multiple NPCs with different stats, weights, and initial attack values
    NPC Receptionest("Receptionest", 10, 2, 30, 30, 40, 0, 0);
    NPC TSA_Agent("TSA_Agent", 20, 2, 30, 30, 40, 0, 0);

    // Perform actions for each NPC
    std::cout << Receptionest.getName() << " performs actions:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Receptionest.performAction();
    }

    std::cout << TSA_Agent.getName() << " performs actions:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        TSA_Agent.performAction();
    }



    // Modify health for one NPC
    Receptionest.changeHealth(-3);
    std::cout << Receptionest.getName() << " now has " << Receptionest.getHealth() << " health.\n";

    // Modify attack for one NPC
    Receptionest.changeAttack(-12);
    std::cout << Receptionest.getName() << " now has " << Receptionest.getAttack() << " attack.\n";

    return 0;
}