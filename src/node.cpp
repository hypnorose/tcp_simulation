#include <vector>
#include "../h/node.h"
using namespace std;


Node::Node(int _id,int _site,int _dst_id,int _timeout_rtt = 3){
    dst_id = _dst_id;
    id = _id;
    site = _site;
    timeout_rtt = _timeout_rtt;
    init();
}
void Node::init(){
    cwnd = 1;
    seq_number = 0;
    last_seq = 0;
    alpha = 1;
    beta = 0.5;
    last_rtt = -1;
    cwnd_thresh = 1<<20;
    ackCount = 0;
}
void Node::setAlpha(int _alpha){
    alpha = _alpha;
}
void Node::setBeta(double _beta){
    beta = _beta;
}
void Node::setTimeout(int _timeout){
    timeout_rtt = _timeout;
}
void Node::backoff(){

    cwnd_thresh =  (int)(beta * (double)cwnd) + 1;
    cwnd = 1;
}
void Node::incr(){
    cwnd += alpha;
    if(cwnd >= cwnd_thresh)cwnd_thresh = cwnd;
}
Packet Node::Node::rcv(Packet packet,int rtt){
    if(packet.type == Packet::PSH){
        
        return Packet(Packet::ACK,packet.src,id,packet.seq_number);
    }
    if(packet.type == Packet::ACK && acksAwaiting.find(packet.seq_number) != acksAwaiting.end()){
        
        acksAwaiting.erase(packet.seq_number);
        if(cwnd >= cwnd_thresh)
        {
            if(rtt != last_rtt)
                incr();
        }
        else incr();
        last_rtt = rtt;
        ackCount++;
        
    }
    return Packet(Packet::NONE,-1,-1,-1);
}
vector<Packet> Node::snd(int rtt){
    
    vector<Packet> packetsToSend;
    if(acksAwaiting.size() > 0 && rtt - getOldestNotAcked().second > timeout_rtt){
        last_seq = getOldestNotAcked().first;
        acksAwaiting.clear();
        backoff();
        return packetsToSend;
    }
    for(int i = notAckedCount() ; i < cwnd; i++){
        acksAwaiting[last_seq]=rtt;
        sndCount++;
        packetsToSend.push_back(Packet(Packet::PSH,dst_id,id,last_seq++));
    }
    return packetsToSend;
}
pair<int,int> Node::getOldestNotAcked(){
    return *(acksAwaiting.begin());
}
int Node::notAckedCount(){
    return acksAwaiting.size();
}