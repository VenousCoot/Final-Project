#include "Room.h"
#include "Utility.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Lobby::Lobby() {
    description = "Omnipresent Voice: This is the lobby of Terminal A. What wonderful news, There's a receptionist right here for you to talk to!";
    npcName = "Receptionist";
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOBBY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Lobby::enter() {
    printLetterByLetter ( description );
    printLetterByLetter( npcName + ": Welcome to Newark Airport! May I see your boarding pass?" );

    string playerInput;
    bool validInput = false;

    while (!validInput) {
        cout << "Player Dialog Choices:" << endl;
        cout << "1. Here you go I have it right here!" << endl;
        cout << "2. Boarding Pass? What's that?" << endl;
        getline(cin, playerInput);

        if (playerInput == "1") {
            printLetterByLetter ( npcName + ": Hmm ...  this sure doesn`t seem like it`s yours. Got any ID?" );

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Choices:" << endl;
                cout << "1. Uhh ... You know what, I don't seem to have it with me right now." << endl;
                cout << "2. That's me! Is there something wrong with your eyes?!" << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    printLetterByLetter ( npcName + ": Alright kid, I'm gonna have to show you the exit." );
                    return;
                }
                else if (playerInput == "2") {
                    printLetterByLetter ( npcName + ": DON'T YOU DARE TALK TO ME THAT WAY" );
                    return;
                }
                else {
                    printLetterByLetter( npcName + ": I'm sorry, were you trying to say something?" );
                    printLetterByLetter( "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2." );
                }
            }
        }
        else if (playerInput == "2") {
            printLetterByLetter ( npcName + ": Listen here bub, if you don't have a boarding pass get the hell out of my line." );

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Choices:" << endl;
                cout << "1. Woah woah woah that's not cool" << endl;
                cout << "2. Oh you wanna fight? Lets do this." << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    printLetterByLetter ( npcName + ": That's it I'm gonna kick your ass!" );
                    return;
                }
                else if (playerInput == "2") {
                    printLetterByLetter("*Swing at the Receptionist*");
                    return;
                }
                else {
                    printLetterByLetter(npcName + ": I'm sorry, were you trying to say something?");
                    printLetterByLetter("Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2.");
                }
            }
        }
        else {
            printLetterByLetter(npcName + ": I'm sorry, were you trying to say something?");
            printLetterByLetter("Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2.");
        }
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SECURITY

Security::Security() {
	description = "Omnipresent Voice: You really beat up that middle aged woman didn't you? You feeling good about yourself? You feel like you're top dog now don't you?";
	npcName = "TSA Agent";
}

