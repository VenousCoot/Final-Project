#include "Room.h"
#include "Utility.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Items.h"
#include "character.h"

using namespace std;

void Gate::setBoardingPass(bool value){
    Gate::hasFirstClassBoardingPass = value;
}

void Plane::setStylishHat(bool value){
    Plane::hasStylishHat = value;
}

Lobby::Lobby() {
    description = "Omnipresent Voice: This is the lobby of Terminal A. What wonderful news, There's a receptionist right here for you to talk to!";
    npcName = "Receptionist";
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOBBY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Lobby::enter() {
    pLBL ( description ); 
    pLBL( npcName + ": Welcome to Newark Airport! May I see your boarding pass? \n" ) ;

    string playerInput;
    bool validInput = false;

    while (!validInput) {
        cout << "Player Dialog Choices:" << endl;
        cout << "1. Here you go I have it right here!" << endl;
        cout << "2. Boarding Pass? What's that?" << endl;
        getline(cin, playerInput);

        if (playerInput == "1") {
            pLBL ( npcName + ": Hmm ...  this sure doesn`t seem like it`s yours. Got any ID? \n" );

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Choices:" << endl;
                cout << "1. Uhh ... You know what, I don't seem to have it with me right now." << endl;
                cout << "2. That's me! Is there something wrong with your eyes?!" << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    pLBL ( npcName + ": Alright kid, I'm gonna have to show you the exit." );
                    return;
                }
                else if (playerInput == "2") {
                    pLBL ( npcName + ": DON'T YOU DARE TALK TO ME THAT WAY" );
                    return;
                }
                else {
                    pLBL( npcName + ": I'm sorry, were you trying to say something? \n" );
                    pLBL( "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2. \n" );
                }
            }
        }
        else if (playerInput == "2") {
            pLBL ( npcName + ": Listen here bub, if you don't have a boarding pass get the hell out of my line. \n" );

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Choices:" << endl;
                cout << "1. Woah woah woah that's not cool" << endl;
                cout << "2. Oh you wanna fight? Lets do this." << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    pLBL ( npcName + ": That's it I'm gonna kick your ass!" );
                    return;
                }
                else if (playerInput == "2") {
                    pLBL("*Swing at the Receptionist*");
                    return;
                }
                else {
                    pLBL(npcName + ": I'm sorry, were you trying to say something? \n");
                    pLBL("Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2. \n");
                }
            }
        }
        else {
            pLBL(npcName + ": I'm sorry, were you trying to say something?\n");
            pLBL("Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2. \n");
        }
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SECURITY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Security::Security() {
	description = "Omnipresent Voice: You really beat up that middle aged woman didn't you? You feeling good about yourself? You feel like you're top dog now don't you?";
	npcName = "TSA Agent";
}

