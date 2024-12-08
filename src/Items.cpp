#include "Items.h"
#include <iostream>

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
    shields.push_back(Item("Money", "Shields", 0, 3, 0, false, false, false));
    shields.push_back(Item("Advil", "Shields", 0, 1, 0, false, false, false)); //Increases MAXIMUM HEALTH by 1
    shields.push_back(Item("Security Vest", "Shields", 0, 2, 0, false, false, false)); //Base stat increase
    shields.push_back(Item("Meat Shield", "Shields", 0, 5, 0, false, false, false)); //One time use
    

    // Swords
    swords.push_back(Item("Stanley Cup", "Swords", 1, 0, 0, false, false, false)); //Base stat increase
    swords.push_back(Item("TSA Beat-stick", "Swords", 1, 0, 0, false, false, false)); //Base stat increase
    swords.push_back(Item("Stun Gun", "Swords", 2, 0, 0, false, false, false)); //Base stat increase
    swords.push_back(Item("Dirty Needle", "Swords", 0, 0, 0, false, false, false)); //Automatically Applied
    swords.push_back(Item("TSA Service Weapon", "Swords", 12, 0, 0, false, true, false)); //OTU

    // Potions
    potions.push_back(Item("Half a Bottle of Whiskey", "Potions", 3, 0, 0, false, false, false)); //OTU
    potions.push_back(Item("Brown Banana", "Potions", 0, 3, 0, false, false, false)); // OTU
    potions.push_back(Item("Shake Shack", "Potions", 0, 6, 0, false, false, false)); // OTU
    potions.push_back(Item("Stylish Hat", "Potions", 0, 0, 0, false, false, false)); // Can't Use just exists in the inventory
    potions.push_back(Item("Suspicious Ticking Suitcase", "Potions", 0, 0, 0, false, false, false)); // OTU
}

// Initialize shop items
void initializeShopItems(std::vector<Item>& shopItems) {
    shopItems.push_back(Item("Dirty Needle", "Swords", 0, 0, 70, true, false, false));
    shopItems.push_back(Item("Meat Shield", "Shields", 0, 5, 60, true, true, false));
    shopItems.push_back(Item("Shake Shack", "Potions", 0, 6, 20, true, true, false));
    shopItems.push_back(Item("Boarding Pass", "Special", 0, 0, 140, true, false, false));
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
void purchaseItem(std::vector<Item>& shopItems, int& playerCurrency, int& playerDamageReduction) {
    std::cout << "Your Currency: $" << playerCurrency << std::endl;
    for (size_t i = 0; i < shopItems.size(); ++i) {
        std::cout << i + 1 << ". ";
        shopItems[i].display();
    }

    int choice;
    std::cout << "Choose an item to buy (1-" << shopItems.size() << "): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= shopItems.size()) {
        Item& selectedItem = shopItems[choice - 1];
        if (playerCurrency >= selectedItem.cost) {
            playerCurrency -= selectedItem.cost;
            std::cout << "You bought: " << selectedItem.name << " for $" << selectedItem.cost << std::endl;
            std::cout << "Remaining Currency: $" << playerCurrency << std::endl;

            // Apply damage reduction effects for special items
            if (selectedItem.name == "Security Vest") {
                playerDamageReduction = -2;
                std::cout << "Equipped Security Vest: Damage reduced to -2!" << std::endl;
            } else if (selectedItem.name == "Meat Suit") {
                playerDamageReduction = -4;
                std::cout << "Equipped Meat Suit: Damage reduced to -4!" << std::endl;
            }
        } else {
            std::cout << "Not enough currency to buy this item!" << std::endl;
        }
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

void