void Security::enter() {
	printLetterByLetter( description );
	printLetterByLetter( "Anyways this is the security check. Be careful the TSA here can be touchy!" );
	printLetterByLetter( npcName + ": Single file line, shoes off. Hey you, get back in line! *points at you*");



	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "Player Dialog Choices:" << endl;
		cout << "1. I am in line. Why are you yelling at me?" << endl;
		cout << "2. What is wrong with the people around here?" << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
            printLetterByLetter(npcName + ": Oh are you giving me lip?" );
			return;
		}
		else if (playerInput == "2") {
            printLetterByLetter(npcName + ": You don't know how long I've been waiting for this." );
			return;
		}
		else {
            printLetterByLetter(npcName + ": I'm sorry, were you trying to say something?");
            printLetterByLetter("Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2.");
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TERMINAL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Terminal::Terminal() {
	description = "Omnipresent Voice: Ok that guy was kinda a dick, but isn't it weird that you have run into 2 people and have gotten into 2 fights? Must be some kind of common denominator here.";
	npcName1 = "Annoyed Man";
	npcName2 = "Shopkeep";
}

void Terminal::enter() {
	printLetterByLetter( description );
    printLetterByLetter( "Moving past your violent tendencies. This is terminal A, Newark's brand new terminal! It has 33 gates and over a dozen unique restaurants!");
	printLetterByLetter(  "Not that it matters to you since you're probably just going to go get into a fight someone else, but I thought that I should at least let you know.");

	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "Player Action Choices:" << endl;
		cout << "1. Go to one of the stores." << endl;
		cout << "2. Go looking for trouble." << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
			printLetterByLetter("Omnipresent Voice: Wow, I wonder how long this non-violent streak of yours will last.");
			printLetterByLetter( npcName2 + ": Welcome to the newest addition to Terminal A, Hudson Non-stop!");
            printLetterByLetter("This is our fully self-checkout convenience store! Just grab what you need, and it is immediately pulled from your emergency savings account!");
			
			validInput = false;
			while (!validInput) {
				cout << "Player Dialog Options:" << endl;
				cout << "1. Oh, that sounds really cool!" << endl;
				cout << "2. If it's fully self-checkout why are you here?" << endl;
				getline(cin, playerInput);
				if (playerInput == "1") {
                    printLetterByLetter(npcName2 + ": Please have a look at what's in stock!" );
                    return;
                    // Bring to shop					
				}
				else if (playerInput == "2"){
                    printLetterByLetter(npcName2 + ": To keep assholes like you out.");
                    return;
					// Bring you to combat
				}
				else {
                    printLetterByLetter(npcName2 + ": I'm sorry, were you trying to say something?");
					printLetterByLetter( "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2.");
				}
			}
			

		}
		else if (playerInput == "2") {
			printLetterByLetter( "Omnipresent Voice: What a shocker you picked to look for a fight. I don't really know why I expected anything different from you.");
            printLetterByLetter(npcName1 + ": HEY YOU!! My flight just got delayed 4 hours and you have the perfect face for punching!");

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
                    printLetterByLetter(npcName1 + ": WHAT DID YOU SAY TO ME!?!?!" );
					printLetterByLetter( "Omnipresent Voice: For the first time you have 3 whole choices to make and you still choose to press a random button. I'm seriously starting to get worried for you." );

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

void Gate::enter() {
    cout << description << endl;
    cout << "You actually managed to make it to your gate despite the extreme violence you have shown during our time together. Or maybe I should say that you made it this far THANKS to the violence." << endl;
    cout << "Just go up to the front and wait for your group to be called, and please, for the love of all that is good, do not start a fight." << endl;
    cout << npcName << ": Now boarding groups 1 and 2! Now boarding groups 1 and 2!" << endl;
    cout << "Excuse me, may I see your boarding pass?" << endl;

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
            cout << npcName << ": How did you even get here without a boarding pass?" << endl;

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Options:" << endl;
                cout << "1. It's been a rough day." << endl;
                cout << "2. I uhhh ... I dropped it, but I'm in the system." << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    cout << npcName << ": It's about to get even worse." << endl;
                    return;
                }
                else if (playerInput == "2") {
                    cout << npcName << ": That's not going to work on anybody." << endl;
                    return;
                }
                else {
                    cout << npcName << ": I'm sorry, what are you trying to say?" << endl;
                    cout << "Omnipresent Voice: CAN YOU PLEASE STOP PRESSING RANDOM BUTTONS. Just pick either a 1 or a 2." << endl;
                }
            }
        }
        else if (playerInput == "2") {
            cout << npcName << ": Hmm... this sure doesn't seem like it's yours. Do you have any ID?" << endl;

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Options:" << endl;
                cout << "1. Not this again. I don't have any ID with me." << endl;
                cout << "2. Of course I do! Here it is *bluff*" << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    cout << npcName << ": No identification, no entry." << endl;
                    return;
                }
                else if (playerInput == "2") {
                    srand(static_cast<unsigned int>(time(0)));
                    int randomValue = rand() % 2;
                    if (randomValue == 0) {
                        cout << npcName << ": Oh of course! You seem so confident I don't even have to check!" << endl;
                        cout << "Please go right ahead." << endl;
                        return;
                        // Send them to floor 5 without fighting
                    }
                    else {
                        cout << npcName << ": This is a half filled out rewards card for Jersey Mike's." << endl;
                        cout << "Omnipresent Voice: Uh oh." << endl;
                        return;
                        // FIGHT
                    }
                }
                else {
                    cout << npcName << ": I don't have time for this nonsense" << endl;
                    cout << "Omnipresent Voice: We have been together so long and you still refuse to press the right buttons." << endl;
                }
            }
        }
        else if (playerInput == "3" && hasFirstClassBoardingPass) {
            cout << npcName << ": Oh, a VIP! Please right this way. Your seat is 0A!" << endl;

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Options:" << endl;
                cout << "1. What's 0A?" << endl;
                cout << "2. Where's that?" << endl;
                if (playerInput == "1" || playerInput == "2") {
                    cout << npcName << ": Well thats the Captain's seat of course!" << endl;
                    return;
                }
                else {
                    cout << npcName << "Pardon?" << endl;
                    cout << "Seriously? This late in the game?" << endl;

                }
            }
        }
        else {
            cout << npcName << ": I didn't quite catch that." << endl;
            cout << "Omnipresent Voice: CAN YOU PLEASE STOP PRESSING RANDOM BUTTONS. Just pick either a 1 or a 2." << endl;
        }
    }
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PLANE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Plane::Plane(bool hasStylishHat) : hasStylishHat(hasStylishHat){
	description = "Omnipresent Voice: I would say that you should take some time to reflect on your choices, but I think its a bit too late for that.";
	npcName = "The Captain";
}

void Plane::enter() {
	cout << description << endl;
	cout << "This is the last obstacle in your path. Usually I would ask you to not get into a fight here, but I honestly doubt that a choice in this scenario." << endl;
	cout << "Good Luck, Adventurer!" << endl;
	cout << npcName << ": My plane my rules! Rule number 1 is that I hate you and you can't fly on my plane." << endl;
	cout << "Rule number 2 is that there are no further rules." << endl;


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
			cout << npcName << ": Sucks to suck dumbass." << endl;
			return;
			}
		else if (playerInput == "2") {
			cout << npcName << "BRING IT ONNNNNNNNN!!!!" << endl;
			return;
		}
		else if (playerInput == "3") {
			cout << "*you lunge at The Captain's neck*" << endl;
			return;
		}
		else if (playerInput == "4" && hasStylishHat) {
			cout << "Omnipresent Voice: That was never going to work." << endl;
			cout << npcName << "Hmm ... No I think I'll beat you up now" << endl;
			return;
		}
		else {
			cout << npcName << "What the hell are you talking about." << endl;
			cout << "Omnipresent Voice: Bruh" << endl;
		}
	}
}