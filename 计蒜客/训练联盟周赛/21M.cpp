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

struct node
{
    int v,w;
};


vector<node> edge[maxn];
int ans=0;
int sz[maxn];
int n;

void dfs(int x,int fa){
    sz[x]=1;
    for(auto &nod:edge[x]){
        if(nod.v==fa)  continue;
        dfs(nod.v,x);
        sz[x]+=sz[nod.v];
        int f1=(sz[nod.v]&1),f2=((n-sz[nod.v])&1);
        if(f1==1&&f2==1){
            ans^=nod.w;
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int u,v,w;
        scanf("%d",&n);
        rep(i,1,n)  edge[i].clear();
        node tmp;
        rep(i,1,n-1){
            scanf("%d%d%d",&u,&v,&w);
            tmp.w=w;
            tmp.v=v;
            edge[u].push_back(tmp);
            tmp.v=u;
            edge[v].push_back(tmp);
        }
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}