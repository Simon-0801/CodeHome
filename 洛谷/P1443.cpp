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
const int maxn = 400 + 5;

struct node
{
    int x,y;
    int step;
};

int n,m,sx,sy;
int mp[maxn][maxn];
int ans[maxn][maxn];
queue<node> q;
int dir[10][2]={{0,0},{-1,-2},{1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1}};

bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m)  return true;
    return false;
}

void bfs(int x,int y){
    node st;
    st.x=x;
    st.y=y;
    st.step=0;
    q.push(st);
    while(!q.empty()){
        node tp=q.front();
        q.pop();
        if(ans[tp.x][tp.y]!=-1)  continue;
        ans[tp.x][tp.y]=tp.step;
        rep(i,1,8){
            int nxtx=tp.x+dir[i][0],nxty=tp.y+dir[i][1];
            if(check(nxtx,nxty)){
                node tmp;
                tmp.x=nxtx;
                tmp.y=nxty;
                tmp.step=tp.step+1;
                q.push(tmp);
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d",&n,&m,&sx,&sy);
    mst(ans,-1);
    bfs(sx,sy);
    rep(i,1,n){
        rep(j,1,m){
            printf("%-5d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}