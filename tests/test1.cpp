#include <gtest/gtest.h>
#include "../h/core.h"
#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

TEST(basicStructure,coreAndNodes){
    Core core(6,1000,100);
    EXPECT_EQ(core.nodes[0].dst_id,3);
    EXPECT_EQ(core.nodes[3].dst_id,0);
    EXPECT_EQ(core.nodes[4].dst_id,1);
    EXPECT_EQ(core.nodes[5].dst_id,2);
    EXPECT_EQ(core.nodes[2].dst_id,5);
}
