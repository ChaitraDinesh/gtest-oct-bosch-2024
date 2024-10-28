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
  StringCalculator objunderTest;
  string input = "0";
  int expectedValue = 0;

  int actualValue = objunderTest.Add(input);
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_1_for_one)
{
  StringCalculator objunderTest;
  string input = "1";
  int expectedValue = 1;
  
  int actualValue = objunderTest.Add(input);
  ASSERT_EQ(expectedValue, actualValue);
}

TEST(string_calculator_add, when_passed_two_comma_delimited_numbers)
{
  StringCalculator objunderTest;
  int actualValue = objunderTest.Add("5,6");
  ASSERT_EQ(11, actualValue);
}

TEST(string_calculator_add, when_passed_multiple_comma_delimited_numbers)
{
  StringCalculator objunderTest;
  int actualValue = objunderTest.Add("3,4,5");
  ASSERT_EQ(12, actualValue);
}

TEST(string_calculator_add, when_delimited_with_newline_and_comma)
{
  StringCalculator objunderTest;
  int actualValue = objunderTest.Add("1\n2,3");
  ASSERT_EQ(6, actualValue);
}
