#include <string>
#include <iostream>
#include <room.h>

using namespace std;


int main()
{
	cout <<"Welcome to Hell Adventurer, this is Newark Liberty International Airport!" << endl;
	cout <<"Voted the worst airport in the United States according to AirHelp's Global Airport Ranking (2019)." << endl;
	cout <<"It looks like you have a flight departing in ... 1 hour!! Better Hurry!" << endl;

	Lobby lobby;
	lobby.enter();

	Security security;
	security.enter();

	Terminal terminal;
	terminal.enter();

	return 0; 
}