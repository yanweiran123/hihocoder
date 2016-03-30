//
//  main.cpp
//  hihocoder1039
//
//  Created by tjuyanweiran on 16/2/12.
//  Copyright © 2016年 tjuyanweiran. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int del(string s){
    s.insert(0, "$");
    s=s+"#";
    string childStr;
    int score = 0;
    bool isCon=false;
    size_t lenth= s.length();
    bool hasCon=false;
    for(size_t i=1;i<lenth-1;i++){
        if (s[i-1]==s[i]) {
            score++;
            hasCon=true;
            if (isCon==false) {
                score++;
            }
            isCon=true;
        }
        
        if (s[i]!=s[i-1]) {
            isCon=false;
        }
        if (s[i]!=s[i-1]&&s[i]!=s[i+1]) {
            childStr=childStr+s[i];
        }
    }
    
    
    
    
    
    if(hasCon==true){
        score=score+del(childStr);
    }
    
    return score;
}





int main(int argc, const char * argv[]) {
    // insert code here...
    
    int k;
    cin>>k;
    while (k) {
        string myStr;
        cin>>myStr;
        string ch="ABC";
        int max = 0;
        int length = myStr.length()+1;
        string temp = myStr;
        for (int i=0; i<length; i++) {
            temp = myStr; //每次初始化，因为每次都是重新插入原始数据的
            for (int j=0; j<3; j++) {
                temp=myStr;
                temp.insert(temp.begin()+i, ch[j]);
                if(del(temp)>max) max = del(temp);
            }
        }
        
        cout<<max<<endl;
        k--;
    }
    
    
    
    return 0;
}
