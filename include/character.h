#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class main_character {
    private:
        string name;
        int max_hp = 20;
        int hp = 20;
        int att = 5;
        int def = 0;
        int sd = 0;
        int sa = 0;
        int money = 3;
    public:
        // Constructor
        main_character(const string& input_name);
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
};

#endif // CHARACTER_H