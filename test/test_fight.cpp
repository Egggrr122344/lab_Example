#include "gtest/gtest.h"
#include "/com.docker.devenvironments.code/include/factory.hpp"
#include "/com.docker.devenvironments.code/include/knight.hpp"
#include "/com.docker.devenvironments.code/include/merchant.hpp"
#include "/com.docker.devenvironments.code/include/observer.hpp"
#include "/com.docker.devenvironments.code/include/squirrel.hpp"
#include "/com.docker.devenvironments.code/include/fight.hpp"
#include "bits/stdc++.h"

TEST(FightManagerTest, AddEventAddsEventToQueue) {
    FightManager& manager = FightManager::get();
    FightEvent event;

    bool test = true;
    try {
        manager.add_event(std::move(event));
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}