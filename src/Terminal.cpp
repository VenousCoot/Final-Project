#include "Room.h"
#include <iostream>

using namespace std;

Terminal::Terminal() {
	description = "Omnipresent Voice: Ok that guy was kinda a dick, but isn't it weird that you have run into 2 people and have gotten into 2 fights? Must be some kind of common denominator here.";
	npcName1 = "Simone Mueller";
	npcName2 = "Shopkeep";
}

void Terminal::enter() {
	cout << description << endl;
	cout << "Moving past your violent tendencies. This is terminal A, Newark's brand new terminal! It has 33 gates and over a dozen unique restaurants!" << endl;
	cout << "Not that it matters to you since you're probably just going to go get into a fight someone else, but I thought that I should at least let you know." << endl;

	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "Player Action Choices:" << endl;
		cout << "1. Go to one of the stores." << endl;
		cout << "2. Go looking for trouble." << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
			cout << "Omnipresent Voice: Wow, I wonder how long this non-violent streak of yours will last." << endl;
			cout << npcName2 << ": Welcome to the newest addition to Terminal A, Hudson Non-stop!" << endl;
			cout << "This is our fully self-checkout convenience store! Just grab what you need, and it is immediately pulled from your emergency savings account!" << endl;
			
			validInput = false;
			while (!validInput) {
				cout << "Player Dialog Options:" << endl;
				cout << "1. Oh, that sounds really cool!" << endl;
				cout << "2. If it's fully self-checkout why are you here?" << endl;
				getline(cin, playerInput);
				if (playerInput == "1") {
					cout << npcName2 << ": Please have a look at what's in stock!" << endl;
					// Bring you to the shop
				}
				else if (playerInput == "2"){
					cout << npcName2 << ": To keep assholes like you out." << endl;
					// Bring you to combat
				}
				else {
					cout << npcName2 << ": I'm sorry, were you trying to say something?" << endl;
					cout << "Omnipresent Voice: Is it really that hard? Just pick a 1 or a 2." << endl;
				}
			}
			

		}
		else if (playerInput == "2") {
			cout << "Omnipresent Voice: What a shocker you picked to look for a fight. I don't really know why I expected anything different from you." << endl;
			cout << npcName1 << ": HEY YOU!! My flight just got delayed 4 hours and you have the perfect face for punching!" << endl;

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
					cout << npcName1 << ": WHAT DID YOU SAY TO ME!?!?!" << endl;
					cout << "Omnipresent Voice: For the first time you have 3 whole choices to make and you still choose to press a random button. I'm seriously starting to get worried for you." << endl;

				}
			}
		}
	}

}