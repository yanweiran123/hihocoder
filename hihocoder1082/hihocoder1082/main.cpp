//
//  main.cpp
//  hihocoder1082
//
//  Created by tjuyanweiran on 16/2/23.
//  Copyright © 2016年 tjuyanweiran. All rights reserved.
//

#include <iostream>
#include <string.h> 

using  namespace std;


const char patterStr[] = {"marshtomp"};
char replaceStr[]={"fjxmlhx"};



bool isEqual(char originStr[],int i){
    
    for (int j=0;j<strlen(patterStr); j++) {
        if (!(patterStr[j]==originStr[i]||(patterStr[j]==(originStr[i]+32)))) {
            return false;
        }
        i++;
    }
    return true;
    
}


int main(int argc, const char * argv[]) {
    char origStr[200];
    while (cin.getline(origStr,200)) {
        for(int i=0;i<strlen(origStr);i++){
            //计算是否匹配
            if (origStr[i]!='m'&&origStr[i]!='M') {
                cout<<origStr[i];
            }else if(isEqual(origStr,i)){
                    cout<<replaceStr;
                    i +=8;
            }else{
                cout<<origStr[i];
            }
            
        }
        cout<<endl;
    }
    return 0;
}
