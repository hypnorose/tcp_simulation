#pragma once
#include <vector>
#include "node.h"
#include "packet.h"
using namespace std;
struct Core{
    vector<Node>  nodes;
    vector<Packet> packets;
    int maxPackets;
    int speed;
    unsigned int rtt_ctr;
    Core(int n,int _maxPackets,int _speed);
    void init();
    void step();
    void printInfo();
    void setAlpha(int val);
    void setBeta(double val);
    void setTimeout(int val);
};