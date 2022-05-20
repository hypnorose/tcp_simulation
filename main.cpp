#include "h/core.h"
#include <iostream>
int main(){
    char z;
    Core core(40,1000,500);
    core.setBeta(0.7);
    for(int i = 0 ; i < 1000; i ++ ){
        core.step();
    }
    core.printInfo();
}