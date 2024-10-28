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

TEST_F(StringCalculatorAddFixture, returns_0_for_empty)
{
  string input = "";
  int expectedValue = "0";
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}
