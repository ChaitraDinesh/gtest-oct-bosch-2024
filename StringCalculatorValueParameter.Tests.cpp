#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
using namespace std;

class StringCalculatorAddFixture:public testing::Test{
  protected:
    StringCalculator *objUnderTest;
  void SetUp() override {
      objUnderTest=new StringCalculator();
  }
  void TearDown(){
        delete objUnderTest;
  }
};

//Parameterized Fixture
class StringCalculatorAddParameterizedFixture:
                                public StringCalculatorAddFixture,
                                public testing::WithParamInterface<tuple<string,int>>{
};

INSTANTIATE_TEST_SUITE_P(ValidValueDataSet, StringCalculatorAddParameterizedFixture, testing::Values(
  make_tuple("",0), make_tuple("0",0), make_tuple("1",1), make_tuple("1,2",3)
));

//fails testcase
INSTANTIATE_TEST_SUITE_P(NegetiveValuesDataSet,StringCalculatorAddParameterizedFixture,testing::Values(
  make_tuple("",10),make_tuple("0",12),make_tuple("1",10),make_tuple("4,5",6)
));

TEST_P(StringCalculatorAddParameterizedFixture, DataDrivenTestCase)
{
  string input = std::get<0>(GetParam());
  int expectedValue=std::get<1>(GetParam());
  int actualValue=objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, Throw_Invalid_Argument_Exception_For_Negative_Numbers){
string input = "1, -2";
EXPECT_THROW(objUnderTest->Add(input), invalid_argument);
}
