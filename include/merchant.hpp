#pragma once
#include "knight.hpp"
#include "npc.hpp"
#include "squirrel.hpp"

class Merchant : public NPC {
public:
    Merchant(int x, int y);
    std::string get_type() override;
    int get_damage_range() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> accepter) override;
    bool fight(std::shared_ptr<Merchant> accepter) override;
    bool fight(std::shared_ptr<Squirrel> accepter) override;

    void move(int max_x, int max_y) override;
};