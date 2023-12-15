#pragma once
#include "knight.hpp"
#include "npc.hpp"
#include "squirrel.hpp"

class Merchant : public NPC {
public:
    Merchant(int x, int y);
    std::string getType() override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(Knight& accepter) override;
    bool fight(Merchant& accepter) override;
    bool fight(Squirrel& accepter) override;
};

