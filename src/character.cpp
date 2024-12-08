#include <iostream>
#include <cmath>
#include "character.h"

// Grab a specific parameter from the main characters stats
int main_character::get_parameter(const string& option){
    if (option == "max_hp"){
        return main_character::max_hp;
    }
    else if(option == "hp"){
        return main_character::hp;
    }
    else if(option == "att"){
        return main_character::att;
    }
    else if(option == "def"){
        return main_character::def;
    }
    else if(option == "sa"){
        return main_character::sa;
    }
    else if(option == "sd"){
        return main_character::sd;
    }
    else if(option == "money"){
        return main_character::money;
    }else{
        cout << "Invalid parameter name input. ERROR IN: character.cpp (get)" << endl;
    };

};

// Update a specific parameter of the main character
void main_character::update_parameter(const string& parameter, int update_amount){
    // The input to this functions "old parameter" should be the string of the name of the parameter you want!!
    // The input to "new parameter" should be whatever number you need to increase (or decrease) by 

    int old_p = main_character::get_parameter(parameter);

    if (old_p == -1){
        cout << "Invalid Parameter Name" << endl;
        return;
    }

    int new_parameter;
    new_parameter += update_amount; // Update the parameter and set it to "new parameter"

    // Check to see if it's negative (does not apply to the "money" attribute)
    if (new_parameter < 1 && parameter != "money"){
        new_parameter = 0;
    }

    // Set the main characters' stats to the new ones :)
    if (parameter == "max_hp"){
        main_character::max_hp == new_parameter;
    }
    else if(parameter == "hp"){
        main_character::hp == new_parameter;
    }
    else if(parameter == "att"){
        main_character::att == new_parameter;
    }
    else if(parameter == "def"){
        main_character::def == new_parameter;
    }
    else if(parameter == "sa"){
        main_character::sa == new_parameter;
    }
    else if(parameter == "sd"){
        main_character::sd == new_parameter;
    }
    else if(parameter == "money"){
        main_character::money == new_parameter;
    }else{
        cout << "Invalid parameter name input. ERROR IN: character.cpp (update)" << endl;
    };

    return;
}


// Function to set any parameter to any value (not negative)
void main_character::set_parameter(const string& parameter, int new_parameter){

        // Set the main characters' stats to the new ones :)
    if (parameter == "max_hp"){
        main_character::max_hp == new_parameter;
    }
    else if(parameter == "hp"){
        main_character::hp == new_parameter;
    }
    else if(parameter == "att"){
        main_character::att == new_parameter;
    }
    else if(parameter == "def"){
        main_character::def == new_parameter;
    }
    else if(parameter == "sa"){
        main_character::sa == new_parameter;
    }
    else if(parameter == "sd"){
        main_character::sd == new_parameter;
    }
    else if(parameter == "money"){
        main_character::money == new_parameter;
    }else{
        cout << "Invalid parameter name input. ERROR IN: character.cpp (set)" << endl;
    };

    return;

}