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
const int maxn = 20 + 5;

int dis[maxn][maxn],vis[maxn][maxn];
int dir[10][2]={0,0,-2,-1,-2,1,2,-1,2,1,-1,-2,1,-2,-1,2,1,2};
queue<PII> q;
int enx,eny,n;

bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=n)  return true;
    return false;
}

int bfs(int stx,int sty){
    PII st(stx,sty);
    while(!q.empty())  q.pop();
    q.push(st);
    // mst(dis,0);
    mst(vis,0);
    dis[stx][sty]=0;
    vis[stx][sty]=1;
    while(!q.empty()){
        PII tp=q.front();
        q.pop();
        if(tp.first==enx&&tp.second==eny){
            return dis[tp.first][tp.second];
        }
        rep(i,1,8){
            int x=tp.first+dir[i][0],y=tp.second+dir[i][1];
            if(check(x,y)&&vis[x][y]==0){
                dis[x][y]=dis[tp.first][tp.second]+1;
                vis[x][y]=1;
                q.push(PII(x,y));
            }
        }
    }
}

int main() {
    int t,stx,sty;
    scanf("%d",&t);
    rep(cas,1,t){
        scanf("%d%d%d%d%d",&n,&stx,&sty,&enx,&eny);
        int ans=bfs(stx,sty);
        printf("Case #%d: %d\n\n",cas,ans);
    }
    return 0;
}