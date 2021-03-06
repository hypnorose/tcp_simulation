#include <gtest/gtest.h>
#include "../h/core.h"
#include "../h/packet.h"
#include <vector>
#include <iostream>
using namespace std;
#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

TEST(basic,dstCheck){
    Core core(6,1000,100);
    EXPECT_EQ(core.nodes[0].dst_id,3);
    EXPECT_EQ(core.nodes[3].dst_id,0);
    EXPECT_EQ(core.nodes[4].dst_id,1);
    EXPECT_EQ(core.nodes[5].dst_id,2);
    EXPECT_EQ(core.nodes[2].dst_id,5);
}

TEST(basic,send){
    Core core(6,1000,100);
    Packet rcvdAck;
    vector<Packet> rcvPackets; 
    rcvPackets = core.nodes[0].snd(0);
    rcvdAck = core.nodes[1].rcv(rcvPackets[0],1);
    core.nodes[0].rcv(rcvdAck,1);
    EXPECT_EQ(core.nodes[0].cwnd,2);
    
}
TEST(basic,backoff){
    Core core(6,1000,100);
    Packet rcvdAck;
    vector<Packet> rcvPackets; 
    rcvPackets = core.nodes[0].snd(0);
    rcvdAck = core.nodes[1].rcv(rcvPackets[0],1);
    core.nodes[0].rcv(rcvdAck,1);
    core.nodes[0].rcv(rcvdAck,1);
    core.nodes[0].rcv(rcvdAck,1);
    core.nodes[0].rcv(rcvdAck,1);
    core.nodes[0].rcv(rcvdAck,1); 
    core.nodes[0].rcv(rcvdAck,1); 
    core.nodes[0].rcv(rcvdAck,1); 
    rcvPackets = core.nodes[0].snd(2);
    rcvdAck = core.nodes[1].rcv(rcvPackets[0],2);
    core.nodes[0].snd(6);
    EXPECT_EQ(core.nodes[0].cwnd,1);
}
TEST(basic,duplicate){
    Core core(6,1000,100);
    Packet rcvdAck;
    vector<Packet> rcvPackets; 
    rcvPackets = core.nodes[0].snd(0);
    rcvdAck = core.nodes[1].rcv(rcvPackets[0],1);
    core.nodes[0].rcv(rcvdAck,1);
    core.nodes[0].rcv(rcvdAck,1);
    core.nodes[0].rcv(rcvdAck,1);
    EXPECT_EQ(core.nodes[0].cwnd,2);
    // it should be 2 because we erase ACK from ackAwaiting map at timeout
}