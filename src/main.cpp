#include <string>
#include "NPC.h"
#include <iostream>
#include <ctime>
#include "Combat.h"
#include <limits>
#include <memory>
#include "character.h"

using namespace std;

// Debug mode if = 1 then will print debugging messages example being object destroying messages
int Debug = 0;

int main()
{
    cout << "Welcome to Hell Adventurer, this is Newark Liberty International Airport!" << endl;
    cout << "Voted the worst airport in the United States according to AirHelp's Global Airport Ranking (2019)." << endl;
    cout << "It looks like you have a flight departing in ... 1 hour!! Better Hurry!" << endl;    

    main_character mc("Default");


        // Seed the random number generator
        srand(static_cast<unsigned>(time(0)));

        // Create multiple NPCs with different stats, weights, and initial attack values
    auto npc_player = make_unique<NPC>("npc_player", 10, 2, 80, 10, 10, 0, 0);
    auto TSA_Agent = make_unique<NPC>("TSA_Agent", 20, 2, 80, 10, 10, 0, 0);




//        TEST CODE FOR NPC FUNCTIONS
//
//        // Perform actions for each NPC
//        std::cout << Receptionest.getName() << " performs actions:" << std::endl;
//        for (int i = 0; i < 5; ++i) {
//            Receptionest.performAction();
//        }
//
//        std::cout << TSA_Agent.getName() << " performs actions:" << std::endl;
//        for (int i = 0; i < 5; ++i) {
//            TSA_Agent.performAction();
//        }
//
//
//
//        // Modify health for one NPC
//        Receptionest.changeHealth(-3);
//        std::cout << Receptionest.getName() << " now has " << Receptionest.getHealth() << " health.\n";
//
//        // Modify attack for one NPC
//        Receptionest.changeAttack(-12);
//        std::cout << Receptionest.getName() << " now has " << Receptionest.getAttack() << " attack.\n";


// TEST CODE FOR COMBAT INTERACTIONS

    Combat::startCombat(npc_player, TSA_Agent);

    // Check and print the health of each NPC after combat
    if (npc_player) {
        cout << npc_player->getName() << " survived the fight with " << npc_player->getHealth()
             << " health remaining." << endl;
    }

    if (TSA_Agent) {
        cout << TSA_Agent->getName() << " survived the fight with " << TSA_Agent->getHealth() << " health remaining."
             << endl;
    }
    return 0;
}