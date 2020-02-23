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

int n,m,t;
int sx,sy,ex,ey;
int mp[10][10],vis[10][10];
int cnt=0;
int dir[10][2]={{0,0},{-1,0},{0,-1},{0,1},{1,0}};

bool check(int x,int y){
    if(!(x<=n&&x>=1&&y<=m&&y>=1))  return false;
    if(mp[x][y])  return false;
    return true;
}

void dfs(int x,int y){
    if(x==ex&&y==ey){
        cnt++;
        return;
    }
    rep(i,1,4){
        int tmpx=x+dir[i][0],tmpy=y+dir[i][1];
        if(vis[tmpx][tmpy]||!check(tmpx,tmpy))  continue;
        vis[tmpx][tmpy]=1;
        dfs(tmpx,tmpy);
        vis[tmpx][tmpy]=0;
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    int x,y;
    mst(mp,0);
    mst(vis,0);
    while(t--){
        scanf("%d%d",&x,&y);
        mp[x][y]=1;
    }
    vis[sx][sy]=1;
    dfs(sx,sy);
    printf("%d\n",cnt);
    return 0;
}