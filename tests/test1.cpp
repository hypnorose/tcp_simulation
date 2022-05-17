#include <gtest/gtest.h>
#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

TEST(test1,BasicAssertions){

    EXPECT_EQ(3*4,12);
    EXPECT_EQ(2+2*2,6);
}
TEST(test1,BasicAssertions2){

    EXPECT_EQ(3*4,12);
    EXPECT_EQ(2+2*2+1,7);
}