void Security::enter() {
	pLBL( description );
	pLBL( "Anyways this is the security check. Be careful the TSA here can be touchy! \n" );
	pLBL( npcName + ": Single file line, shoes off. Hey you, get back in line! *points at you* \n");



	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "Player Dialog Choices:" << endl;
		cout << "1. I am in line. Why are you yelling at me?" << endl;
		cout << "2. What is wrong with the people around here?" << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
            pLBL(npcName + ": Oh are you giving me lip?" );
			return;
		}
		else if (playerInput == "2") {
            pLBL(npcName + ": You don't know how long I've been waiting for this." );
			return;
		}
		else {
            pLBL(npcName + ": I'm sorry, were you trying to say something? \n");
            pLBL("Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2. \n");
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TERMINAL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Terminal::Terminal() {
	description = "Omnipresent Voice: Ok that guy was kinda a dick, but isn't it weird that you have run into 2 people and have gotten into 2 fights? Must be some kind of common denominator here.";
	npcName1 = "Annoyed Man";
	npcName2 = "Shopkeep";
}

void Terminal::enterTerminal(main_character& player) {
	pLBL( description );
    pLBL( "Moving past your violent tendencies. This is terminal A, Newark's brand new terminal! It has 33 gates and over a dozen unique restaurants!");
	pLBL(  "Not that it matters to you since you're probably just going to go get into a fight someone else, but I thought that I should at least let you know. \n");

	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "Player Action Choices:" << endl;
		cout << "1. Go to one of the stores." << endl;
		cout << "2. Go looking for trouble." << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
			pLBL("Omnipresent Voice: Wow, I wonder how long this non-violent streak of yours will last. \n");
			pLBL( npcName2 + ": Welcome to the newest addition to Terminal A, Hudson Non-stop!");
            pLBL("This is our fully self-checkout convenience store! Just grab what you need, and it is immediately pulled from your emergency savings account! \n");
			
			validInput = false;
			while (!validInput) {
				cout << "Player Dialog Options:" << endl;
				cout << "1. Oh, that sounds really cool!" << endl;
				cout << "2. If it's fully self-checkout why are you here?" << endl;
				getline(cin, playerInput);
				if (playerInput == "1") {
                    player.updateChecks(1, true); // set shop to true
                    // player.shop = true; 
                    return;
                    // Bring to shop					
				}
				else if (playerInput == "2"){
                    pLBL(npcName2 + ": To keep assholes like you out.");
                    // player.shopKeep = true;
                    player.updateChecks(2, true); // set fightshopkeep to true
                    return; // Return to main for combat
				}
				else {
                    pLBL(npcName2 + ": I'm sorry, were you trying to say something? \n");
					pLBL( "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2. \n");
				}
			}
			

		}
		else if (playerInput == "2") {
			pLBL( "Omnipresent Voice: What a shocker you picked to look for a fight. I don't really know why I expected anything different from you. \n");
            pLBL(npcName1 + ": HEY YOU!! My flight just got delayed 4 hours and you have the perfect face for punching! \n");

			validInput = false;
			while (!validInput) {
				cout << "Player Dialog Options:" << endl;
				cout << "1. NO, YOUR FACE IS PERFECT FOR PUNCHING!!!" << endl;
				cout << "2. I'LL KILL YOU!!!" << endl;
				cout << "3. AAAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGHHHHHHHHHHHH!!!!!!!!!" << endl;
				getline(cin, playerInput);

				if (playerInput == "1") {
					return;
				}
				else if (playerInput == "2") {
					return;
				}
				else if (playerInput == "3") {
					return;
				}
				else {
                    pLBL(npcName1 + ": WHAT DID YOU SAY TO ME!?!?! \n" );
					pLBL( "Omnipresent Voice: For the first time you have 3 whole choices to make and you still choose to press a random button. I'm seriously starting to get worried for you. \n" );

				}
			}
		}
	}

}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GATE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Gate::Gate(bool hasFirstClassBoardingPass) : hasFirstClassBoardingPass(hasFirstClassBoardingPass){
    description = "Omnipresent Voice: I honestly don't know what to say. I'm certainly not proud of you, but I guess I can commend you for getting this far.";
    npcName = "Flight Attendant";
}

