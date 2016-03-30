//
//  main.cpp
//  hihocoder1094
//
//  Created by tjuyanweiran on 16/2/27.
//  Copyright © 2016年 tjuyanweiran. All rights reserved.
//

#include <iostream>
using namespace std;

char mainChar[200][200];
char supChar[5][5];

char  tempArray[5][5];
char  tempChar;


//将area旋转三次
void rotateArea(char  (*area)[5]){
    
    tempChar = area[0][1];
    for(int i=0;i<3;i++){
        tempArray[0][i]=area[i][0];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            area[i][j]=area[j][2-i];
        }
    }
    
    for(int i=0;i<3;i++){
        area[2][i]=tempArray[0][i];
    }
    area[1][0]=tempChar;
    
}


//开始枚举 判断是否矩阵是否完全相同
bool judge(int column,int row){
    
    for(int i=column-1;i<=column+1;i++){
            for(int j=row-1;j<=row+1;j++){
                if(mainChar[i][j]!=supChar[i-(column-1)][j-(row-1)])
                    return false;
            }
        }
    
    
    
    cout<<column+1<<" "<<row+1<<endl;
    return true;
}

int main(int argc, const char * argv[]) {
    
    int N,M;
    while(scanf("%d %d", &N, &M) != EOF){
        
        for(int i=0; i<N; i++)
            scanf("%s", mainChar[i]);
        
        for(int i=0; i<3; i++)
            scanf("%s", supChar[i]);
        
        for (int i=1; i<=N-2; i++) {
            for (int j=1; j<=M-2; j++) {
                if (mainChar[i][j]==supChar[1][1]) {
                    for(int r=0;r<=3;r++){
                        if(judge(i,j)==true)
                        break;
                        rotateArea(supChar);
                    }
                    
                }
            }
        }
    }
    return 0;
}
