#include <iostream>
#include <cmath>
#include <string>
#include "character.h"
#include <algorithm>
#include "Items.h"

using namespace std;

//
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
    cout << "Please enter your name / The name of your character: ";
    getline(cin, character_name); // Read entire line for name

    bool verified = false;
    while(!verified){
        string selection;
        cout << "Your name is: " << character_name << endl;
        cout << "Is this right? (Type '1' for yes, '2' for no): ";
        getline(cin, selection);
        while(selection != "1" && selection != "2"){
            cout << "Input a number buddy... either 1 or 2: ";
            getline(cin, selection); // Read entire line for selection
        }

        if (selection == "1"){
            set_name(character_name); // Update the main_character object with the confirmed name
            cout << "Okay, then let's continue, " << get_name() << "!" << endl;
            verified = true;
        } else if (selection == "2"){
            cout << "Please re-input your name!: ";
            getline(cin, character_name); // Read entire line for new name
        }
    }
}


// Players action choises:
string main_character::player_action(){
    bool verify = false;
    string action;
    cout << "What would you like to do? (Enter the number associated with the action)" << endl;
    cout << "Choices: Attack (1), Defend (2), Item (3): ";
    getline(cin, action);
    while (!verify){
        if(action == "1"){
            return "attack";
        }else if(action == "2") {
            return "block";
        }else if(action == "3"){
            display_inventory();
            return "item";
        }else{
            cout << "Okay wise guy, how about you enter something valid here 0_0" << endl;
        }
        cout << "Choices: Attack (1), Defend (2), Item (3): ";
        getline(cin, action);
    }
    return 0;
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
        cout << "Invalid parameter name input. ERROR IN: character.cpp (get)" << endl;
        return -1; // Return a specific value for invalid parameters
    }
}

// Update a specific parameter of the main character
void main_character::update_parameter(const string& parameter, int update_amount) {
    int old_p = main_character::get_parameter(parameter);

    // Check for valid parameter
    if (old_p == -1) {
        cout << "Invalid Parameter Name" << endl;
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
        cout << "Invalid parameter name input. ERROR IN: character.cpp (set)" << endl;
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
            std::cout << main_character::name << item_name << "\" used." << std::endl;
            item_found = true;
            break;
        }
    }

    if (!item_found) {
        std::cout << "Item \"" << item_name << "\" not found in inventory. Please try again: ";
        std::string new_item_name;
        std::cin >> new_item_name;
        remove_item(new_item_name); // Recursive call
    }
}

void main_character::display_inventory() const {
    cout << "Inventory:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (const auto& item : inventory) {
        item.display();
    }
}

// Use item function:
void main_character::use_item(){
    string item_name;
    display_inventory();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Input the name of the item you want to use" << endl;
    cin >> item_name;

    bool item_found = false;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->get_name() == item_name) {
            Item item_to_use = *it; // Store the Item object
            apply_item(item_to_use); // Pass the Item object to apply_item
            item_found = true;
            break;
        }
    }

    if (!item_found) {
        std::cout << "Item \"" << item_name << "\" not found in inventory. Please try again: ";
        std::string new_item_name;
        std::cin >> new_item_name;
        remove_item(new_item_name); // Recursive call
    }

}

// Apply stats of an item:
void main_character::apply_item(Item item){
    if(item.isOTU && item.category != "Potions"){
        string item_name;
        if(item.damage != 0){
            item_name = "att";
            main_character::update_parameter(item_name, item.damage);
        }
        if(item.health != 0){
            item_name = "hp";
            main_character::update_parameter(item_name, item.health);
        }
        remove_item(item.name);
    }else{
        string item_name;
        if(item.damage != 0){
            item_name = "att";
            main_character::update_parameter(item_name, item.damage);
        }
        if(item.health != 0){
            item_name = "hp";
            main_character::update_parameter(item_name, item.health);
        }
        item.isUsed = true;
    }
}
