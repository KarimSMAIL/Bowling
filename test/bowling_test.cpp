#include "gtest/gtest.h"
#include "bowling.h"

bool TestValidLine(string lineData)
{
    return get<0>(validLine(lineData));
}

int TestcalculateScore(string lineData)
{
    return calculateScore(get<1>(validLine(lineData)));
}

TEST(BowlingTest, NumberOfTernesMin)
{
    ASSERT_FALSE(TestValidLine("XXXXXXXXXX"));
}

TEST(BowlingTest, NumberOfTernesMax)
{
    ASSERT_FALSE(TestValidLine("XXXXXXXXXXXXXXXXXXXXXX"));
}

TEST(BowlingTest, InvalidRegulExpression)
{
    ASSERT_FALSE(TestValidLine("AZERTYUIERTYOP"));
}

TEST(BowlingTest, ValidNumberOfTernes)
{
    ASSERT_TRUE(TestValidLine("XXXXXXXXXXXX"));
}

TEST(BowlingTest, ValidInput)
{
    ASSERT_TRUE(TestValidLine("9-9-9-9-9-9-9-9-9-9-"));
}

TEST(BowlingTest, ValidInput2)
{
    ASSERT_TRUE(TestValidLine("5/5/5/5/5/5/5/5/5/5/5"));
}

TEST(BowlingTest, ValidScore1)
{
    ASSERT_EQ(300, TestcalculateScore("XXXXXXXXXXXX"));
}

TEST(BowlingTest, ValidScore2)
{
    ASSERT_EQ(90, TestcalculateScore("9-9-9-9-9-9-9-9-9-9-"));
}

TEST(BowlingTest, ValidScore3)
{
    ASSERT_EQ(150, TestcalculateScore("5/5/5/5/5/5/5/5/5/5/5"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}