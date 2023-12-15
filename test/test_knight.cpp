#include "gtest/gtest.h"
#include "/com.docker.devenvironments.code/include/factory.hpp"
#include "/com.docker.devenvironments.code/include/knight.hpp"
#include "/com.docker.devenvironments.code/include/merchant.hpp"
#include "/com.docker.devenvironments.code/include/observer.hpp"
#include "/com.docker.devenvironments.code/include/squirrel.hpp"
#include "bits/stdc++.h"

TEST(KnightTest, ConstructorAndGetters) {
    Knight knight(1, 2);
    EXPECT_EQ(knight.getX(), 1);
    EXPECT_EQ(knight.getY(), 2);
    EXPECT_TRUE(knight.alive());
    EXPECT_EQ(knight.getType(), "Knight");
}

TEST(KnightTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);

    EXPECT_FALSE(knight->accept(knight));
    EXPECT_FALSE(knight->accept(merchant));
    EXPECT_FALSE(knight->accept(squirrel));
    EXPECT_TRUE(knight->alive());
}
