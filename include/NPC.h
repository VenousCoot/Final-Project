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

public:
    // Constructor
    NPC(const std::string& npcName, int initialHealth, int initialAttack , int attackW, int blockW, int doNothingW, int specialW, int instaW);

    // Getter
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;

    // Methods
    void changeHealth(int amount);
    void performAction() const;
    void changeAttack(int amount);
};

#endif // NPC_H