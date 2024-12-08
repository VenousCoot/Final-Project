#include "Room.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
