#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_empty_string)
{
  //Arrange
  StringCalculator objunderTest;
  string input = "";
  int expectedValue = 0;

  //Act
  int actualValue = objunderTest.Add(input);

  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_zero)
{
  //Arrange
  StringCalculator objunderTest;
  string input = "0";
  int expectedValue = 0;

  //Act
  int actualValue = objunderTest.Add(input);

  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_1_for_one)
{
  //Arrange
  StringCalculator objunderTest;
  string input = "1";
  int expectedValue = 1;

  //Act
  int actualValue = objunderTest.Add(input);

  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}
