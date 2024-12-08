#include "room.h"
#include <iostream>

using namespace std;

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
			cout << npcName << "What the hell are talking about." << endl;
			cout << "Omnipresent Voice: Bruh" << endl;
		}
	}
}