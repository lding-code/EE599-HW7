#include "gtest/gtest.h"
#include <string>
#include <iostream>

#include "src/lib/solution.h"

TEST(HelloWorldShould, ReturnHelloWorld) {
    Solution solution;

    std::string actual = solution.HelloWorld();
    std::string expected = "HelloWorld";

    EXPECT_EQ(expected, actual);
}