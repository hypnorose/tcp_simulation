#include "../h/core.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


Core::Core(int n,int _maxPackets,int _speed){
    maxPackets = _maxPackets;
    speed = _speed * 2;
    for(int i = 0 ; i < n ;i ++){
        nodes.push_back(Node(i,i < n/2,i < n/2 ? i + n/2 : i - n /2,2));
    }
    init();
}
void Core::init(){
    rtt_ctr = 0;
}
void Core::step(){
    vector<Packet> toSendRandomized;
    
    
    for(int i = 0; i < speed && packets.size()!=0; i++){
        
        auto iter = packets.begin();
        Packet packet = nodes[iter->dst].rcv(*iter,rtt_ctr);
        packets.erase(iter);
        if(packet.type == Packet::NONE){
            continue;
        }
        toSendRandomized.push_back(packet);
    }
    random_shuffle(toSendRandomized.begin(), toSendRandomized.end());
    for(int j=0; j < toSendRandomized.size();j++){
            if(packets.size() < maxPackets){
                packets.push_back(toSendRandomized[j]);
            }
            else break;
    }
    toSendRandomized.clear();
    for(int i = 0 ; i < nodes.size();i++){
        vector<Packet> nodePackets = nodes[i].snd(rtt_ctr);
        toSendRandomized.insert(toSendRandomized.begin(),nodePackets.begin(),nodePackets.end());
    }
    random_shuffle(toSendRandomized.begin(), toSendRandomized.end());
    for(int j=0; j < toSendRandomized.size();j++){
            if(packets.size() < maxPackets){
                packets.push_back(toSendRandomized[j]);
            }
            else break;
    }
    rtt_ctr++;
}
void Core::printInfo(){
    double sum = 0;
    for(int i = 0; i < nodes.size();i++){
        cout.precision(2);
        cout << nodes[i].id << " " << setw(3) << nodes[i].acksAwaiting.size() << "/"<< setw(4) <<nodes[i].cwnd << " " << fixed << setw(8) <<(double)nodes[i].ackCount / rtt_ctr << " sgmnts/rtt " << 100.0 - 100.0 * ((double)nodes[i].ackCount/nodes[i].sndCount) << "\% packet loss"<<  endl;
        sum += (double)nodes[i].ackCount / rtt_ctr;
    }
    cout << "sum: " << sum << " sgmnts/rtt" << endl;
    cout << "avg: " << sum/nodes.size() << " sgmnts/rtt" << endl;
}
void Core::setAlpha(int val){
    for(int i = 0; i < nodes.size() ; i++){
        nodes[i].alpha = val;
    }
}
void Core::setBeta(double val){
    for(int i = 0; i < nodes.size() ; i++){
        nodes[i].beta= val;
    }
}

void Core::setTimeout(int val){
    for(int i = 0; i < nodes.size() ; i++){
        nodes[i].timeout_rtt = val;
    }
}

