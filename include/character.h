#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Items.h"

using namespace std;


//
class main_character {
    private:
        string name;
        int max_hp = 30;
        int hp = 20;
        int att = 5;
        int def = 2;
        int sd = 0;
        int sa = 0;
        int money = 150;
        vector <Item> inventory;
        vector <bool> checks; // Sets the boolean check that the player may or may not need to have options. 
    public:
        bool shop = false;
        bool shopKeep = false;
        bool hasFirstClassBoardingPass = false;
        bool fistClassSkip = false;
        bool fightSkip = false;

        bool get_check(int check);

        void updateChecks(int check, bool value); // Function to set the checks to a specific check type
        // 1 is going to shop. 2 is fighting shopkeep. 3 is firstclassboardingpass. 4 is fight skip 5 is stylish hat

        // Constructor
        main_character();
        // Main character function to select a name:
        void pick_player_name();
        string get_name();
        // Just for the name
        void set_name(const string name);
        // Set the nameeeeeeeeeeee
        int get_parameter(const string& option); // Function to output a specific parameter
        void update_parameter(const string& parameter, int update_amount); 
        // Function to update a parameter by a specific value (add or subtract)
        void set_parameter(const string& parameter, int new_parameter); 
        // Function to set a parameter to a specific value

        void parameter_selection(const string& name, int value);
        // Using this to simplify code for readability

        string player_action();
        // Player's actions 

        // Display characters stats
        void display_all_parameters() const;

        // Inventory management functions
        void add_item(Item item);
        void remove_item(const string& item_name);
        void display_inventory() const;
        Item use_item();
        void apply_item(Item& item);
        vector <Item> get_inventory();
};

#endif 