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
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

ll dp[maxn];
vector<int> edge[maxn];
int deg[maxn];
int vis[maxn];
int client[maxn];
ll cnt;
queue<int> q;

void dfs(int x){
    vis[x]=1;
    if(edge[x].size()==0){
        cnt++;
        client[x]=1;
        return;
    }
    for(auto &nod:edge[x]){
        deg[nod]++;
        if(vis[nod])  continue;
        dfs(nod);
    }
}

int main() {
    int n,l,k,v;
    scanf("%d%d",&n,&l);
    rep(i,1,l){
        scanf("%d",&k);
        rep(j,1,k){
            scanf("%d",&v);
            edge[i].push_back(v);
        }
    }
    ll ans=0;
    cnt=0;
    dfs(1);
    dp[1]=1;
    q.push(1);
    while(!q.empty()){
        int tp=q.front();
        q.pop();
        if(client[tp]){
            ans=(ans+dp[tp])%mod;
            continue;
        }
        for(auto &nod:edge[tp]){
            if(!vis[nod])  continue;
            dp[nod]=(dp[nod]+dp[tp])%mod;
            deg[nod]--;
            if(deg[nod]==0)  q.push(nod);
        }
    }
    printf("%lld %lld\n",ans%mod,cnt);
    return 0;
}