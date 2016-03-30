//
//  main.cpp
//  hihocoder1175
//
//  Created by tjuyanweiran on 16/3/20.
//  Copyright © 2016年 tjuyanweiran. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const int mod=142857;
const int MX=100000+5;
int  A[MX]; //每个节点的病毒数量
int in_degree[MX];//每个节点的入度
vector<int> G[MX];//构造一个图的邻接链表
queue<int> q; //入度为0的队列



int getvirusnum(int N,int M ){
    
    
    int  arrDEL[MX]; //表示已经删除节点
    int  start=1;
    for (int i=1; i<=N; i++) {
        arrDEL[i]=1;
    }
    
    while (!q.empty()) {
        start = q.front();
        q.pop();
        arrDEL[start]=0; //表示这个节点会被删除
        vector<int>::iterator it;
        for(it=G[start].begin();it!=G[start].end();it++){
                A[*it]=(A[*it]+A[start])%mod; //病毒数量叠加
                in_degree[*it]--; //节点入度-1
                if(in_degree[*it]==0)q.push(*it);
        }
        
        
        M--;
    }
    
    int sum=0;
    for (int i=1; i<=N; i++) {
        sum = (sum+A[i])%mod;
    }
    
    return sum;
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //首先根据输入的数字构建邻接链表
    int N,M,K;
    int U,V;
    while (cin>>N>>M>>K) {
        
        while (!q.empty()) //清空队列
        
        //每个节点上的病毒数量初始化为0
        for (int i=1; i<=N; i++) {
            A[i]=0;
        }
        //第K个节点上有1个病毒
        for (int i=1; i<=K; i++) {
            int node;
            cin>>node;
            A[node]=1;
        }
        


        
        //将链表清空
        for(int i=1;i<=N;i++){
            G[i].clear();
            in_degree[i]=0;
        }
        
        while (M) {
            cin>>U>>V;
            G[U].push_back(V);
            in_degree[V]++; //节点V的入度+1
            M--;
        }
        
        //将入度为0的放入队列
        for (int i=1; i<=N; i++) {
            if(in_degree[i]==0)q.push(i);
        }
        
        
        cout<<getvirusnum(N,M);
    }
    
    
    
    
    
    return 0;
}
