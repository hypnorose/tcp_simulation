#include "h/core.h"
#include <iostream>
int main(){
    char z;
    Core core(10,1000,500);
    core.nodes[0].beta = 0.99;
    for(int i = 0 ; i < 1000; i ++ ){
        core.step();
    }
    core.printInfo();
}