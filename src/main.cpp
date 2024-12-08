#include <string>
#include <iostream>
#include "NPC.h"
#include <ctime>
#include "items.h"
#include <vector>




using namespace std;


int main()
{
	cout <<"Welcome to Hell Adventurer, this is Newark Liberty International Airport!" << endl;
	cout <<"Voted the worst airport in the United States according to AirHelp's Global Airport Ranking (2019)." << endl;
	cout <<"It looks like you have a flight departing in ... 1 hour!! Better Hurry!" << endl;




        std::vector<Item> shields;
        std::vector<Item> swords;
        std::vector<Item> potions;
        std::vector<Item> shopItems;

        int playerCurrency = 150;          // Starting currency for the player
        int playerDamageReduction = 0;  // Default damage reduction

        // Initialize items
        initializeGroupedItems(shields, swords, potions);
        initializeShopItems(shopItems);

        // Display grouped items
        std::cout << "======================================== Dropped Items ====================================================" << std::endl;
        displayGroupedItems("Shield Items", shields);
        displayGroupedItems("Sword Items", swords);
        displayGroupedItems("Potion Items", potions);

        // Display shop items and allow purchasing
        std::cout << "======================================== Shop Items ====================================================" << std::endl;
        purchaseItem(shopItems, playerCurrency, playerDamageReduction);

        // Final player state
        std::cout << "\nFinal Player State:" << std::endl;
        std::cout << "Currency: $" << playerCurrency << ", Damage Reduction: " << playerDamageReduction << std::endl;







    // Seed the random number geerator
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