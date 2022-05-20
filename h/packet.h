#pragma once
struct Packet{
    enum Type{
        PSH,ACK,NONE
    };
    Type type;
    int dst;
    int src; 
    int seq_number;
    Packet();
    Packet(Type _type,int _dst,int _src,int _seq_number);
    void print();
};