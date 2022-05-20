#include "h/core.h"
#include <iostream>
int main(){
    double beta;
    int nodesNumber,queueSize,speed,alpha,timeout;
    cout << "insert nodes number:" << endl;
    cin >> nodesNumber;
    cout << "insert max packets in core:" << endl;
    cin >> queueSize;
    cout << "insert how many packets can core handle in one time unit: " << endl;
    cin >> speed;
    cout << "insert alpha parameter:" << endl;
    cin >> alpha;
    cout << "insert beta parameter:" << endl;
    cin >> beta;
    cout << "insert number of units node can wait for ACK:" << endl;
    cin >> timeout;

    

    Core core(nodesNumber,queueSize,speed);
    core.setAlpha(alpha);
    core.setBeta(beta);
    core.setTimeout(timeout);
    for(int i = 0 ; i < 1000; i ++ ){
        core.step();
    }
    core.printInfo();
}