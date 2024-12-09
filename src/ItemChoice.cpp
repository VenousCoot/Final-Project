#include "Items.h"
#include "character.h"
#include <iostream>

using namespace std;

void LobbyItems(main_character& mc) {

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
			mc.add_item(Item("Stanley Cup", "Swords", 1, 0, 0, false, false, false));
			cout << "Added Stanley Cup!" << endl;
			return;
		}
		else if (playerInput == "2") {
			mc.add_item(Item("Advil", "Shields", 0, 1, 0, false, false, false));
			cout << "Added Advil!" << endl;
			return;
		}
		else if (playerInput == "3") {
			mc.add_item(Item("Slightly Browned Banana", "Potions", 0, 3, 0, false, true, false));
			cout << "Added Slightly Browned Banana!" << endl;
			return;
		}
		else if (playerInput == "4") {
			mc.update_parameter("money", 63);
			cout << "Added 63 dollars!" << endl;
			return;
		}
		else {
			cout << "Omnipresent Voice: Please select an Item to aid you on your Journey!" << endl;
		}
	}

}

void SecurityItems(main_character& mc) {
	cout << "TSA Agent: That was a cheap shot ... I'll have you cavity searched next time you come through here." << endl;
	cout << "Omnipresent Voice: Theres a bunch of stuff on that desk behind him." << endl;
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
			mc.add_item(Item("TSA Beat-stick", "Swords", 1, 0, 0, false, false, false));
			cout << "Added TSA Beat-stick!" << endl;
			return;
		}
		else if (playerInput == "2") {
			mc.add_item(Item("Half a Bottle of Whiskey", "Potions", 2, 0, 0, false, true, false));
			cout << "Added Half a Bottle of Whiskey!" << endl;
			return;
		}
		else if (playerInput == "3") {
			mc.add_item(Item("Stylish Hat", "Potions", 0, 0, 0, false, false, false));
			cout << "Added Stylish Hat!" << endl;
			return;
		}
		else if (playerInput == "4") {
			mc.add_item(Item("Suspicious Ticking Suitcase", "Potions", 0, 0, 0, false, true, false));
			cout << "Added Suspicious Ticking Suitcase!" << endl;
			return;
		}
		else {
			cout << "Omnipresent Voice: Just pick a number between 1 and 4" << endl;

		}
	}




}

void TerminalItems(main_character& mc) {

	cout << "Annoyed Man: Wow! That really helped me release some of the stress! Thanks man!" << endl;
	cout << "Omnipresent Voice: You beating the crap out of him made him drop his suitcase if you wanna rob him too." << endl;
	cout << "Rummage Through this guys stuff:" << endl;

	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "1. Laptop Bag - Gives you +2 Base Damage! I bet he has a ThinkPad!" << endl;
		cout << "2. Meat Shield - Have your new friend take 1 hit for you!" << endl;
		cout << "3. Shake Shack - Heal 6 Health!" << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
			mc.add_item(Item("Laptop Bag", "Swords", 2, 0, 0, false));
			cout << "Added Laptop Bag!" << endl;
			return;
		}
		else if (playerInput == "2") {
			mc.add_item(Item("Meat Shield", "Shields", 0, 5, 0, false));
			cout << "Added Meat Shield!" << endl;
			return;
		}
		else if (playerInput == "3") {
			mc.add_item(Item("Shake Shack", "Potions", 0, 6, 0, false));
		}
		else {
			cout << "Omnipresent Voice: I really wish I could give you no items, but that's not how this works." << endl;

		}
	}

}

void GateItems(main_character& mc) {

	cout << "Flight Attendant: You will never defeat The Captain!" << endl;
	cout << "Omnipresent Voice: Well, what are you waiting for? This is no time for you to finally grow some morals. Steal her stuff like you always do." << endl;
	cout << "Rob the Flight Attendant:" << endl;

	string playerInput;
	bool validInput = false;

	while (!validInput) {
		cout << "1. Stun Gun - Increases Base Damage by 2!" << endl;
		cout << "2. Security Vest - Reduce Damage taken by 2!" << endl;
		cout << "3. Half a Hotdog and a Redbull - Increases Damage by 3 for one combat, but deals 3 damage to you! Is that mold?" << endl;
		getline(cin, playerInput);

		if (playerInput == "1") {
			mc.add_item(Item("Stun Gun", "Swords", 2, 0, 0, false));
			cout << "Added Stun Gun!" << endl;
			cout << "... What's this?" << endl;
			cout << "Added TSA Service Weapon! One in the Chamber! Deals 12 Damage!" << endl;
			mc.add_item(Item("TSA Service Weapon", "Swords", 12, 0, 0, false));
			return;
		}
		else if (playerInput == "2") {
			mc.add_item(Item("Security Vest", "Shields", 0, 2, 0, false));
			cout << "Added Security Vest!" << endl;
			cout << "... What's this?" << endl;
			cout << "Added TSA Service Weapon! One in the Chamber! Deals 12 Damage!" << endl;
			mc.add_item(Item("TSA Service Weapon", "Swords", 12, 0, 0, false));
			return;
		}
		else if (playerInput == "3") {
			mc.add_item(Item("Half a Hotdog and a Redbull", "Potions", 3, -3, 0, false));
			cout << "Added Half a Hotdog and a Redbull!" << endl;
			cout << "... What's this?" << endl;
			cout << "Added TSA Service Weapon! One in the Chamber! Deals 12 Damage!" << endl;
			mc.add_item(Item("TSA Service Weapon", "Swords", 12, 0, 0, false));
			return;
		}
		else {
			cout << "Omnipresent Voice: You know what? Screw you, you get no item." << endl;
			return;
		}
	}

	
}
