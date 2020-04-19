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

vector<int> edge[maxn];
int sz[maxn];
int ans=0;

void dfs(int x,int fa){
    sz[x]=1;
    for(auto &nod:edge[x]){
        if(nod==fa)  continue;
        dfs(nod,x);
        sz[x]+=sz[nod];
        if(sz[nod]%2==0)  ans++;
    }
    
}

int main() {
    int n,u,v;
    scanf("%d",&n);
    rep(i,1,n-1){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    if(n&1){
        printf("-1\n");
        return 0;
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}