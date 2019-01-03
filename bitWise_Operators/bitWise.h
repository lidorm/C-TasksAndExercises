//
//  bitWise.h
//  bitWise_Operators
//
//  Created by Lidor Mashiah on 05/11/2018.
//  Copyright © 2018 Lidor Mashiah. All rights reserved.
//

#ifndef bitWise_h
#define bitWise_h
#include <iostream>

using namespace std;

class CoffeMachine{
    
public:
    static const int coffee=2;
    static const int milk=4;
    static const int sugar = 8;
    static const int tee = 16;
    
    
    void getOptions(int mode){
        switch(mode){
            case coffee:
                cout<<"coffee"<<endl;
                break;
            case coffee | milk:
                cout<<"coffee and milk"<<endl;
                break;
            case coffee|milk|sugar:
                cout<<"coffee with milk and sugar"<<endl;
                break;
            case tee:
                cout<<"tee"<<endl;
                break;
            case tee|sugar:
                cout<<"tee with sugar"<<endl;
                break;
                
                
        }
    }
    
    
    
    
};










#endif /* bitWise_h */
