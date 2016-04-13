#include <cstdlib>
#include <iostream>

using namespace std;

void getNext(string pattern,int * next){
    int length = pattern.length();
    next[0]=-1; //初始K设为-1
    int k=-1;
    int j=0;
    while(j<=length){
        if(k==-1||pattern[j]==pattern[k]){
            next[++j]=++k;
        }else{
            k = next[k];
        }
    }
}

int main(int argc, char *argv[])
{
    string text;
    string myPattern;
    int pairOfStr;
    int next[10000];
    cin>>pairOfStr;
    while(pairOfStr>0){
        cin>>myPattern;
        cin>>text;
        if(myPattern.length()>text.length())return 0;
        getNext(myPattern,next);//生成next数组
        int count=0;
        int i=0,j=0,q=0;
        while(i<text.length()){
            if(j==-1||myPattern[j]==text[i]){
                i++;
                j++;
            }else{
                j=next[j];
            }
            
            if(j==myPattern.length()){
                count++;
                j=next[j];
            }
        }
        
        cout<<count<<endl;
        pairOfStr--;
    }
    
    return EXIT_SUCCESS;
}
