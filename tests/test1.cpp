#include <gtest/gtest.h>
#include "../h/core.h"
#include "../h/packet.h"
#include <vector>
#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

TEST(basicStructure,dstCheck){
    Core core(6,1000,100);
    EXPECT_EQ(core.nodes[0].dst_id,3);
    EXPECT_EQ(core.nodes[3].dst_id,0);
    EXPECT_EQ(core.nodes[4].dst_id,1);
    EXPECT_EQ(core.nodes[5].dst_id,2);
    EXPECT_EQ(core.nodes[2].dst_id,5);
}

TEST(basicStructure,sendCheck){
    Core core(6,1000,100);
    vector<Packet> rcvPackets = core.nodes[0].snd(0);
    Packet rcvdAck = core.nodes[1].rcv(rcvPackets[0],1);
    core.nodes[0].rcv(rcvdAck,1);
    EXPECT_EQ(core.nodes[0].cwnd,2);
    core.nodes[0].rcv(rcvdAck,1);
}
