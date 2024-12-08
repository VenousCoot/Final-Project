#include <string>
#include "NPC.h"
#include <ctime>
#include "Items.h"
#include <vector>
#include "Combat.h"
#include <limits>
#include <memory>
#include "character.h"
#include <iostream>

using namespace std;

// Debug mode if = 1 then will print debugging messages example being object destroying messages
int Debug = 0;

int main()
{
    cout << "Welcome to Hell Adventurer, this is Newark Liberty International Airport!" << endl;
    cout << "Voted the worst airport in the United States according to AirHelp's Global Airport Ranking (2019)." << endl;
    cout << "It looks like you have a flight departing in ... 1 hour!! Better Hurry!" << endl;    

        std::vector<Item> shields;
        std::vector<Item> swords;
        std::vector<Item> potions;
        std::vector<Item> shopItems;

        // int playerCurrency = 150;          // Starting currency for the player
        int playerDamageReduction = 0;  // Default damage reduction

        // Initialize items
        // initializeGroupedItems(shields, swords, potions);
        // initializeShopItems(shopItems);






    // Seed the random number geerator
        srand(static_cast<unsigned>(time(0)));


//        Character Creation
    main_character player;
    player.pick_player_name();

        // Create multiple NPCs with different stats, weights, and initial attack values

    auto Receptionist = make_unique<NPC>("Receptionist", 10, 2, 80, 10, 10, 0, 0);
    auto TSA_Agent = make_unique<NPC>("TSA Agent", 20, 2, 80, 10, 10, 0, 0);




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

    Combat::startCombat(Receptionist, player);

    // Check and print the health of each NPC after combat

    if (Receptionist) {
        cout << Receptionist->getName() << " survived the fight with " << Receptionist->getHealth() << " health remaining."
             << endl;
    }
    if (player.get_parameter("hp") > 0) {
        cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining."
             << endl;
    }




    Combat::startCombat(TSA_Agent, player);

    // Check and print the health of each NPC after combat

    if (TSA_Agent) {
        cout << TSA_Agent->getName() << " survived the fight with " << TSA_Agent->getHealth() << " health remaining."
             << endl;
    }
    if (player.get_parameter("hp") > 0) {
        cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining."
             << endl;
    }

    return 0;
}