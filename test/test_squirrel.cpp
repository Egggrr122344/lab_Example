#include "gtest/gtest.h"
#include "/com.docker.devenvironments.code/include/factory.hpp"
#include "/com.docker.devenvironments.code/include/knight.hpp"
#include "/com.docker.devenvironments.code/include/merchant.hpp"
#include "/com.docker.devenvironments.code/include/observer.hpp"
#include "/com.docker.devenvironments.code/include/squirrel.hpp"
#include "bits/stdc++.h"

TEST(SquirrelTest, ConstructorAndGetters) {
    Squirrel squirrel(1, 2);
    EXPECT_EQ(squirrel.get_x(), 1);
    EXPECT_EQ(squirrel.get_y(), 2);
    EXPECT_TRUE(squirrel.alive());
    EXPECT_EQ(squirrel.get_type(), "Squirrel");
}

TEST(SquirrelTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);

    EXPECT_FALSE(squirrel->accept(knight));
    EXPECT_TRUE(squirrel->alive());
    remove("battle_stats.txt");
    remove("test.txt");
}