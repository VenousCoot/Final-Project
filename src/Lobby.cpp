#include "Room.h"
#include <iostream>

using namespace std;

Lobby::Lobby() {
    description = "Omnipresent Voice: This is the lobby of Terminal A. What wonderful news, There's a receptionist right here for you to talk to!";
    npcName = "Receptionist";
}

void Lobby::enter() {
    cout << description << endl;
    cout << npcName << endl;
    cout << ": Welcome to Newark Airport! May I see your boarding pass?" << endl;

    string playerInput;
    bool validInput = false;

    while (!validInput) {
        cout << "Player Dialog Choices:" << endl;
        cout << "1. Here you go I have it right here!" << endl;
        cout << "2. Boarding Pass? What's that?" << endl;
        getline(cin, playerInput);

        if (playerInput == "1") {
            cout << npcName << ": Hmm… this sure doesn’t seem like it’s yours. Got any ID?" << endl;

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Choices:" << endl;
                cout << "1. Uhh ... You know what, I don't seem to have it with me right now." << endl;
                cout << "2. That's me! Is there something wrong with your eyes?!" << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    cout << npcName << ": Alright kid, I'm gonna have to show you the exit." << endl;
                    return;
                }
                else if (playerInput == "2") {
                    cout << npcName << ": DON'T YOU DARE TALK TO ME THAT WAY" << endl;
                    return;
                }
                else {
                    cout << npcName << ": I'm sorry, were you trying to say something?" << endl;
                    cout << "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2." << endl;
                }
            }
        }
        else if (playerInput == "2") {
            cout << npcName << ": Listen here bub, if you don’t have a boarding pass get the hell out of my line." << endl;

            validInput = false;
            while (!validInput) {
                cout << "Player Dialog Choices:" << endl;
                cout << "1. Woah woah woah that’s not cool" << endl;
                cout << "2. Oh you wanna fight? Lets do this." << endl;
                getline(cin, playerInput);

                if (playerInput == "1") {
                    cout << npcName << ": That's it I'm gonna kick your ass!" << endl;
                    return;
                }
                else if (playerInput == "2") {
                    return;
                }
                else {
                    cout << npcName << ": I'm sorry, were you trying to say something?" << endl;
                    cout << "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2." << endl;
                }
            }
        }
        else {
            cout << npcName << ": I'm sorry, were you trying to say something?" << endl;
            cout << "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2." << endl;
        }
    }
}
