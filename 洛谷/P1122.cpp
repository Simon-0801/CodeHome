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
const int maxn = 16000 + 5;

int a[maxn];
VI edge[maxn];
int mx[maxn];
int ans=-INF;

// void dfssum(int x,int fa){
//     // if(edge[x].size()==1&&edge[x][0]==fa){
//     //     sum[x]=a[x];
//     //     return;
//     // }
//     sum[x]=a[x];
//     for(int tmp:edge[x]){
//         if(tmp==fa)  continue;
//         dfssum(tmp,x);
//         sum[x]+=sum[tmp];
//     }
// }

void dfs(int x,int fa){
    mx[x]=a[x];
    for(int tmp:edge[x]){
        if(tmp==fa)  continue;
        dfs(tmp,x);
        if(mx[tmp]>0)  mx[x]+=mx[tmp];
    }
    ans=max(ans,mx[x]);
}

int main() {
    int n;scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",a+i);
    }
    int u,v;
    rep(i,1,n-1){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    // dfssum(1,0);
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}