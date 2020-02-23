#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 1000000 + 5;

int edge[maxn],num[maxn];
int ans=0,f=0;
int ins[maxn];

int dfs(int now){
    if(num[now])  return num[now];
    if(!ins[now]){
        ins[now]=1;
        num[now]=dfs(edge[now])+1;
        ins[now]=0;
        return num[now];
    }
    else{
        f=now;
        return 0;
    }
}

void findCircle(int x){
    int sz=1,k=edge[x];
    while(k!=x){
        sz++;
        k=edge[k];
    }
    k=edge[x];
    num[x]=sz;
    while(k!=x){
        num[k]=sz;
        k=edge[k];
    }
}

int main() {
    int n;
    scanf("%d",&n);
    mst(ins,0);
    mst(num,0);
    for(int i=1;i<=n;i++){
        scanf("%d",&edge[i]);
    }
    for(int i=1;i<=n;i++){
        if(!num[i])  num[i]=dfs(i);
        if(f){
            findCircle(f);
            f=0;
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,num[i]);
    }
    printf("%d\n",ans);
    return 0;
}