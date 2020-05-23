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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

int t[maxn];

struct node
{
    int v,w;
};

vector<node> edge[maxn];

int sz[maxn],sumt[maxn];
ll sum1[maxn],sum2[maxn];
int n;

void dfs1(int x,int fa){
    sz[x]=1;
    sumt[x]=t[x];
    for(auto &nod:edge[x]){
        if(nod.v==fa)  continue;
        dfs1(nod.v,x);
        sz[x]+=sz[nod.v];
        sumt[x]+=sumt[nod.v];
    }
}

void dfs2(int x,int fa,int dep){
    sum1[1]+=1ll*dep;
    sum2[1]+=1ll*dep*t[x];
    for(auto nod:edge[x]){
        if(nod.v==fa)  continue;
        dfs2(nod.v,x,dep+nod.w);
    }
}

void dfs(int x,int fa){
    for(auto &nod:edge[x]){
        if(nod.v==fa)  continue;
        sum1[nod.v]=sum1[x]+1ll*nod.w*(n-sz[nod.v])-1ll*nod.w*(sz[nod.v]);
        sum2[nod.v]=sum2[x]+1ll*nod.w*(sumt[1]-sumt[nod.v])-1ll*nod.w*sumt[nod.v];
        dfs(nod.v,x);
    }
}


int main() {
    int u,v,w;
    node tmp;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",t+i);
    }
    rep(i,1,n-1){
        scanf("%d%d%d",&u,&v,&w);
        tmp.v=v;
        tmp.w=w;
        edge[u].push_back(tmp);
        tmp.v=u;
        edge[v].push_back(tmp);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    dfs(1,0);
    rep(i,1,n){
        printf("%lld\n",sum1[i]*t[i]+sum2[i]);
    }
    return 0;
}