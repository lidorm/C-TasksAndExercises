

#include <iostream>
#include "bitWise.h"


int main(int argc, const char * argv[]) {

    CoffeMachine c;

    int mode=CoffeMachine::coffee;
    int mode2=CoffeMachine::coffee|CoffeMachine::milk;
    int mode3=CoffeMachine::tee;
    c.getOptions(mode);
    c.getOptions(mode2);
    c.getOptions(mode3);
    

    
    
    
    
    return 0;
}
