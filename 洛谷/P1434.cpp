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
const int maxn = 100 + 5;

int n,m;
int mp[maxn][maxn],dp[maxn][maxn];
int dir[5][2]={{0,0},{0,-1},{0,1},{1,0},{-1,0}};

bool check(int x,int y){
    if(x<=n&&x>=1&&y<=m&&y>=1)  return true;
    return false;
}

int dfs(int x,int y){
    if(dp[x][y])  return dp[x][y];
    int res=1;
    rep(i,1,4){
        int nxtx=x+dir[i][0],nxty=y+dir[i][1];
        if(check(nxtx,nxty)&&mp[nxtx][nxty]<mp[x][y]){
            res=max(res,dfs(nxtx,nxty)+1);
        }
    }
    return dp[x][y]=res;
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        rep(j,1,m){
            scanf("%d",&mp[i][j]);
        }
    }
    mst(dp,0);
    int ans=-1;
    rep(i,1,n){
        rep(j,1,m){
            ans=max(ans,dfs(i,j));
        }
    }
    printf("%d\n",ans);
    return 0;
}