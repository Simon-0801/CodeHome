#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;

char str[maxn];
int nxt[maxn];
int n;

void cal_nxt(){
    nxt[1]=0;
    for(int i=2,j=0;i<=n;i++){
        while(j>0&&str[i]!=str[j+1])  j=nxt[j];
        if(str[i]==str[j+1])  j++;
        nxt[i]=j;
    }
}

int main() {
    scanf("%s",str+1);
    n=strlen(str+1);
    cal_nxt();
    int tmp=nxt[n],ans=0;
    for(int i=2;i<n;i++){
        if(nxt[i]==tmp){
            ans=max(ans,nxt[i]);
        }
    }
    tmp=nxt[nxt[n]];
    for(int i=2;i<n;i++){
        if(nxt[i]==tmp){
            ans=max(ans,nxt[i]);
        }
    }
    // string st=str+1,en=str+1;
    // for(int i=n-tmp+1;i<n;i++){
    //     // string tt=st.substr(0,nxt[i]);
    //     // string ss=en.substr(n-nxt[i],nxt[i]);
    //     if(st.substr(0,nxt[i])==en.substr(n-nxt[i],nxt[i])){
    //         ans=max(ans,nxt[i]);
    //     }
    // }
    if(ans==0){
        printf("Just a legend\n");
        return 0;
    }
    for(int i=1;i<=ans;i++){
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}