
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class main_character{
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
        // Constructor:
        main_character(const string& name, int max_hp, int hp, int att, int def, int sd, int sa, int money);

        int get_parameter(const string& option); // Function to output a specific parameter
        void update_parameter(const string& parameter, int update_amount); 
        // Function to update a parameter by a specific value (add or subtraction)
        void set_parameter(const string& parameter, int new_parameter); 
        // Function to set a parameter to a specific value
};


#endif