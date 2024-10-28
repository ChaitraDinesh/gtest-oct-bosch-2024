#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(string_calculator_add, when_passes_a_single_number_returns_0_for_zero)
{
  //Arrange
  stringCalculator objunderTest;
  string input = "";
  int expectedValue = 0;

  //Act
  int actualValue = objunderTest.Add(input);

  //Assert
  ASSERT_EQ(expectedValue, actualValue);
}
