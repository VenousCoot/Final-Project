#include <iostream>
#include <cmath>
#include <string>
#include "character.h"
#include <algorithm>
#include "Items.h"
#include "utility.h"

using namespace std;

// Constructor
main_character::main_character(){};

// Just function for name
string main_character::get_name(){
    return main_character::name;
}

void main_character::set_name(const string name){
    main_character::name = name;
}

// Function for player to pick a name for their character
void main_character::pick_player_name(){
    string character_name;
    printLetterByLetter("Please enter your name / The name of your character: ");
    getline(cin, character_name); // Read entire line for name

    bool verified = false;
    while(!verified){
        string selection;
        printLetterByLetter("Your name is: " + character_name + "\n");
        printLetterByLetter("Is this right? (Type '1' for yes, '2' for no): ");
        getline(cin, selection);
        while(selection != "1" && selection != "2"){
            printLetterByLetter("Input a number buddy... either 1 or 2: ");
            getline(cin, selection); // Read entire line for selection
        }

        if (selection == "1"){
            set_name(character_name); // Update the main_character object with the confirmed name
            printLetterByLetter("Okay, then let's continue, " + get_name() + "!\n");
            verified = true;
        } else if (selection == "2"){
            printLetterByLetter("Please re-input your name!: ");
            getline(cin, character_name); // Read entire line for new name
        }
    }
}

// Players action choises:
string main_character::player_action() {
    bool verify = false;
    string action;
    printLetterByLetter("What would you like to do? (Enter the number associated with the action)\n");
    printLetterByLetter("Choices: Attack (1), Defend (2), Item (3): ");
    getline(cin, action);

    while (!verify) {
        if (action == "1") {
            return "attack";
        } else if (action == "2") {
            return "block";
        } else if (action == "3") {
            Item item = use_item();
            if (item.name == "none") {
                // If no item was used, loop back to the options
                printLetterByLetter("Choices: Attack (1), Defend (2), Item (3): ");
                getline(cin, action);
                continue;
            } else if (item.damage != 0) {
                return "attack";
            } else {
                return "item";
            }
        } else {
            printLetterByLetter("Okay wise guy, how about you enter something valid here 0_0\n");
        }
        printLetterByLetter("Choices: Attack (1), Defend (2), Item (3): ");
        getline(cin, action);
    }
    return "None";
}

// Grab a specific parameter from the main character's stats
int main_character::get_parameter(const string& option) {
    if (option == "max_hp") {
        return main_character::max_hp;
    } else if (option == "hp") {
        return main_character::hp;
    } else if (option == "att") {
        return main_character::att;
    } else if (option == "def") {
        return main_character::def;
    } else if (option == "sa") {
        return main_character::sa;
    } else if (option == "sd") {
        return main_character::sd;
    } else if (option == "money") {
        return main_character::money;
    } else {
        printLetterByLetter("Invalid parameter name input. ERROR IN: character.cpp (get)\n");
        return -1; // Return a specific value for invalid parameters
    }
}

// Update a specific parameter of the main character
void main_character::update_parameter(const string& parameter, int update_amount) {
    int old_p = main_character::get_parameter(parameter);

    // Check for valid parameter
    if (old_p == -1) {
        printLetterByLetter("Invalid Parameter Name\n");
        return;
    }

    int new_parameter = old_p + update_amount; // Update the parameter and set it to "new parameter"

    if(parameter == "hp" && new_parameter > main_character::max_hp){
        new_parameter = main_character::max_hp;
    }
    // Check to see if it's negative (does not apply to the "money" attribute)
    if (new_parameter < 0 && parameter != "money") {
        new_parameter = 0;
    }

    // Set the main character's stats to the new ones :)
    main_character::parameter_selection(parameter, new_parameter);
}

// Function to set any parameter to any value (not negative)
void main_character::set_parameter(const string& parameter, int new_parameter) {
    // Set the main character's stats to the new ones :)
    main_character::parameter_selection(parameter, new_parameter);
}

