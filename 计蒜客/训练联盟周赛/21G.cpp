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
const int maxn = 200000 + 5;

ll w[maxn];
VI edge[maxn];
ll sum[maxn],dep[maxn];
ll ans[maxn];

void dfs(int x,int fa,int depth){
    sum[x]=w[x];
    dep[x]=depth;
    for(auto &nod:edge[x]){
        if(nod==fa)  continue;
        dfs(nod,x,depth+1);
        sum[x]+=sum[nod];
    }
}

void dfs1(int x,int fa){
    ans[1]+=dep[x]*w[x];
    for(auto &nod:edge[x]){
        if(nod==fa)  continue;
        dfs1(nod,x);
    }
}

void dfs2(int x,int fa){
    for(auto &nod:edge[x]){
        if(nod==fa)  continue;
        ans[nod]=ans[x]+sum[1]-sum[nod]-sum[nod];
        dfs2(nod,x);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,u,v;
        scanf("%d",&n);
        rep(i,1,n)  edge[i].clear();
        rep(i,1,n){
            scanf("%lld",w+i);
        }
        rep(i,1,n-1){
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1,0,1);
        ans[1]=0;
        dfs1(1,0);
        dfs2(1,0);
        rep(i,1,n){
            printf("%lld ",ans[i]);
        }
        puts("");
    }
    return 0;
}