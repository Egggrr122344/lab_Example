#pragma once
#include "merchant.hpp"
#include "npc.hpp"
#include "squirrel.hpp"

class Knight : public NPC {
public:
    Knight(int x, int y);
    std::string getType() override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(Knight& accepter) override;
    bool fight(Merchant& accepter) override;
    bool fight(Squirrel& accepter) override;
};

