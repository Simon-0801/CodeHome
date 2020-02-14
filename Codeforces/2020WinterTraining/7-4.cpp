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
const int maxn = 300000 + 5;

ll t[maxn];

void update(int x,ll num){
    for(;x<maxn;x+=(x&-x))  t[x]+=num;
}
 
ll query(int x){
    ll ans=0;
    for(;x;x-=(x&-x))  ans+=t[x];
    return ans;
}

vector<int> edge[maxn];
vector<PLL> que[maxn];
ll ans[maxn];
int depth[maxn];
int root;

void dfsdep(int now,int fa){
    if(now==root)  depth[now]=1;
    else  depth[now]=depth[fa]+1;
    for(auto &v:edge[now]){
        if(v==fa)  continue;
        dfsdep(v,now);
    }
}

void dfs(int now,int fa){
    for(auto &x:que[now]){
        update(depth[now],x.second);
        update(depth[now]+x.first+1,-x.second);
    }
    ans[now]=query(depth[now]);
    for(auto &v:edge[now]){
        if(v==fa)  continue;
        dfs(v,now);
    }
    for(auto &x:que[now]){
        update(depth[now],-x.second);
        update(depth[now]+x.first+1,x.second);
    }
}

int main() {
    int n,x,y,m,v;
    ll d,num;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d%I64d%I64d",&v,&d,&num);
        que[v].push_back(PLL(d,num));
    }
    root=1;
    dfsdep(1,0);
    mst(t,0);
    dfs(1,0);
    for(int i=1;i<=n;i++){
        printf("%I64d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}