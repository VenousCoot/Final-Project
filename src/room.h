#ifndef ROOM_H
#define ROOM_H

#include <string>

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

class Terminal : public Room {
public:
    Terminal();
    void enter() override;
private:
    string npcName1;
    string npcName2;
};

class Gate : public Room {
public:
    Gate(bool hasFirstClassBoardingPass);
    void enter() override;
private:
    string npcName;
    bool hasFirstClassBoardingPass;
};

class Plane : public Room {
public:
    Plane();
    void enter() override;
private:
    string npcName;
};

#endif // ROOM_H
