#include <gtest/gtest.h>
#include "function.h"



TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange 
  unsigned long int number = 10;

  // act
  string result = Get_To_Str(number);
  // assert
  EXPECT_EQ(result, "00000000000000000000000000001010");
}
TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  // arrange 
  unsigned long int number = 32 ;


  // act
  string result = Get_To_Str(number);
  // assert
  EXPECT_EQ(result, "00000000000000000000000000100000");
}
TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  // arrange 
  unsigned long int number = 64;

  // act
  string result = Get_To_Str(number);
  // assert
  EXPECT_EQ(result, "00000000000000000000000001000000");
}


  TEST(ExampleOfStandartUsageTest4, BasicAssertions) {
    // arrange
    unsigned long int number = 2828281212 ;
    // act
    string result {Get_To_Str(number)};
    // result
    EXPECT_EQ (result, "10101000100101000010010101111100");
  }
    TEST(ExampleOfStandartUsageTest5, BasicAssertions) {
    // arrange
    unsigned long int number = 128 ;
    // act
    string result {Get_To_Str(number)};
    // result
    EXPECT_EQ (result, "00000000000000000000000010000000");
  }
    TEST(ExampleOfStandartUsageTest6, BasicAssertions) {
    // arrange
    unsigned long int number = 256 ;
    // act
    string result {Get_To_Str(number)};
    // result
    EXPECT_EQ (result, "00000000000000000000000100000000");
  }
