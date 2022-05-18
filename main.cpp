#include "h/core.h"
#include <iostream>
int main(){
    char z;
    Core core(4,1000,100);
    core.printInfo();
    cin >> z;
    for(int i = 0 ; i < 100; i ++ ){
        core.step();
        core.printInfo();
        getc(stdin);
    }
}