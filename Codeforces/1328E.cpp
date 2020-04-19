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
const int maxn = 200000 + 5;

vector<int> edge[maxn];


int dep[maxn];
int f[maxn][30];
int t;
int q[maxn];

void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    rep(i,1,t) f[x][i]=f[f[x][i-1]][i-1];
    for(auto &nod:edge[x]){
        if(nod==fa)  continue;
        dfs(nod,x);
    }
}

int lca(int x,int y){
    if(dep[x]>dep[y])  swap(x,y);
    repd(i,t,0){
        if(dep[f[y][i]]>=dep[x])  y=f[y][i];
    }
    if(x==y)  return x;
    repd(i,t,0){
        if(f[x][i]!=f[y][i])  x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}

int cmp(int x,int y){
    return dep[x]<dep[y];
}

int main() {
    int n,m,u,v,k;
    scanf("%d%d",&n,&m);
    t=(int)(log(n)/log(2))+1;
    rep(i,1,n-1){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    while(m--){
        scanf("%d",&k);
        rep(i,1,k){
            scanf("%d",q+i);
        }
        sort(q+1,q+k+1,cmp);
        int flag=1;
        rep(i,2,k){
            int lc=lca(q[i-1],q[i]);
            if(!(dep[q[i-1]]-dep[lc]<=1||dep[q[i]]-dep[lc]<=1)){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}