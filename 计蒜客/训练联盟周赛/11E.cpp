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
const int maxn = 500000 + 5;

int c[maxn];
VI edge[maxn];
double dp[maxn];

void dfs(int x){
    if(dp[x])  return;
    dp[x]=c[x];
    for(auto &nod:edge[x]){
        dfs(nod);
        dp[x]=max(dp[x],max(dp[nod],dp[nod]*0.5+c[x]));
    }
}

int main() {
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%d",c+i);
    }
    rep(i,1,m){
        scanf("%d%d",&u,&v);
        edge[u+1].push_back(v+1);
    }
    dfs(1);
    printf("%.10lf\n",dp[1]);
    return 0;
}