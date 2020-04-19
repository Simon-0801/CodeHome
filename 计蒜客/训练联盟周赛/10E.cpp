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
const int maxn = 100000 + 5;

VI edge[maxn];
int sz[maxn],fa[maxn];
VI leaf;

void dfs(int x,int f){
    sz[x]=1;
    fa[x]=f;
    for(auto &nod:edge[x]){
        if(nod==f)  continue;
        dfs(nod,x);
        sz[x]+=sz[nod];
    }
    if(sz[x]==1){
        leaf.push_back(x);
    }
}

int main() {
    int n;scanf("%d",&n);
    int u,v;
    rep(i,1,n-1){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    int f=1;
    for(auto &x:leaf){
        if(sz[fa[x]]!=2){
            f=0;
            break;
        }
    }
    if(!f)  printf("Alice\n");
    else  printf("Bob\n");
    return 0;
}