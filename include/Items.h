#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <vector>

class Item {
public:
    std::string name;
    std::string category; // Shields, Swords, Potions, Health, Special
    int damage;
    int health;
    int cost;
    bool isShopItem; // True for shop items, false for drop items

    Item(std::string itemName, std::string itemCategory, int itemDamage, int itemHealth, int itemCost, bool shopItem);
    void display() const;
};

// Function declarations
void initializeGroupedItems(std::vector<Item>& shields, std::vector<Item>& swords, std::vector<Item>& potions);
void initializeShopItems(std::vector<Item>& shopItems);
void displayGroupedItems(const std::string& category, const std::vector<Item>& items);
void purchaseItem(std::vector<Item>& shopItems, int& playerCurrency, int& playerDamageReduction);
void DisplayDroppedItems();

#endif // ITEMS_H
