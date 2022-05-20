#include "../h/packet.h"
#include <iostream>
using namespace std;
Packet::Packet(Type _type,int _dst,int _src,int _seq_number){
    dst = _dst;
    src = _src;
    type = _type;
    seq_number = _seq_number;
}
Packet::Packet(){
    
}
void Packet::print(){
    cout << src << "->" << dst << " seq:" << seq_number << endl;
}