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
const int maxn = 1000 + 5;

char mp[maxn][maxn];
int vis[maxn][maxn];
int n;
queue<pair<int,int>> q;
PII que[100005];
int ans[100005];
int dir[5][2]={{0,0},{0,-1},{-1,0},{0,1},{1,0}};

bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=n)  return true;
    return false;
}

int bfs(int id,int x,int y){
    while(!q.empty())  q.pop();
    // mst(vis,0);
    if(vis[x][y])  return vis[x][y];
    int cnt=0;
    q.push(make_pair(x,y));
    while(!q.empty()){
        PII tp=q.front();
        q.pop();
        if(vis[tp.first][tp.second])  continue;
        vis[tp.first][tp.second]=-1*id;
        cnt++;
        rep(i,1,4){
            int nxtx=tp.first+dir[i][0],nxty=tp.second+dir[i][1];
            if(check(nxtx,nxty)){
                if(mp[tp.first][tp.second]=='0'&&mp[nxtx][nxty]=='1'){
                    q.push(make_pair(nxtx,nxty));
                }
                else if(mp[tp.first][tp.second]=='1'&&mp[nxtx][nxty]=='0'){
                    q.push(make_pair(nxtx,nxty));
                }
            }
        }
    }
    return cnt;
}

int main() {
    int m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%s",mp[i]+1);
    }
    int sx,sy;
    rep(cas,1,m){
        scanf("%d%d",&sx,&sy);
        que[cas]=PII(sx,sy);
    }
    mst(ans,0);
    mst(vis,0);
    rep(cas,1,m){
        sx=que[cas].first,sy=que[cas].second;
        int tmp=bfs(cas,sx,sy);
        if(tmp<0)  ans[cas]=ans[-1*tmp];
        else  ans[cas]=tmp;
    }
    rep(i,1,m){
        printf("%d\n",ans[i]);
    }
    return 0;
}