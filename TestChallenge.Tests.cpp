#include "TestChallenge.h"
#include <gtest/gtest.h>
 
TEST(AddTest, CorrectSum) {
    int result = 0;
    add(5, 3, &result);
    EXPECT_EQ(result, 8);
}
 
TEST(AddTest, IncorrectOutput) {
    int result = 0;
    add(5, 3, &result);
    EXPECT_EQ(to_string(result), "Sum of 5:3 is 8");
}
