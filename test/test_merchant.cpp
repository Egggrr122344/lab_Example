#include "gtest/gtest.h"
#include "/com.docker.devenvironments.code/include/factory.hpp"
#include "/com.docker.devenvironments.code/include/knight.hpp"
#include "/com.docker.devenvironments.code/include/merchant.hpp"
#include "/com.docker.devenvironments.code/include/observer.hpp"
#include "/com.docker.devenvironments.code/include/squirrel.hpp"
#include "bits/stdc++.h"

TEST(MerchantTest, ConstructorAndGetters) {
    Merchant merchant(1, 2);
    EXPECT_EQ(merchant.get_x(), 1);
    EXPECT_EQ(merchant.get_y(), 2);
    EXPECT_TRUE(merchant.alive());
    EXPECT_EQ(merchant.get_type(), "Merchant");
}

TEST(MerchantTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);

    EXPECT_FALSE(merchant->accept(merchant));
    EXPECT_FALSE(merchant->accept(squirrel));
    EXPECT_TRUE(merchant->alive());
}