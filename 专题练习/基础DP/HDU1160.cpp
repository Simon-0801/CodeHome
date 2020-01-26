#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

struct mouse
{
    int w;
    int s;
    int index;
}m[maxn];

int cmp(mouse a,mouse b){
    if(a.s==b.s)  return a.w<b.w;
    return a.s>b.s;
}

int dp[maxn],pre[maxn];

void Print(int pos){
    if(pos==-1)  return;
    Print(pre[pos]);
    printf("%d\n",m[pos].index);
}

int main() {
    int wt,sp,cnt=0;
    while(scanf("%d%d",&wt,&sp)!=EOF){
        m[++cnt].w=wt;
        m[cnt].s=sp;
        m[cnt].index=cnt;
    }
    sort(m+1,m+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        dp[i]=1;
        pre[i]=-1;
    }
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<i;j++){
            if(m[j].w<m[i].w&&m[j].s>m[i].s){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
        }
    }
    int tmax=0,p=-1;
    for(int i=1;i<=cnt;i++){
        if(tmax<dp[i]){
            tmax=dp[i];
            p=i;
        }
    }
    printf("%d\n",tmax);
    Print(p);
    return 0;
}