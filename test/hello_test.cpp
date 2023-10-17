#include <gtest/gtest.h>
#include <lib.h>

TEST(firstConstructorTest, BasicAssertions) {
  // arrange 
  Money money1 {};
  

  // assert
  
    EXPECT_EQ (money1.getArray(), nullptr);
    EXPECT_EQ (money1.getSize(), 0);
  
}

TEST(SecondConstructorTest, BasicAssertions) {
  // arrange
   Money money1(3,5);

   // assert

   EXPECT_EQ (money1.getSize(),3);
   EXPECT_EQ (money1.getArray()[0],5);
   
}

TEST(diffError, BasicAssertions) {
  // arrange
  Money money1 {1,2,3,4};
  Money money2 {5,6,7,8};

  // assert
  EXPECT_THROW (money1.operator-(money2), invalid_argument);
}


TEST(DiffTest1, BasicAssertions) {
  // arrange 
  Money money1 {1,2,5,3};
  Money money2 {1,2,5,3};

  unsigned char array[] {0,0,0,0};
  size_t arrSize = 4;

  // act
  Money result = money1.operator-(money2);

  // assert
  for (size_t i {0}; i < result.getSize(); i++) {
    EXPECT_EQ(result.getArray()[i], array[arrSize-i-1]);
  }
}

TEST(DiffTest2, BasicAssertions) {
  // arrange
  Money money1 {1,2,3,4};
  Money money2 {3,4,5,6};

  unsigned char array[] {2,2,2,2};
  size_t arrSize = 4;

  // act
  Money result = money2.operator-(money1);

  // assert
  for (size_t i {0}; i < result.getSize(); i++) {
    EXPECT_EQ(result.getArray()[i], array[arrSize-i-1]);
  }


}

TEST(SumTest1, BasicAssertions) {
  // arrange
  Money money1 {0,0,0,5};
  Money money2 {0,5,5,1};

  unsigned char array[] {6,5,5,0};
  size_t  arrSize = 4; 

  // act
  Money result = money1.operator+(money2);

  // assert
  for (size_t i {0}; i < result.getSize(); i++) {
    EXPECT_EQ(result.getArray()[i], array[arrSize-i-1]);
  }
    
  
}

TEST(SumTest3, BasicAssertions) {
  // arrange
  Money money1 {0,0,5,5,5};
  Money money2 {1,2,6,7,8}; // 1431,21

  unsigned char array[] {1,4,3,1,2,1};
  size_t  arrSize = 6; 

  // act
  Money result = money1.operator+(money2);

  // assert
  for (size_t i {0}; i < result.getSize(); i++) {
    EXPECT_EQ(result.getArray()[i], array[arrSize-i-1]);
  }
}


TEST(isLess, BasicAssertions) {
  // arrange
  Money money1 {1,2,3,4};
  Money money2 {3,4,5,6};

  // act
  bool result = true;

  // assert
  
    EXPECT_EQ(money1.operator<(money2), result);
  
}

TEST(isHigh, BasicAssertions) {
  // arrange
  Money money1 {1,2,3,4};
  Money money2 {3,4,5,6};

  // act
  bool result = false;

  // assert
  
    EXPECT_EQ(money1.operator>(money2), result);
  
}

TEST(isEqual, BasicAssertions) {
  // arrange
  Money money1 {1,2,3,4};
  Money money2 {3,4,5,6};

  // act
  bool result = false;

  // assert
  
    EXPECT_EQ(money1.operator==(money2), result);
  
}

TEST(copyTest, BasicAssertions) {
  // arrange
  Money money1 {1,2,3,4};

  // act
  Money money3 = money1;

  // assert
  
    EXPECT_EQ(money3,money1);
  
}


TEST(SetAmount, BasicAssertions) {
  // arrange
  Money money1;
  
  size_t arrSize = 4;
  unsigned char result[] {4,3,2,1};

  // act
  money1.setAmount({1,2,3,4});

  // assert
  for (size_t i {0}; i < arrSize; i++) {
    EXPECT_EQ(money1.getArray()[i],result[arrSize-i-1]);
  }
    
  
}

TEST(setError, BasicAssertions) {
  // arrange
  Money money1;

  size_t arrSize = 0;
  unsigned char result[] {};

  // assert
  EXPECT_THROW(money1.setAmount({}), invalid_argument);
}

TEST(movingTest, BasicAssertions) {
  // arrange
  Money money1 (2,3);

  // act
  Money money2 (move(money1));

  // assert
  EXPECT_EQ(money1.getArray(), nullptr);
  EXPECT_EQ(money1.getSize(), 0);

  for (size_t i {0}; i < 2; i++) {
    EXPECT_EQ(money2.getArray()[i], 3);
  }
  
  EXPECT_EQ(money2.getSize(),2);

}

