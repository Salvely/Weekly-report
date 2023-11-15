#include <gtest/gtest.h>
#include <iostream>

TEST(TestName, SubTest_1) { ASSERT_FALSE(1 == 2); }
TEST(TestName2, SubTest_1) { ASSERT_TRUE(1 == 2); }
int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
