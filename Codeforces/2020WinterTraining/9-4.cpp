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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 500 + 5;

char mp[maxn][maxn];
int vis[maxn][maxn];
int n,m,k;
int dir[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};

bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m)  return true;
    return false;
}

void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=1;i<=4;i++){
        int nxtx=x+dir[i][0],nxty=y+dir[i][1];
        if(check(nxtx,nxty)&&!vis[nxtx][nxty]&&mp[nxtx][nxty]=='.'){
            dfs(nxtx,nxty);
        }
    }
    if(k)  mp[x][y]='X',k--;
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",mp[i]+1);
    }
    mst(vis,0);
    int stx=0,sty=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='.'){
                stx=i;
                sty=j;
                break;
            }
        }
        if(stx)  break;
    }
    dfs(stx,sty);
    for(int i=1;i<=n;i++){
        printf("%s\n",mp[i]+1);
    }
    return 0;
}