#include "Room.h"
#include <iostream>

using namespace std;

Security::Security() {
	description = "Omnipresent Voice: You really beat up that middle aged woman didn't you? You feeling good about yourself? You feel like you're top dog now don't you?";
	npcName = "TSA Agent";
}

void Security::enter() {
	cout << description << endl;
	cout << "Anyways this is the security check. Be careful the TSA here can be touchy!" << endl;
	cout << npcName << ": Single file line, shoes off. Hey you, get back in line! *points at you*" << endl;



	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "Player Dialog Choices:" << endl;
		cout << "1. I am in line. Why are you yelling at me?" << endl;
		cout << "2. What is wrong with the people around here?" << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
			cout << npcName << ": Oh are you giving me lip?" << endl;
			return;
		}
		else if (playerInput == "2") {
			cout << npcName << ": You don’t know how long I’ve been waiting for this." << endl;
			return;
		}
		else {
			cout << npcName << ": I'm sorry, were you trying to say something?" << endl;
			cout << "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2." << endl;
		}
	}
}