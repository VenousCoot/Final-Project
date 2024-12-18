#include "Items.h"
#include <iostream>
#include "character.h"
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Constructor
Item::Item(std::string itemName, std::string itemCategory, int itemDamage, int itemHealth, int itemCost, bool shopItem, bool OTU, bool used)
        : name(itemName), category(itemCategory), damage(itemDamage), health(itemHealth), cost(itemCost), isShopItem(shopItem), isOTU(OTU), isUsed(used){}

std::string Item::get_name(){
    return name;
}

// Display item information
void Item::display() const {
    std::cout << "Name: " << name
            << ", Damage: " << damage
            << ", Health: " << health
            << ", Cost: " << cost
            << (isShopItem ? " (Shop Item)" : " (Drop Item)") << std::endl;
}

// Initialize grouped items
void initializeGroupedItems(std::vector<Item>& shields, std::vector<Item>& swords, std::vector<Item>& potions) {
    // Shields
    shields.push_back(Item("Money", "Shields", 0, 3, 0, false, false, false)); // Base stat increase
    shields.push_back(Item("Security Vest", "Shields", 0, 2, 0, false, false, false)); //Base stat increase
    shields.push_back(Item("Meat Shield", "Shields", 0, 5, 0, false, true, false)); //One time use

    // Swords
    swords.push_back(Item("Stanley Cup", "Swords", 1, 0, 0, false, false, false)); //Base stat increase
    swords.push_back(Item("TSA Beat-stick", "Swords", 1, 0, 0, false, false, false)); //Base stat increase
    swords.push_back(Item("Stun Gun", "Swords", 2, 0, 0, false, false, false)); //Base stat increase
    swords.push_back(Item("Laptop Bag", "Swords", 2, 0, 0, false, false, false)); //Automatically Applied
    swords.push_back(Item("TSA Service Weapon", "Swords", 12, 0, 0, false, true, false)); //OTU

    // Potions
    potions.push_back(Item("Advil", "Shields", 0, 1, 0, false, false, false)); //Increases MAXIMUM HEALTH by 1
    potions.push_back(Item("Half a Bottle of Whiskey", "Potions", 3, 0, 0, false, true, false)); //OTU
    potions.push_back(Item("Slightly Browned Banana", "Potions", 0, 3, 0, false, true, false)); // OTU
    potions.push_back(Item("Shake Shack", "Potions", 0, 6, 0, false, true, false)); // OTU
    potions.push_back(Item("Stylish Hat", "Potions", 0, 0, 0, false, false, false)); // Can't Use just exists in the inventory
    potions.push_back(Item("Suspicious Ticking Suitcase", "Potions", 0, 0, 0, false, true, false)); // OTU
}

// Initialize shop items
void initializeShopItems(std::vector<Item>& shopItems) {
    shopItems.push_back(Item("Laptop Bag", "Swords", 2, 0, 60, false, false, false));
    shopItems.push_back(Item("Meat Shield", "Shields", 0, 5, 60, true, true, false));
    shopItems.push_back(Item("Shake Shack", "Potions", 0, 6, 20, true, false, false));
    shopItems.push_back(Item("First Class Boarding Pass", "Special", 0, 0, 140, true, false, false));
}
//
// Display grouped items
int purchaseItem(std::vector<Item>& shopItems, int playerCurrency, main_character& player) {
    std::cout << "Your Currency: $" << playerCurrency << std::endl;

    while (true) {
        for (size_t i = 0; i < shopItems.size(); ++i) {
            std::cout << i + 1 << ". ";
            shopItems[i].display();
        }

        std::string choice;
        int itemIndex;
        bool validInput = false;

        while (!validInput) {
            std::cout << "Choose an item to buy (1-" << shopItems.size() << ") or press (5) to exit the shop without buying anything: ";
            std::cin >> choice;

            try {
                itemIndex = std::stoi(choice) - 1;
                if (itemIndex >= -1 && itemIndex < static_cast<int>(shopItems.size())) {
                    validInput = true;
                } else {
                    std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
                }
            } catch (const std::invalid_argument&) {
                std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
            }
        }

        if (itemIndex == 4) {  // User chose to exit (5 - 1 = 4)
            std::cout << "ShopKeep: Thank you for coming!!" << std::endl;
            break;
        }

        Item& selectedItem = shopItems[itemIndex];
        if (playerCurrency >= selectedItem.cost) {
            playerCurrency -= selectedItem.cost;
            std::cout << "You bought: " << selectedItem.name << " for $" << selectedItem.cost << std::endl;
            std::cout << "Remaining Currency: $" << playerCurrency << std::endl;

            if (selectedItem.name == "Laptop Bag") {
                std::cout << "Equipped Laptop Bag: ATK stat increased by 2!" << std::endl;
                player.apply_item(selectedItem);
            } else {
                player.add_item(selectedItem);
            }

            // Remove the purchased item from the shop
            shopItems.erase(shopItems.begin() + itemIndex);
        } else {
            std::cout << "Not enough currency to buy this item." << std::endl;
        }

        if (shopItems.empty()) {
            std::cout << "ShopKeep: All items sold out! Have a nice day!" << std::endl;
            break;
        }

        std::string continueChoice;
        bool validContinueChoice = false;

        while (!validContinueChoice) {
            std::cout << "Would you like to buy another item? (1 for yes, 2 for no): ";
            std::cin >> continueChoice;

            if (continueChoice == "1" || continueChoice == "2") {
                validContinueChoice = true;
            } else {
                std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
            }
        }

        if (continueChoice == "2") {
            std::cout << "ShopKeep: Have a nice day!" << std::endl;
            break;
        }
    }

    return playerCurrency;
}



