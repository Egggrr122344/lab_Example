#include "gtest/gtest.h"
#include "/com.docker.devenvironments.code/include/factory.hpp"
#include "/com.docker.devenvironments.code/include/knight.hpp"
#include "/com.docker.devenvironments.code/include/merchant.hpp"
#include "/com.docker.devenvironments.code/include/observer.hpp"
#include "/com.docker.devenvironments.code/include/squirrel.hpp"
#include "bits/stdc++.h"

TEST(NPCFactoryTest, CreateNPC) {
    NPCFactory factory;
    bool test = true;
    try {
        std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
        std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
        std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Save) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s.insert(factory.createNPC(NPC_type::knight, 1, 2));
        s.insert(factory.createNPC(NPC_type::merchant, 3, 4));
        s.insert(factory.createNPC(NPC_type::squirrel, 5, 6));
        factory.save(s, "test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Load) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s = factory.load("test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCTest, OutputOperator) {
    std::shared_ptr<NPC> npc = std::make_shared<Knight>(1, 2);
    std::stringstream expected_output;
    expected_output << "knight_9 {x : 1, y : 2}";

    std::stringstream actual_output;
    actual_output << *npc.get();

    EXPECT_EQ(expected_output.str(), actual_output.str());
}

//_________________________________________________________________________________________________________________________
TEST(NPCTest, Getters) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 2);
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 3, 4);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 5, 6);

    EXPECT_EQ(knight->get_type(), "Knight");
    EXPECT_EQ(merchant->get_type(), "Merchant");
    EXPECT_EQ(squirrel->get_type(), "Squirrel");

    EXPECT_TRUE(knight->alive());
    EXPECT_TRUE(merchant->alive());
    EXPECT_TRUE(squirrel->alive());

    EXPECT_EQ(knight->get_x(), 1);
    EXPECT_EQ(merchant->get_x(), 3);
    EXPECT_EQ(squirrel->get_x(), 5);
    EXPECT_EQ(knight->get_y(), 2);
    EXPECT_EQ(merchant->get_y(), 4);
    EXPECT_EQ(squirrel->get_y(), 6);
}

TEST(NPCTest, Near) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 1);
    std::shared_ptr<NPC> merchant = factory.createNPC(NPC_type::merchant, 50, 1);
    std::shared_ptr<NPC> squirrel = factory.createNPC(NPC_type::squirrel, 100, 1);

    EXPECT_FALSE(knight->near(merchant, 10));
    EXPECT_TRUE(knight->near(merchant, 60));
    EXPECT_FALSE(knight->near(squirrel, 90));
    EXPECT_TRUE(knight->near(squirrel, 110));
}

TEST(NPCTest, Attach) {
    NPCFactory factory;
    std::shared_ptr<NPC> knight = factory.createNPC(NPC_type::knight, 1, 1);
    std::shared_ptr<Observer> console_observer, file_observer;
    console_observer = std::make_shared<ConsoleObserver>();
    file_observer = std::make_shared<FileObserver>();
    bool test = true;
    try {
        knight->attach(console_observer);
        knight->attach(file_observer);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}
