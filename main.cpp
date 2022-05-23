#include "h/core.h"
#include <iostream>

void readInput(int &nodesNumber,int &queueSize, int &speed,
    int &alpha, double &beta, int& timeout){
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

}

int main(){
    double beta;
    int nodesNumber,queueSize,speed,alpha,timeout;
    nodesNumber = 10;
    queueSize = 10000;
    speed = 1000;
    alpha = 1;
    beta = 0.5;
    timeout = 3;
    
    char z;
    cout << "read custom config? y/n: " << endl;
    cin >> z;
    if(z == 'y')readInput(nodesNumber,queueSize,speed,
        alpha,beta,timeout);

    Core core(nodesNumber,queueSize,speed);
    core.setAlpha(alpha);
    core.setBeta(beta);
    core.setTimeout(timeout);
    int print_ctr=0;
    for(;;){
        core.step();
        if(print_ctr++%20 == 0){
            core.printInfo();
            cout << "\x1b["<< core.nodes.size() + 2<<"A";

        }
    }
    core.printInfo();
}