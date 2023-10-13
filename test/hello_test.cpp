#include <gtest/gtest.h>
#include <lib.h>


TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange 
  Money money1 {1,2,5,3};

  Money money2 {1,2,5,3};

  unsigned char array[] {0,0,0,0};
  int arrSize = 4;

  // act
  Money result = money1.operator-(money2);
  
  

  // assert
  for (size_t i {0}; i < result.getSize(); i ++) {
    EXPECT_EQ(result.getArray()[i], array[arrSize-i- 1]);
  }
}