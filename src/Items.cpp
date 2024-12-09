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
    shopItems.push_back(Item("Laptop Bag", "Swords", 2, 0, 0, false, false, false));
    shopItems.push_back(Item("Meat Shield", "Shields", 0, 5, 60, true, true, false));
    shopItems.push_back(Item("Shake Shack", "Potions", 0, 6, 20, true, true, false));
    shopItems.push_back(Item("First Class Boarding Pass", "Special", 0, 0, 140, true, false, false));
}

// Display grouped items
void displayGroupedItems(const std::string& category, const std::vector<Item>& items) {
    std::cout << "=== " << category << " ===" << std::endl;
    for (const auto& item : items) {
        item.display();
    }
    std::cout << std::endl;
}

// Purchase items from the shop
int purchaseItem(std::vector<Item>& shopItems, int playerCurrency, main_character& player) {
    std::cout << "Your Currency: $" << playerCurrency << std::endl;
    for (size_t i = 0; i < shopItems.size(); ++i) {
        std::cout << i + 1 << ". ";
        shopItems[i].display();
    }

    int choice;
    std::cout << "Choose an item to buy (1-" << shopItems.size() << "): ";
    std::cin >> choice;
    bool valid_option = false;
    while(!valid_option){
        if (choice >= 1 && choice <= shopItems.size()) {
            Item& selectedItem = shopItems[choice - 1];
                playerCurrency -= selectedItem.cost;
                std::cout << "You bought: " << selectedItem.name << " for $" << selectedItem.cost << std::endl;
                std::cout << "Remaining Currency: $" << playerCurrency << std::endl;
                valid_option = true;

            if (selectedItem.name == "Security Vest") {
                std::cout << "Equipped Security Vest: DEF stat increaded by 2!" << std::endl;
                for (Item& item : shopItems) {
                    if (item.name == selectedItem.name) {
                        player.apply_item(item);
                        break;
                    }
                }
            } else if (selectedItem.name == "Meat Shield") {
                std::cout << "Equipped Meat Suit: DEF stat increaded by 4!" << std::endl;
                for (Item& item : shopItems) {
                    if (item.name == selectedItem.name) {
                        player.apply_item(item);
                        break;
                    }
                }
            } else {
                for (const auto& item : shopItems) {
                    if (item.name == selectedItem.name) {
                        player.add_item(item);
                        break;
                    }
                }
            }
        } else {
            std::cout << "Invalid choice!" << std::endl;
            valid_option = false;
        }
    }
    return playerCurrency;
}