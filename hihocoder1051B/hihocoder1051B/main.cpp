//
//  main.cpp
//  hihocoder1051
//
//  Created by tjuyanweiran on 16/2/21.
//  Copyright © 2016年 tjuyanweiran. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


int getContinueDay(int array[],int start,int end){
    int continueDay=0;
    int behind=0;
    int after=0;
    //计算起始补卡的起始天数之前的连续天数
    for(int i=end-1; i>=1; i--) {
        if (0==array[i]) {
            break;
        }
        behind++;
    }
    //计算起始补卡的终结天数之后的连续天数
    
    for (int j=end+1; j<100; j++) {
        if (0==array[j]) {
            break;
        }
        after++;
    }
    continueDay = after+behind+1;
    return continueDay;
    
}

int maxContinues(int dayArray[],int numOfcard,int numOfabsent,vector<int> abVec){
    int maxContDay=0;
    int temArray[100];
    int numOfCompare=numOfabsent-numOfcard+1; //计算出需要遍历的次数
    for(int i=0;i<=numOfCompare;i++)
    {
        memcpy(temArray,dayArray,100*sizeof(int));
        for(int j=0;j<numOfcard;j++){
            temArray[abVec[j+i]]=1;
        }
        if (maxContDay<getContinueDay(temArray, abVec[i], abVec[i+numOfcard-1])) {
            maxContDay=getContinueDay(temArray, abVec[i], abVec[i+numOfcard-1]);
        }
    }
    
    return maxContDay;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int numOfTest;//测试案例
    int N,M;//N代表N天没有刷题，M代表有M张补卡
    int day;
    cin>>numOfTest;
    while (numOfTest){
        cin>>N>>M;
        int dayArray[100];
        vector<int> abVec;
        for (int i=0; i<=100; i++) {
            dayArray[i]=1;
        }
        
        int tempN=N;
        while (tempN) {
            cin>>day;
            dayArray[day]=0;
            abVec.push_back(day);
            tempN--;
        }
        /*求出最大的连续天数*/
        if(M>=N) {
            cout<<100<<endl;
        }//如果补卡数目大于天数，则直接输出100
        else{
            cout<<maxContinues(dayArray,M,N,abVec)<<endl;
        }
        numOfTest--;
    }
    
    
    
    return 0;
}
