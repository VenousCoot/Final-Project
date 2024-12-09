#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <vector>


class main_character; // Forward declaration to get around circular dependancy

class Item {
public:
    std::string name;
    std::string category; // Shields, Swords, Potions, Health, Special
    int damage;
    int health;
    int cost;
    bool isShopItem; // True for shop items, false for drop items
    bool isOTU; // If it's one time use
    bool isUsed; // if the item was used

    std::string get_name();

    Item(std::string itemName, std::string itemCategory, int itemDamage, int itemHealth, int itemCost, bool shopItem, bool OUT, bool used);
    void display() const;
};

// Function declarations
void initializeGroupedItems(std::vector<Item>& shields, std::vector<Item>& swords, std::vector<Item>& potions);
void initializeShopItems(std::vector<Item>& shopItems);
void displayGroupedItems(const std::string& category, const std::vector<Item>& items);
int purchaseItem(std::vector<Item>& shopItems, int playerCurrency, main_character& player);
void DisplayDroppedItems();

#endif // ITEMS_H
