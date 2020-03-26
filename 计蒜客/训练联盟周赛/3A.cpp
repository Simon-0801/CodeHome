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

ll a[maxn];
int fa[maxn];
vector<int> edge[maxn];

int len[maxn],son[maxn],top[maxn];

ll l[maxn];

void dfs1(int x){
    son[x]=-1;
    for(auto &nod:edge[x]){
        dfs1(nod);
        if(son[x]==-1||len[son[x]]<len[nod])  son[x]=nod;
    }
    len[x]=len[son[x]]+1;
}

void dfs2(int x,int t){
    top[x]=t;
    if(son[x]==-1)  return;
    dfs2(son[x],t);
    for(auto &nod:edge[x]){
        if(nod!=son[x]){
            dfs2(nod,nod);
        }
    }
}

int main() {
    int n,k,tmp;
    scanf("%d%d",&n,&k);
    rep(i,1,k){
        scanf("%lld",a+i);
    }
    rep(i,2,n){
        scanf("%d",&tmp);
        edge[tmp+1].push_back(i);
        fa[i]=tmp+1;
    }
    dfs1(1);
    dfs2(1,1);
    int cnt=0;
    l[++cnt]=len[1]-1;
    rep(i,2,n){
        if(top[i]==i)  l[++cnt]=len[i];
    }
    sort(l+1,l+cnt+1);
    sort(a+1,a+k+1);
    ll ans=0;
    repd(i,k,1){
        ans+=1ll*l[i]*a[i];
    }
    printf("%lld\n",ans);
    return 0;
}