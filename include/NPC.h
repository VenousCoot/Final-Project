#ifndef NPC_H
#define NPC_H

#include <string>

class NPC {
private:
    std::string name;
    int health;
    int attack;
    int attackWeight;
    int blockWeight;
    int doNothingWeight;
    int specialAttackWeight;
    int instaKillWeight;
    std::string action;

public:
    // Constructor
    NPC(const std::string& npcName, int initialHealth, int initialAttack, int attackW, int blockW, int doNothingW, int specialW, int instaW);

    // Getter
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    std::string getAction() const;

    // Methods
    void changeHealth(int amount);
    void changeAttack(int amount);
    std::string performAction();
};

#endif // NPC_H
