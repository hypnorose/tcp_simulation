#pragma once
#include "packet.h"
#include <map>
#include <vector>
using namespace std;
struct Node{
    
    int alpha;
    double beta;
    int cwnd;
    
    int id,site, seq_number,dst_id,timeout_rtt,cwnd_thresh,last_rtt,
    ackCount,sndCount;
    map<int,int> acksAwaiting;
    int last_seq;
    Node(int _id,int _site,int _dst_id,int _timeout_rtt);
    void init();
    void setAlpha(int _alpha);
    void setBeta(double _beta);
    void setTimeout(int _timeout);
    void backoff();
    void incr();
    
    Packet rcv(Packet packet,int rtt);
    vector<Packet> snd(int rtt);
    pair<int,int> getOldestNotAcked();
    int notAckedCount();
};