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