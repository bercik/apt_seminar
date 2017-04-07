#include "gtest/gtest.h"
#include "panic.h"

TEST(PanicTest, TestPanic)
{
    ASSERT_EXIT(panic("This is just a test"), ::testing::ExitedWithCode(1), 
            "This is just a test");
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
