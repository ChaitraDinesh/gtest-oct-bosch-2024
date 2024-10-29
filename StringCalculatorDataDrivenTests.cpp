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
void assertEachDataRow(string& input, int expectedValue)
{
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorDataDrivenAddFixture, DataDrivenTest)
{
  vector<tuple<string,int> dataSet;
  dataset.pushback(make_tuple("",0));
  dataset.pushback(make_tuple("0",0));
  dataset.pushback(make_tuple("1",1));
  dataset.pushback(make_tuple(1,2));
  //iterate
  for(tuple<string,int> dataRow : dataSet)
    {
      assertEachDataRow(dataRow.get<string>(0),dataRow.get<int>(1))
    }
}
