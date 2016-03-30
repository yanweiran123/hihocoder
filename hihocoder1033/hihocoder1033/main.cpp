//
//  main.cpp
//  hihocoder1033
//
//  Created by tjuyanweiran on 16/2/3.
//  Copyright © 2016年 tjuyanweiran. All rights reserved.
//

#include <iostream>

using namespace std;


const int M=1000000007;  // outcome will mod M
int bits[21];
long long  base[21];

struct node{

    long sum,num;
    
};

node  dp[21][22][400];  //状态转移 分别是数字长度，最高位首字母大小，以及和
                        //最高位数字同时需要判断前面的符号，例如[0，100]中的  99 09是有区别的

//数位DP  状态转移模板,len表示位数的长短，end_flag表示前一位是否枚举到9，还是枚举到bit[len-2],end_flag为true，则前一位枚举到9
node dfs(int len, int dig ,bool isZero, bool end_flag,int sum){
    
    node t;    //新建一个节点
    t.sum=t.num=0;
    
    /*
     如果位置为0，那么直接返回状态
     */
    if (len<=0||len>=20||dig<0||dig>9||sum<-200||sum>200) {
        return t;
    }
    /*如果长度是1，那么就不需要枚举，直接判断位数为1的数字是否能构成交错和所需要的*/
    if (len==1) {
        if (dig!=sum) {
            return t;
        }else{
            t.num=1;
            t.sum=sum; // 长度只有一位，所以这个节点的和就是sum
            return t;
        }
    }
    
    //如过n=-1,表示该状态已经计算过，直接返回即可
    if (!end_flag&&dp[len][dig+(isZero?0:10)][sum+200].num!=-1) {
        return dp[len][dig+(isZero?0:10)][sum+200];
    }
    
    
    int  end = end_flag?bits[len-2]:9;
    int  newsum  = dig - sum;  //如果首位是正的，次位是负值，那么次位的和必须是 首位减去总和
    node temp;
    for (int j=0;j<end+1; j++) {
        if (isZero){
            temp = dfs(len-1, j, j!=0, end_flag&&(j!=end), sum);
        }else{
            temp = dfs(len-1, j, false, end_flag&&(j!=end), newsum);
        }
        t.num=t.num+temp.num;
        t.sum=(t.sum+temp.sum)%M+((t.num*dig)%M*base[len-1]%M)%M;
    }
    
    if (!end_flag) {
        dp[len][dig+(isZero?0:10)][sum+200]=t;
    }
    
    return t;

}


long long solve(long long n ,int s){
    if (n<0) {
        return 0;
    }
    int l=0;
    for (int i=0; i<21; i++) {
        bits[l++]=n%10;
        n=n/10;
    }
    return dfs(l+1, 0, true, false, s).sum;
    
}


int main(int argc, const char * argv[]) {
    
    
    long long low,high,sum;  //low 代表区间下限，high代表区间上限
    cin>>low>>high>>sum;
    
    node t;
    t.num=-1;
    t.sum=0;
    
    
    for (int i=0; i<21; i++) {
        for (int j=0; j<22; j++) {
            for (int k=0; k<400; k++) {
                dp[i][j][k]=t;
            }
        }
    }
    
    base[0]=1;
    for (int i=0; i<21; i++) {
        base[i] = (base[i-1]*10)%M;
    }

    cout<<(solve(high,sum)-solve(low-1,sum)+M)%M<<endl;
    
    return 0;
}
