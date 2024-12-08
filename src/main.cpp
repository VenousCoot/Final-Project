#include <string>
#include <iostream>
#include <limits>
#include "character.h"

using namespace std;

int main()
{
    cout << "Welcome to Hell Adventurer, this is Newark Liberty International Airport!" << endl;
    cout << "Voted the worst airport in the United States according to AirHelp's Global Airport Ranking (2019)." << endl;
    cout << "It looks like you have a flight departing in ... 1 hour!! Better Hurry!" << endl;    

    main_character mc("Default");

    mc.pick_player_name();
    
    return 0;
}