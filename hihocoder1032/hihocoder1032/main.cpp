//
//  main.cpp
//  hihocoder1032
//
//  Created by tjuyanweiran on 16/4/13.
//  Copyright © 2016年 tjuyanweiran. All rights reserved.
//

#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

const int MX = 1e6 + 5;

char s[MX * 2];//记得要开两倍
int p[MX * 2];

int manacher(char *s){
    int len = strlen(s), id = 0, ans = 0;
    for(int i = len; i >= 0; i--) {
        s[i + i + 2] = s[i];
        s[i + i + 1] = '#';
    }
    s[0] = '*';//防越界,很重要!!
    for(int i = 2; i < 2 * len + 1; ++i) {
        if(p[id] + id > i) p[i] = min(p[2 * id - i], p[id] + id - i);
        else p[i] = 1;
        while(s[i - p[i]] == s[i + p[i]]) p[i]++;
        if(id + p[id] < i + p[i]) id = i;
        ans = max(ans, p[i] - 1);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        printf("%d\n", manacher(s));
    }
    return 0;
}
