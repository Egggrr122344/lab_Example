#pragma once
#include "merchant.hpp"
#include "npc.hpp"
#include "squirrel.hpp"

class Knight : public NPC {
public:
    Knight(int x, int y);
    std::string get_type() override;
    int get_damage_range() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Knight> accepter) override;
    bool fight(std::shared_ptr<Merchant> accepter) override;
    bool fight(std::shared_ptr<Squirrel> accepter) override;

    void move(int max_x, int max_y) override;
};