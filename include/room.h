#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "character.h"

using namespace std;

class Room {
public:
    virtual void enter() = 0;
protected:
    string description;
};

class Lobby : public Room {
public:
    Lobby();
    void enter() override;
private:
    string npcName;
};

class Security : public Room {
public:
    Security();
    void enter() override;
private:
    string npcName;
};

class Terminal{
public:
    Terminal();
    void enterTerminal(main_character& player);
private:
    string npcName1;
    string npcName2;
protected:
    string description;
};

class Gate{
public:
    Gate(bool hasFirstClassBoardingPass);
    void enterGate(main_character& player);
    void setBoardingPass(bool value);
private:
    bool hasFirstClassBoardingPass;
    string npcName;
protected:
    string description;
};

class Plane : public Room {
public:
    Plane(bool hasStylishHat);
    void enter() override;
    void setStylishHat(bool value);
private:
    string npcName;
    bool hasStylishHat;
};

#endif // ROOM_H
