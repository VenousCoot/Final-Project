#include <string>
#include <iostream>
#include "room.h"
#include "NPC.h"
#include <ctime>
#include "Items.h"
#include <vector>
#include "Combat.h"
#include <limits>
#include <memory>
#include "character.h"
#include <iostream>
#include "ItemChoice.h"
#include "utility.h"

using namespace std;

// Debug mode if = 1 then will print debugging messages example being object destroying messages
int Debug = 0;
int main_debug = 0; // Debug used if you want to go to a specific stage (1 for lobby, 2 for security, 3 for terminal, 4 for gate, 5 for cockpit).
bool check = false;

// Create the object "Player"
main_character player;

// Create objects for all the rooms:
Lobby lobby;
Security security;
Terminal terminal;
Gate gate(false);
Plane plane(false);

// Initialize items for shop demo:
vector<Item> shields;
vector<Item> swords;
vector<Item> potions;
vector<Item> shopItems;


int main()
{
    
    srand(static_cast<unsigned>(time(0)));    // Seed the random number generator
    long long start_time = static_cast<unsigned>(time(0));
    int TTF = (rand() % (60 - 5 + 1)) + 5;

    if (main_debug <= 0) {
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INTRODUCTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        cout <<"==================================================================="<< endl;
        pLBL("Welcome to Hell, Adventurer, this is Newark Liberty International Airport!");
        pLBL("Voted the worst airport in the United States according to AirHelp's Global Airport Ranking (2019).");
        pLBL("It looks like you have a flight departing in ... " + to_string(TTF) + " minutes!! Better Hurry!");
        cout <<"===================================================================" << endl;
        int playerDamageReduction = 0;  // Default damage reduction

        player.pick_player_name();
        cout <<"===================================================================" << endl;
        cout <<"Stats:" << endl;
        player.display_all_parameters();
        cout << "Press Enter to continue...";
        cin.get(); // Waits for the user to press Enter
    }

    if (main_debug <= 1) {
        cout <<"\n===================================================================" << endl;
        cout << "Stage 1: Lobby" << endl;
        cout <<"===================================================================\n" << endl;

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STAGE BEGIN: LOBBY  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        lobby.enter();
        auto Receptionist = make_unique<NPC>("Receptionist", 10, 1, 80, 10, 10, 0, 0);
        cout << "Press Enter to continue...";
        cin.get(); // Waits for the user to press Enter;

        Combat::startCombat(Receptionist, player); // Start combat between player and lobby NPC

        if (player.get_parameter("hp") > 0) {
            cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining." << endl;
        } else {
            pLBL("Thank you for playing, hope you win next time!");
            cin.get();
            return 1;
        }

        LobbyItems(player); // Loot drop for the player to pick from!
    }

    if (main_debug <= 2) {
        cout <<"\n===================================================================" << endl;
        cout << "Stage 2: Security" << endl;
        cout <<"===================================================================\n" << endl;

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STAGE BEGIN: SECURITY  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        security.enter(); // Call the security function to start next stage
        auto TSA_Agent = make_unique<NPC>("TSA Agent", 20, 2, 60, 30, 10, 0, 0); // Create the TSA NPC
        cout << "Press Enter to continue...";
        cin.get(); // Waits for the user to press Enter;

        Combat::startCombat(TSA_Agent, player); // Start combat between player and TSA Agent

        if (player.get_parameter("hp") > 0) {
            cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining." << endl;
        } else {
            pLBL("Thank you for playing, hope you win next time!");
            cin.get();
            return 1;
        }

        SecurityItems(player); // Loot drop for the player to pick from!
    }

    if (main_debug <= 3) {
        
        cout <<"\n===================================================================" << endl;
        cout << "Stage 3: Terminal A" << endl;
        cout <<"===================================================================\n" << endl;

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STAGE BEGIN: TERMINAL  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        terminal.enterTerminal(player); // Call the terminal function to start next stage
        if(player.get_check(1)){
            initializeShopItems(shopItems);
            int money;
            money = purchaseItem(shopItems, player.get_parameter("money"), player);
            player.set_parameter("money",money);

            cout << "\nFinal Player State:" << endl;
            cout << "Currency: $" << player.get_parameter("money") << endl;
            if(player.get_check(3)){
                gate.setBoardingPass(true);
            }
        } else if(player.get_check(2)){
            auto shopKeep = make_unique<NPC>("Shopkeep", 35, 5, 30, 50, 0, 10, 0); // Create the TSA NPC
            cout << "Press Enter to continue...";
            cin.get(); // Waits for the user to press Enter;

            Combat::startCombat(shopKeep, player); // Start combat between player and Shopkeep

            if (player.get_parameter("hp") > 0) {
                cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining." << endl;
            } else {
                pLBL("Thank you for playing, hope you win next time!");
                cin.get();
                return 0;
            }
            
            player.add_item(Item("Laptop Bag", "Swords", 2, 0, 60, false, false, false));
            player.add_item(Item("Meat Shield", "Shields", 0, 5, 60, true, true, false));
            player.add_item(Item("Shake Shack", "Potions", 0, 6, 20, true, true, false));
            player.add_item(Item("First Class Boarding Pass", "Special", 0, 0, 140, true, false, false));

            if(player.get_check(3)){
                gate.setBoardingPass(true);
            }

        } else {
            auto annoyed_man = make_unique<NPC>("Annoyed Man", 15, 3, 20, 57, 18, 5, 0); // Create the TSA NPC
            cout << "Press Enter to continue...";
            cin.get(); // Waits for the user to press Enter;

            Combat::startCombat(annoyed_man, player); // Start combat between player and Annoyed Man

            if (player.get_parameter("hp") > 0) {
                cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining." << endl;
            } else {
                pLBL("Thank you for playing, hope you win next time!");
                cin.get();
                return 0;
            }

            TerminalItems(player); // Loot drop for the player to pick from!
        }
    }

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STAGE END: TERMINAL  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if (main_debug <= 4) {
        cout <<"\n===================================================================" << endl;
        cout << "Stage 4: Gate 7" << endl;
        cout <<"===================================================================\n" << endl;
        
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STAGE BEGIN: GATE  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
        long long end_time = static_cast<unsigned>(time(0));
        TTF = TTF * 60;
        if (end_time - start_time > TTF){
            pLBL("Gate Agent: Sorry, your flight has left already without you.");
            pLBL("Omnipresent Voice: ... HAHAHAHHAHAHAHAHAHHAHHAHAHHAHAHAHAHAHAH... ");
            pLBL(" HAHAHHAHA... wow. Wow. WOW! You really messed this up huh. Maybe if you spent less time beating up random people");
            pLBL("  and more time actually going to your gate...");
            pLBL(" YOU WOULDN'T HAVE TOTALLY MISSED YOUR FLIGHT HAHAHAHHAHAHAHAHHAHAHAHHAHAHAHAH");
            pLBL(" ... moron.");
            pLBL(" Game Over");
            return 1;
        }

        gate.enterGate(player); // Call the gate function to start next stage

        if(player.get_check(3) || player.get_check(4)){ // check to see if the player has passed the First class boarding pass, or the fight skip (if they won the 50/50)
            cout << "Press Enter to continue...";
            cin.get(); // Waits for the user to press Enter;
        } else {
            auto flight_attendant = make_unique<NPC>("Flight Attendant", 20, 2, 53, 30, 10, 7, 0); // Create the TSA NPC
            cout << "Press Enter to continue...";
            cin.get(); // Waits for the user to press Enter;

            Combat::startCombat(flight_attendant, player); // Start combat between player and Flight Attendant

            if (player.get_parameter("hp") > 0) {
                cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining." << endl;
            } else {
                pLBL("Thank you for playing, hope you win next time!");
                cin.get();
                return 0;
            }

            GateItems(player); // Loot drop for the player to pick from!
        }
    }

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STAGE BEGIN: COCKPIT  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  

    if (main_debug <= 5) {
        cout <<"\n===================================================================" << endl;
        cout << "Stage 5: Cockpit " << endl;
        cout <<"===================================================================\n" << endl;

        check = false;

        if(player.get_check(5)){
            plane.setStylishHat(true);
        }

        plane.enter(); // Call the plane function to start next stage
        auto the_captain = make_unique<NPC>("The Captain", 35, 4, 20, 60, 10, 7, 3);
        cout << "Press Enter to continue...";
        cin.get(); // Waits for the user to press Enter;

        Combat::startCombat(the_captain, player); // Start combat between player and THE CAPTAIN!!!!!!!!!!!!!!

        if (player.get_parameter("hp") > 0) {
            cout << player.get_name() << " survived the fight with " << player.get_parameter("hp") << " health remaining." << endl;
        } else {
            pLBL("Thank you for playing, hope you win next time! (lol u died at the captain have fun restarting)");
            cin.get();
            return 1;
        }

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STAGE END: COCKPIT  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  



        pLBL("Narrator: As you sit in the captain's chair, you realize how much work it took to get here and reminisce in the glory that is your perserverence...");
        cin.get();
        pLBL("Narrator: Even though there are hundreds of civilians inside, you decide you want to take this plane to the destination yourself...");
        cin.get();
        pLBL("Narrator: You, with little to no piloting experience grab the yoke, and tell ATC that there is no option, you are already spooling up on the runway...");
        cin.get();
        pLBL("Narrator: You haphazardly takeoff as the sound of pounding of the flight attendants on the bullet-proof door and the muffled screams of the passengers fade from your mind...");
        cin.get();
        pLBL("Narrator: You are finally at peace...");
        cin.get();
        pLBL("Narrator: ...");
        cin.get();
        pLBL("Narrator: ...");
        cin.get();
        pLBL("Narrator: ...");
        cin.get();
        pLBL("Narrator: And then you *almost* crash land into your destination: Philadelphia International Airport. \n");
        cin.get();

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        pLBL("Congratulations! You beat the game!!!!\n");
        pLBL("Your final money count is:" + to_string(player.get_parameter("money")) + ".");
        pLBL("'BoardQuest' by Giuseppe Carbone, Shaan Sullivan, Achyutan Srinivasan, Aditi Priya-Swaminathan");
        pLBL("This was a collaborative effort between all of us and we had a blast making it.");
        pLBL("If you are our professor, we hope you had fun and this compiled and ran without any errors.");
        pLBL("If you are some random person on the internet, thank you for playing our poorly made text-based rpg. We hope you enjoyed it and you rock!");
        pLBL("Seriously it means the world to us that you even took the time to beat it in the first place. It was made to make the player suffer soooo.... Sorry!");
        pLBL("Also, you should go out and play it again! There aren't multiple endings, but there are different routes and things that could end up happening (take a peek at the source code)");
        pLBL("Consider reaching out to my email giuseppe687.gc2@gmail.com if you want to contact us for any reason (don't be an asshole this is not my primary email so I will just delete it / block you)");
        pLBL("Have a wonderfull day! And thanks again for playing!:) ");
        cin.get();
    }

    return 0;
}
