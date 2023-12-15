#pragma once
#include "knight.hpp"
#include "merchant.hpp"
#include "npc.hpp"

class Squirrel : public NPC {
public:
    Squirrel(int x, int y);
    std::string getType() override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(Knight& accepter) override;
    bool fight(Merchant& accepter) override;
    bool fight(Squirrel& accepter) override;
};

