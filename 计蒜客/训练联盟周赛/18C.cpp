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
const int maxn = 300000 + 5;

VI edge[maxn];

int son[maxn],top[maxn],dfn[maxn],rnk[maxn],dep[maxn],f[maxn];
int cnt=0;

void dfs1(int o,int fa) {
    son[o] = -1;
    dep[o] = 1;
    f[o]=fa;
    int tmp=0;
    for (auto &nod:edge[o]){
        if(nod==fa)  continue;
        dfs1(nod,o);
        // if(son[o]==-1){
        //     tmp=dep[nod];
        //     son[o]=nod;
        // }
        if(tmp<dep[nod]){
            tmp=dep[nod];
            son[o]=nod;
        }
    }
    dep[o]+=tmp;
}

void dfs2(int o, int t) {
  top[o] = t;
  cnt++;
  dfn[o] = cnt;
  rnk[cnt] = o;
  if (son[o] == -1) return;
  dfs2(son[o], t);  // 优先对重儿子进行 DFS，可以保证同一条重链上的点 DFS 序连续
  for (auto &nod:edge[o])
    if (nod != son[o] && nod != f[o]) dfs2(nod, nod);
}

int main() {
    int n,u,v;
    scanf("%d",&n);
    rep(i,1,n-1){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int root=0;
    rep(i,1,n){
        if(edge[i].size()<=1){
            root=i;
            break;
        }
    }
    dfs1(root,0);
    dfs2(root,root);
    int ans=0;
    rep(i,1,n){
        if(top[i]==i){
            ans++;
        }
    }
    printf("%d\n",ans-1);
    return 0;
}