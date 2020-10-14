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

int vis[15][15];
int n;
int ans;
int wcnt[15][2];

void dfs(int id,int k){
    if(k==id){
        dfs(id,k+1);
        return;
    }
    if(vis[id][k]){
        dfs(id,k+1);
        return;
    }
    if(k>n){
        if(wcnt[id][0]!=n/2)  return;
        dfs(id+1,1);
        return;
    }
    if(id>n){
        // rep(i,2,n){
        //     if(vis[1][i]==1){
        //         win++;
        //     }
        // }
        // int f=1;
        // rep(i,2,n){
        //     int twin=0;
        //     rep(j,1,n){
        //         if(i==j)  continue;
        //         if(vis[i][j]==1){
        //             twin++;
        //         }
        //     }
        //     if(twin!=win){
        //         f=0;
        //         break;
        //     }
        // }
        ans++;
        return;
    }
    vis[id][k]=1;
    vis[k][id]=-1;
    wcnt[id][0]++;
    wcnt[k][1]++;
    if(!(wcnt[id][0]>n/2||wcnt[k][1]>n/2)){
        dfs(id,k+1);
    }
    wcnt[id][0]--;
    wcnt[k][1]--;
    vis[id][k]=-1;
    vis[k][id]=1;
    wcnt[id][1]++;
    wcnt[k][0]++;
    if(!(wcnt[id][1]>n/2||wcnt[k][0]>n/2)){
        dfs(id,k+1);
    }
    wcnt[id][1]--;
    wcnt[k][0]--;
    vis[id][k]=vis[k][id]=0;
}

int main() {
    while(scanf("%d",&n)&&n){
        int m,x,y;
        scanf("%d",&m);
        mst(vis,0);
        mst(wcnt,0);
        rep(i,1,m){
            scanf("%d%d",&x,&y);
            vis[x][y]=1;
            vis[y][x]=-1;
            wcnt[x][0]++;
            wcnt[y][1]++;
        }
        ans=0;
        dfs(1,1);
        printf("%d\n",ans);
    }
    return 0;
}