void Gate::enterGate(main_character& player) {
    pLBL( description );
    pLBL( "You actually managed to make it to your gate despite the extreme violence you have shown during our time together. Or maybe I should say that you made it this far THANKS to the violence." );
    pLBL( "Just go up to the front and wait for your group to be called, and please, for the love of all that is good, do not start a fight. \n" );
    pLBL( npcName + ": Now boarding groups 1 and 2! Now boarding groups 1 and 2!" );
    pLBL( "Excuse me, may I see your boarding pass? \n" );

    string playerInput;
    bool validInput = false;

    while (!validInput) {
        cout << "Player Dialog Options:" << endl;
        cout << "1. Oh, I don't have one." << endl;
        cout << "2. I have it right here!" << endl;
        // IF YOU HAVE THE FIRST CLASS BOARDING PASS
        if (hasFirstClassBoardingPass) {
            cout << "3. *Present the First Class Boarding Pass*" << endl;
        }
        getline(cin, playerInput);

        if (playerInput == "1") {
            pLBL(npcName + ": How did you even get here without a boarding pass? \n" );

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Options:" << endl;
                cout << "1. It's been a rough day." << endl;
                cout << "2. I uhhh ... I dropped it, but I'm in the system." << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    pLBL(npcName + ": It's about to get even worse." );
                    return;
                }
                else if (playerInput == "2") {
                    pLBL(npcName + ": That's not going to work on anybody.");
                    return;
                }
                else {
                    pLBL(npcName + ": I'm sorry, what are you trying to say? \n" );
                    pLBL( "Omnipresent Voice: CAN YOU PLEASE STOP PRESSING RANDOM BUTTONS. Just pick either a 1 or a 2. \n" );
                }
            }
        }
        else if (playerInput == "2") {
            pLBL(npcName + ": Hmm... this sure doesn't seem like it's yours. Do you have any ID? \n" );

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Options:" << endl;
                cout << "1. Not this again. I don't have any ID with me." << endl;
                cout << "2. Of course I do! Here it is *bluff*" << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    pLBL(npcName + ": No identification, no entry." );
                    return; // FIGHT
                }
                else if (playerInput == "2") {
                    srand(static_cast<unsigned int>(time(0)));
                    int randomValue = rand() % 2;
                    if (randomValue == 0) {
                        pLBL(npcName + ": Oh of course! You seem so confident I don't even have to check!" );
                        pLBL( "Please go right ahead." );
                        player.updateChecks(4, true); // Set the fight skip to true
                        return;
                        // Send them to floor 5 without fighting
                    }
                    else {
                        pLBL(npcName + ": This is a half filled out rewards card for Jersey Mike's." );
                        pLBL( "Omnipresent Voice: Did you honestly think that would work?" );
                        return;
                        // FIGHT
                    }
                }
                else {
                    pLBL(npcName + ": I don't have time for this nonsense. \n" );
                    pLBL(npcName + "Omnipresent Voice: We have been together so long and you still refuse to press the right buttons. \n" );
                }
            }
        }
        else if (playerInput == "3" && hasFirstClassBoardingPass) {
            pLBL(npcName + ": Oh, a VIP! Please right this way. Your seat is 0A! \n" );

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Options:" << endl;
                cout << "1. What's 0A?" << endl;
                cout << "2. Where's that?" << endl;
                getline(cin, playerInput);

                if (playerInput == "1" || playerInput == "2") {
                    pLBL(npcName + ": Well that's the Captain's seat of course!" );
                    return;
                }
                else {
                    pLBL(npcName + ": Pardon? \n" );
                    pLBL( "Omnipresent Voice: Seriously? This late in the game? \n" );

                }
            }
        }
        else {
            pLBL(npcName + ": I didn't quite catch that. \n" );
            pLBL( "Omnipresent Voice: CAN YOU PLEASE STOP PRESSING RANDOM BUTTONS. Just pick either a 1 or a 2. \n" );
        }
    }
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PLANE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Plane::Plane(bool hasStylishHat) : hasStylishHat(hasStylishHat){
	description = "Omnipresent Voice: I would say that you should take some time to reflect on your choices, but I think its a bit too late for that.";
	npcName = "The Captain";
}

void Plane::enter() {
    pLBL( description );
    pLBL("This is the last obstacle in your path. Usually I would ask you to not get into a fight here, but I honestly doubt that you have a choice in this scenario." );
    pLBL( "Good Luck! \n" );
    pLBL( npcName + ": My plane my rules moron! Rule number 1 is that I hate you and you can't fly on my plane. " );
    pLBL("Rule number 2 is that there are no further rules. \n" );


	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "Player Dialog Options:" << endl;
		cout << "1. What the hell that's so unfair!" << endl;
		cout << "2. Screw this shit. I'm gonna kick your ass!" << endl;
		cout << "3. AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGHHHHHHHHHHHHHH!!!!!!!" << endl;
		// IF YOU HAVE THE STYLISH HAT
		if (hasStylishHat) {
			cout << "4. Captain, can`t we come to a peaceful solution to this problem?" << endl;
		}
		getline(cin, playerInput);

		if (playerInput == "1") {
            pLBL( npcName + ": Sucks to suck dumbass." );
			return;
			}
		else if (playerInput == "2") {
            pLBL(npcName + ": BRING IT ONNNNNNNNN!!!!" );
			return;
		}
		else if (playerInput == "3") {
            pLBL( "*you lunge at The Captain's neck*" );
			return;
		}
		else if (playerInput == "4" && hasStylishHat) {
			pLBL( "Omnipresent Voice: That was never going to work. \n" );
            pLBL(npcName + ": Hmm ... No I think I'll beat you up now" );
			return;
		}
		else {
            pLBL(npcName + ": What the hell are you talking about. \n" );
			pLBL( "Omnipresent Voice: Bruh \n" );
		}
	}
}

