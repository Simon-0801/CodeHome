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
const int maxn = 200000 + 5;

ll a[maxn],sum[maxn];
vector<int> edge[maxn];
ll ans;

void dfs(int x,int fa,int depth){
    sum[x]=a[x];
    ans+=depth*a[x];
    for(auto node:edge[x]){
        if(node==fa)  continue;
        dfs(node,x,depth+1);
        sum[x]+=sum[node];
    }
}

void solve(int x,int fa,ll tans){
    ans=max(ans,tans);
    for(auto node:edge[x]){
        if(node==fa)  continue;
        solve(node,x,tans+sum[1]-sum[node]-sum[node]);
    }
}

int main() {
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    ans=0;
    dfs(1,0,0);
    solve(1,0,ans);
    printf("%I64d\n",ans);
    return 0;
}