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
const int maxn = 100 + 5;

struct node
{
    int v,w;
};

vector<node> edge[maxn];
int dp[maxn][maxn];
int sz[maxn];

void dfssz(int x,int fa){
    sz[x]=0;
    for(auto &nod:edge[x]){
        if(nod.v==fa)  continue;
        dfssz(nod.v,x);
        sz[x]+=1+sz[nod.v];
    }
}

void dfs(int x,int fa){
    dp[x][0]=0;
    for(auto &nod:edge[x]){
        if(nod.v==fa)  continue;
        dfs(nod.v,x);
        repd(i,sz[x],1){
            rep(j,0,sz[nod.v]){
                if(i-j>=1){
                    dp[x][i]=max(dp[x][i],dp[nod.v][j]+dp[x][i-1-j]+nod.w);
                }
            }
        }
    }
}

int main() {
    int n,q;
    int u,v,w;
    scanf("%d%d",&n,&q);
    node tmp;
    rep(i,1,n-1){
        scanf("%d%d%d",&u,&v,&w);
        tmp.w=w;
        tmp.v=v;
        edge[u].push_back(tmp);
        tmp.v=u;
        edge[v].push_back(tmp);
    }
    dfssz(1,0);
    dfs(1,0);
    printf("%d\n",dp[1][q]);
    return 0;
}