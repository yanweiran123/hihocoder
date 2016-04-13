#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct TrieNode{
    int count;
    struct TrieNode * next[26];
    bool isWord;
    
};

TrieNode * createTrieNode(){
    TrieNode * node = (TrieNode*)malloc(sizeof(TrieNode));
    node->count=0;
    node->isWord = false; //假设不能构成单词
    memset(node->next, 0 , sizeof(node->next));//初始化为空指针
    return node;
}

int main(int argc, char *argv[])
{
    int numOfWord,numOfPre;
    cin>>numOfWord;
    string word,pre;
    TrieNode * node=createTrieNode(); //构建树的节点
    TrieNode * head;
    head = node;
    /*这段函数是输入第一批值，构建字典树*/
    while(numOfWord>0){
        cin>>word;
        int len=word.length();
        for(int i=0;i<len;i++){
            if(node->next[word[i]-'a']==NULL){
                node->next[word[i]-'a']=createTrieNode();
            }
            node = node->next[word[i]-'a'];
            node->count+=1;
        }
        node->isWord = true;
        node=head;
        numOfWord--;
    }
    
    /* 这段函数是输入第一批值，构建字典树*/
    
    /*这段函数是接受第二批输入,根据前缀进行查找*/
    cin>>numOfPre;
    while(numOfPre>0){
        cin>>pre;
        int len = pre.length();
        int i;
        for(i=0;i<len;i++){
            if(node->next[pre[i]-'a']==NULL){
                break;
            }
            node = node->next[pre[i]-'a'];
            //cout<<node->count<<endl;
        }
        if(len>i){
            cout<<0<<endl;
        }else{
            cout<<node->count<<endl;
        }
        
        node=head;
        numOfPre--;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
