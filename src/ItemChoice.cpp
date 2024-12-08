#include "Items.h"
#include "character.h"
#include <iostream>

using namespace std;

void LobbyItems() {

	cout << "Receptionist: You won't make it through security like that." << endl;
	cout << "Omnipresent Voice: Oh look at that! She dropped a suitcase!" << endl;
	cout << "Pick an Item from these Choices:" << endl;

	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "1. Stanley Cup - Increases damage dealt by 1!" << endl;
		cout << "2. Advil - Increase maximum health by 1!" << endl;
		cout << "3. Slightly Browned Banana - Restores 3 health!" << endl;
		cout << "4. 63 Whole Dollars!" << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
			main_character::add_item(Item("Stanley Cup", "Swords", 1, 0, 0, false));
			cout << "Added Stanley Cup!" << endl;
			return;
		}
		else if (playerInput == "2") {
			main_character::add_item(Item("Advil", "Shields", 0, 1, 0, false));
			cout << "Added Advil!" << endl;
			return;
		}
		else if (playerInput == "3") {
			main_character::add_item(Item("Slightly Browned Banana", "Potions", 0, 3, 0, false));
			cout << "Added Slightly Browned Banana!" << endl;
			return;
		}
		else if (playerInput == "4") {
			main_character::update_parameter("money", 63);
			cout << "Added 63 dollars!" << endl;
			return;
		}
		else {
			cout <<"Omnipresent Voice: Please select an Item to aid you on your Journey!"
		}
	}

}

void SecurityItems() {
	cout << "TSA Agent: That was a cheap shot ... I'll have you cavity searched next time you come through here." << endl;
	cout << "Omnipresent Voice: Theres a bunch of stuff on that desk behind him."
	cout << "Pick an Item:" << endl;

	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "1. TSA Beat-stick - Increases Base Damage by 1" << endl;
		cout << "2. Half a Bottle of Whiskey - Potion that Increases Damage by 2 on use (only lasts for 1 combat)" << endl;
		cout << "3. Stylish Hat - Makes you more Personable (more chat options)" << endl;
		cout << "4. Suspicious Ticking Suitcase - I wonder what this does??" << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
			main_character::add_item(Item("TSA Beat-stick", "Swords", 1, 0, 0, false));
			cout << "Added TSA Beat-stick!" << endl;
			return;
		}
		else if (playerInput == "2") {
			main_charater::add_item(Item("Half a Bottle of Whiskey", "Potions", 2, 0, 0, false));
			cout << "Added Half a Bottle of Whiskey!" << endl;
			return;
		}
		else if (playerInput == "3") {
			main_character::add_item(Item("Stylish Hat", "Potions", 0, 0, 0, false));
			cout << "Added Stylish Hat!" << endl;
			return;
		}
		else if (playerInput == "4") {
			main_character::add_item(Item("Suspicious Ticking Suitcase", "Potions", 0, 0, 0, false));
			cout << "Added Suspicious Ticking Suitcase!" << endl;
			return;
		}
		else {
			cout << "Just pick a number between 1 and 4" << endl;

		}
	}

	void TerminalItems() {

		cout << "Annoyed Man: Wow! That really helped me release some of the stress! Thanks man!" << endl;
		cout << "Omnipresent Voice: You beating the crap out of him made him drop his suitcase if you wanna rob him too." << endl;
		cout << "Rummage Through this guys stuff:" << endl;

		string playerInput;


	}




}
