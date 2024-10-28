#include "StringCalculator.h"
#include <gtest/gtest.h>

class StringCalculatorAddFixture:public testing::Test{
protected:
  StringCalculator *objUnderTest;
void Setup() override{
  objUnderTest= new StringCalculator();
}

void TearDown(){
  delete objUnderTest;
}
};

TEST_F(StringCalculatorAddFixture, when_passed_a_single_number_returns_0_for_empty)
{
  string input = "";
  int expectedValue = 0;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_zero)
{
  string input = "0";
  int expectedValue = 0;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_1_for_one)
{
  string input = "1";
  int expectedValue = 1;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_two_comma_delimited_numbers)
{
  int actualValue = objUnderTest->Add("5,6");
  ASSERT_EQ(actualValue, 11);
}

TEST(string_calculator_add, when_passed_multiple_comma_delimited_numbers)
{
  int actualValue = objUnderTest->Add("3,4,5");
  ASSERT_EQ(actualValue, 12);
}

TEST(string_calculator_add, when_delimited_with_newline_and_comma)
{ 
  int actualValue = objUnderTest->Add("1\n2,3");
  ASSERT_EQ(actualValue, 6);
}

TEST(string_calculator_add, when_passed_a_delimiter)
{
  int actualValue = objUnderTest->Add("//;\n1;2;3");
  ASSERT_EQ(actualValue, 6);
}

TEST(string_calculator_add, when_passed_numbers_over_1000)
{
  int actualValue = objUnderTest->Add("1,2,1001");
  ASSERT_EQ(actualValue, 3);
}

TEST(string_calculator_add, when_passed_multicharacter_delimiter)
{
  int actualValue = objUnderTest->Add("//[***]\n1***2***3");
  ASSERT_EQ(actualValue, 6);
}

TEST(string_calculator_add, when_passed_multiple_delimiters)
{
  int actualValue = objUnderTest->Add("//[***]\n1***2***3***4");
  ASSERT_EQ(actualValue, 10);
}

TEST(string_calculator_add, when_passed_multiple_multicharacter_delimiter)
{
  int actualValue = objUnderTest->Add("//[***]\n1***2***3//[***]\n1***2***3");
  ASSERT_EQ(actualValue, 12);
}
