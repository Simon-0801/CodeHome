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
const int maxn = 100000 + 5;

ll x[maxn];
vector<int> edge[maxn];
map<ll,int> mp[maxn];
ll ans=0;

void dfs(int now,int fa){
    if(fa){
        for(auto &a:mp[fa]){
            ll tmp=__gcd(a.first,x[now]);
            mp[now][tmp]+=a.second;
        }
    }
    mp[now][x[now]]++;
    for(auto &a:mp[now]){
        ans+=(a.first*a.second)%mod;
        ans%=mod;
    }
    int sz=edge[now].size();
    for(int i=0;i<sz;i++){
        if(edge[now][i]==fa)  continue;
        dfs(edge[now][i],now);
    }
}

int main() {
    ans=0;
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&x[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    printf("%I64d\n",ans);
    return 0;
}