// Function that updates the selected value based upon inputs:
void main_character::parameter_selection(const string& param_name, int value) {
    if (param_name == "max_hp") {
        main_character::max_hp = value; // Use assignment operator
    } else if (param_name == "hp") {
        main_character::hp = value;
    } else if (param_name == "att") {
        main_character::att = value;
    } else if (param_name == "def") {
        main_character::def = value;
    } else if (param_name == "sa") {
        main_character::sa = value;
    } else if (param_name == "sd") {
        main_character::sd = value;
    } else if (param_name == "money") {
        main_character::money = value;
    } else {
        printLetterByLetter("Invalid parameter name input. ERROR IN: character.cpp (set)\n");
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INVENTORY MANAGEMENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main_character::add_item(const Item& item){
    inventory.push_back(item);
}

void main_character::remove_item(const string& item_name) {
    bool item_found = false;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->get_name() == item_name) {
            inventory.erase(it);
            item_found = true;
            break;
        }
    }
}

void main_character::display_inventory() const {
    printLetterByLetter("Inventory:\n");
    printLetterByLetter("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for (const auto& item : inventory) {
        item.display();
    }
    return;
}

void main_character::display_all_parameters() const {
    printLetterByLetter("Character Name: " + name + "\n");
    printLetterByLetter("Max HP: " + to_string(max_hp) + "\n");
    printLetterByLetter("Current HP: " + to_string(hp) + "\n");
    printLetterByLetter("Attack: " + to_string(att) + "\n");
    printLetterByLetter("Defense: " + to_string(def) + "\n");
    printLetterByLetter("Special Defense: " + to_string(sd) + "\n");
    printLetterByLetter("Special Attack: " + to_string(sa) + "\n");
    printLetterByLetter("Money: " + to_string(money) + "\n");
}

// Use item function:
Item main_character::use_item() {
    if (inventory.empty()) {
        printLetterByLetter("You have no items.\n");
        return Item("none", "none", 0, 0, 0, false, false, false); // Return a default-constructed Item object
    }

    std::string item_name;
    display_inventory();
    printLetterByLetter("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printLetterByLetter("Input the name of the item you want to use or type 'back' to go back: ");
    getline(std::cin, item_name);

    bool item_found = false;
    while (!item_found) {
        if (item_name == "back") {
            printLetterByLetter("Returning to previous menu.\n");
            return Item("none", "none", 0, 0, 0, false, false, false); // Return a default-constructed Item object
        }

        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->get_name() == item_name) {
                apply_item(*it); // Pass the Item object to apply_item
                item_found = true;
                printLetterByLetter(main_character::name + " used " + it->get_name() + ".\n");
                main_character::display_all_parameters();
                return *it;
            }
        }

        if (!item_found) {
            printLetterByLetter("Item \"" + item_name + "\" not found in inventory. Please try again or type 'back' to go back: ");
            getline(std::cin, item_name);
        }
    }

    return Item("none", "none", 0, 0, 0, false, false, false); // Return a default-constructed Item object
}

// Apply stats of an item:
void main_character::apply_item(Item& item) {
    // Update parameters based on item properties
    if (item.name == "First Class Boarding Pass"){
        printLetterByLetter("It's a boarding pass....\n");
        return;
    }
    if (item.name == "Stylish Hat") {
        printLetterByLetter("Omnipresent voice: Cool hat huh???? RIGHT??? \n");
        return;
    }
    if (item.name == "Advil") {
        main_character::update_parameter("max_hp", item.health);
    }
    if (item.name == "Suspicious Ticking Suitcase") {
        printLetterByLetter("Well, it's not a bomb... but you did lose your turn!\n");
    }
    if (item.name == "Meat Shield" && item.isUsed == true){
        printLetterByLetter("You pull a grandma in front of you to take the hit.... She dies\n");
        printLetterByLetter("Omnipresent voice: Wow you're a piece of shit\n");
    }
    if (item.damage != 0) {
        main_character::update_parameter("att", item.damage);
    }
    if (item.health != 0 && item.name != "Advil" && item.name != "Shields") {
        main_character::update_parameter("hp", item.health);
    }
    if (item.health != 0 && item.category == "Shields") {
        main_character::update_parameter("def", item.health);
    }

    // Handle one-time use items
    if (item.isOTU) {
        item.isUsed = true;
    } else {
        remove_item(item.name);
    }
}

vector <Item> main_character::get_inventory(){
    return main_character::inventory;
}
