#include <string>
#include <iostream>
#include "room.h"
#include "NPC.h"
#include <ctime>
#include "Items.h"
#include <vector>
#include "Combat.h"
#include <limits>
#include <memory>
#include "character.h"
#include <iostream>
#include "ItemChoice.h"
#include "utility.h"

using namespace std;

// Debug mode if = 1 then will print debugging messages example being object destroying messages
int Debug = 0;

// Create the object "Player"
main_character player;

// Create objects for all the rooms:
Lobby lobby;
Security security;
// Terminal terminal;
// Gate gate;
// Plane plane;

// Initialize items for shop demo:
vector<Item> shields;
vector<Item> swords;
vector<Item> potions;
vector<Item> shopItems;

int main()
{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INTRODUCTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    cout <<"==================================================================="<< endl;
    printLetterByLetter("Welcome to Hell Adventurer, this is Newark Liberty International Airport!");
    printLetterByLetter("Voted the worst airport in the United States according to AirHelp's Global Airport Ranking (2019).");
    printLetterByLetter("It looks like you have a flight departing in ... 1 hour!! Better Hurry!");
    cout <<"===================================================================" << endl;
    // int playerCurrency = 150;          // Starting currency for the player
    int playerDamageReduction = 0;  // Default damage reduction

    srand(static_cast<unsigned>(time(0)));    // Seed the random number geerator

    player.pick_player_name();
    cout <<"===================================================================" << endl;
    cout <<"Stats:" << endl;
    player.display_all_parameters();
    cout << "Press Enter to continue...";
    cin.get(); // Waits for the user to press Enter

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INTRO END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STAGE LOBBY  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	lobby.enter();
    auto Receptionist = make_unique<NPC>("Receptionist", 10, 2, 80, 10, 10, 0, 0);
    cout << "Press Enter to continue...";
    cin.get(); // Waits for the user to press Enter;

    Combat::startCombat(Receptionist, player); // Start combat between player and lobby NPC

    // Check and print the health of each NPC after combat

    if (Receptionist) {
        cout << Receptionist->getName() << " survived the fight with " << Receptionist->getHealth() << " health remaining."
            << endl;
    }
    if (player.get_parameter("hp") > 0) {
        cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining."
            << endl;
    }







    




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




    cout <<"===================================================================" << endl;
    cout << "DEMO FOR LOOT DROP " << endl;
    cout <<"===================================================================" << endl;
    std::cout << "Press Enter to continue...";
    std::cin.get(); // Waits for the user to press Enter;
    LobbyItems(player);
    

    cout <<"===================================================================" << endl;
    cout << "DEMO FOR SHOP" << endl;
    cout <<"===================================================================" << endl;
    std::cout << "Press Enter to continue...";
    std::cin.get(); // Waits for the user to press Enter;

    initializeShopItems(shopItems);
    int money;
    money = purchaseItem(shopItems, player.get_parameter("money"), player);
    player.set_parameter("money",money);

    cout << "\nFinal Player State:" << endl;
    cout << "Currency: $" << player.get_parameter("money") << endl;

    auto TSA_Agent = make_unique<NPC>("TSA Agent", 20, 2, 80, 10, 10, 0, 0);



    cout <<"===================================================================" << endl;
    cout << "Security Demo (BETWEEN PLAYER AND TSA AGENT (ALSO USE ITEMS HERE))" << endl;
    cout <<"===================================================================" << endl;

    security.enter();

    cout <<"===================================================================" << endl;
    cout << "DEMO FOR COMBAT (BETWEEN PLAYER AND TSA AGENT (ALSO USE ITEMS HERE))" << endl;
    cout <<"===================================================================" << endl;
    std::cout << "Press Enter to continue...";
    std::cin.get(); // Waits for the user to press Enter;



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



    std::cout << "Press Enter to continue...";
    std::cin.get(); // Waits for the user to press Enter;

    return 0;
}