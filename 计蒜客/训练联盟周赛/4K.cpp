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

struct node
{
    int x,y;
};

node p[15],q[15];
int mp[15][15];
int vis[15];
int n,ans=INF;

void dfs(int cnt,int id){
    if(id==n){
        ans=min(ans,cnt);
        return;
    }
    vis[id]=1;
    rep(i,1,n){
        if(i==id||vis[i])  continue;
        if(mp[id][i])  dfs(cnt+1,i);
    }
    vis[id]=0;
}

int main() {
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    rep(i,1,n){
        scanf("%d%d",&q[i].x,&q[i].y);
    }
    rep(i,1,n){
        rep(j,1,n){
            if(i==j)  continue;
            int tx=p[j].x-p[i].x,ty=p[j].y-p[i].y;
            int flag=1;
            rep(l,1,n){
                int sx=q[l].x-p[i].x,sy=q[l].y-p[i].y;
                if(sx*ty==sy*tx&&(sx*tx+sy*ty>0)&&(tx*tx+ty*ty>sx*sx+sy*sy)){
                    flag=0;
                    break;
                }
            }
            if(flag)  mp[i][j]=1;
            else  mp[i][j]=0;
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            if(i==j)  continue;
            int tx=p[j].x-p[i].x,ty=p[j].y-p[i].y;
            int flag=1;
            rep(l,1,n){
                if(l==i||l==j)  continue;
                int sx=p[l].x-p[i].x,sy=p[l].y-p[i].y;
                if(sx*ty==sy*tx&&(sx*tx+sy*ty>0)&&(tx*tx+ty*ty>sx*sx+sy*sy)){
                    flag=0;
                    break;
                }
            }
            if(mp[i][j]&&!flag)  mp[i][j]=0;
        }
    }
    dfs(0,1);
    if(ans==INF)  printf("-1\n");
    else  printf("%d\n",ans);
    return 0;
}